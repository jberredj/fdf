/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 21:58:53 by jberredj          #+#    #+#             */
/*   Updated: 2021/08/16 11:51:59 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs/t_3dobj.h"
#include "structs/t_vec.h"
#include "structs/t_window.h"
#include "color_utils.h"
#include "mlx.h"
#include "window.h"
#include "geometry.h"
#include "objects.h"

void	project_mesh(t_3dobj *obj, t_vec2d cam, double zoom, double amplitude)
{
	t_vec3d	point;
	int		i;

	i = -1;
	while (++i < obj->nbr_vert)
	{
		point = obj->vertices[i].coord;
		point.z *= amplitude;
		point = vec3d_rot_y(point, obj->orient.y);
		point = vec3d_rot_x(point, obj->orient.x);
		point = vec3d_rot_z(point, obj->orient.z);
		point.y -= cam.y;
		point.x -= cam.x;
		obj->vertices[i].projected = ortho_projection(point, zoom);
	}
}

void	print_command(void *mlx, void *win)
{
	mlx_string_put(mlx, win, 10, 10, WHITE, "Commands :");
	mlx_string_put(mlx, win, 10, 30, WHITE, "WASD : Move mesh");
	mlx_string_put(mlx, win, 10, 50, WHITE,
		"Arrows - Num 1/Num 9 : Rotate mesh");
	mlx_string_put(mlx, win, 10, 70, WHITE, "+/- : Amplitude");
	mlx_string_put(mlx, win, 10, 90, WHITE, "Num +/Num - : Zoom");
	mlx_string_put(mlx, win, 10, 110, WHITE, "R : Reset mesh rotation");
	mlx_string_put(mlx, win, 10, 130, WHITE,
		"C : Reset mesh size and position");
}

void	rotate_mesh(t_3dobj *obj, t_key flags)
{
	obj->orient.x = normalizeAngle(obj->orient.x + (double)flags.rotx * 0.01);
	obj->orient.y = normalizeAngle(obj->orient.y + (double)flags.roty * 0.01);
	obj->orient.z = normalizeAngle(obj->orient.z + (double)flags.rotz * 0.01);
	if (flags.reset_cam)
		obj->orient = vec3d(0.523599, 0.523599, 0.9);
}

void	move_mesh(t_window *win, t_key flags)
{
	win->camera.x -= (double)flags.movex * 10 * (1 / win->zoom);
	win->camera.y -= (double)flags.movey * 10 * (1 / win->zoom);
	win->zoom += (double)flags.zoom * 0.3;
	if (win->zoom <= 0.0)
		win->zoom = 0.01;
	win->amplitude += (double)flags.amplitude * 0.01;
	if (flags.reset_pos)
	{
		win->camera = vec2d(0.0, 0.0);
		win->zoom = 32;
		win->amplitude = 1;
	}
}

int	loop(t_window *win)
{
	int		i;

	rotate_mesh(win->objs, win->flags);
	move_mesh(win, win->flags);
	project_mesh(win->objs, win->camera, win->zoom, win->amplitude);
	i = -1;
	while (++i < win->objs->nbr_faces)
		put_face_edge(i, *win->objs, win);
	push_back_fb(win->mlx, win->win, &win->fb, 0x3c3c3c);
	print_command(win->mlx, win->win);
	return (0);
}
