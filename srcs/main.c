/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:43:38 by jberredj          #+#    #+#             */
/*   Updated: 2021/07/16 17:07:20 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**TO REMOVE
*/
#include <stdio.h>
/*
**TO REMOVE
*/
#include <stdlib.h>
#include <math.h>
#include "structs/t_window.h"
#include "structs/t_vec.h"
#include "mlx.h"
#include "geometry.h"
#include "objects.h"
#include "color_utils.h"
#include "window.h"
#include "parsers.h"

void	project_mesh(t_3dobj *obj, t_vec2d cam, double zoom, double amplitude)
{
	t_vec3d	point;
	int		i;

	i = -1;
	while (++i < obj->nbr_vertices)
	{
		point = obj->vertices[i].coord;
		point.z *= amplitude;
		point = vec3d_rot_y(point, obj->orient.y);
		point = vec3d_rot_x(point, obj->orient.x);
		point = vec3d_rot_z(point, obj->orient.z);
		point.y -= cam.y;
		point.x -= cam.x;
		obj->vertices[i].projected = ortho_projection(point, zoom, amplitude);
	}
}

void	print_command(void *mlx, void *win)
{
	mlx_string_put(mlx, win, 10, 10, WHITE, "Commands :");
	mlx_string_put(mlx, win, 10, 30, WHITE, "WASD : Move mesh");
	mlx_string_put(mlx, win, 10, 50, WHITE, "Arrows - Num 1/Num 9 : Rotate mesh");
	mlx_string_put(mlx, win, 10, 70, WHITE, "+/- : Amplitude");
	mlx_string_put(mlx, win, 10, 90, WHITE, "Num +/Num - : Zoom");
	mlx_string_put(mlx, win, 10, 110, WHITE, "R : Reset mesh rotation");
	mlx_string_put(mlx, win, 10, 130, WHITE, "C : Reset mesh size and position");
}

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

double normalizeAngle(double angle)
{
	angle = fmod(angle, (2 * M_PI));
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	return (angle);
}

void rotate_mesh(t_3dobj *obj, t_key flags)
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
	t_vec2d	projected;
	
	rotate_mesh(win->objs, win->flags);
	move_mesh(win, win->flags);
	project_mesh(win->objs, win->camera, win->zoom, win->amplitude);
	i = -1;
	while (++i < win->objs->nbr_faces)
		put_face_edge(i, *win->objs, WHITE, win);
	push_back_fb(win->mlx, win->win, &win->fb, 0x181818);
	print_command(win->mlx, win->win);
	return (0);
}

t_3dobj *create_simple_ls(void)
{
	t_3dobj	*ls;

	ls = (t_3dobj *)malloc(sizeof(t_3dobj));
	ls->nbr_faces = 9;
	ls->nbr_vertices = 4 * 4;
	ls->vertices = (t_vertex *)malloc(sizeof(t_vertex) * 4 * 4);
	ls->faces = (t_face *)malloc(sizeof(t_face) * 9);

	ls->vertices[0].coord = vec3d(-1.5, -1.5, -5);
	ls->vertices[1].coord = vec3d(-0.5, -1.5, 0);
	ls->vertices[2].coord = vec3d(0.5, -1.5, 0);
	ls->vertices[3].coord = vec3d(1.5, -1.5, 0);
	ls->vertices[4].coord = vec3d(-1.5, -0.5, 0);
	ls->vertices[5].coord = vec3d(-0.5, -0.5, 3);
	ls->vertices[6].coord = vec3d(0.5, -0.5, -1);
	ls->vertices[7].coord = vec3d(1.5, -0.5, 0);
	ls->vertices[8].coord = vec3d(-1.5, 0.5, 0);
	ls->vertices[9].coord = vec3d(-0.5, 0.5, 8);
	ls->vertices[10].coord = vec3d(0.5, 0.5, 10);
	ls->vertices[11].coord = vec3d(1.5, 0.5, 0);
	ls->vertices[12].coord = vec3d(-1.5, 1.5, 0);
	ls->vertices[13].coord = vec3d(-0.5, 1.5, 0);
	ls->vertices[14].coord = vec3d(0.5, 1.5, 0);
	ls->vertices[15].coord = vec3d(1.5, 1.5, 0);

	for(int i; i < 9; i++)
	{
		ls->faces[i].nbr_edges = 4;
		ls->faces[i].edges = (t_edge *)malloc(sizeof(t_edge) * 4);
	}
	set_quad_face(quad(0, 1, 5, 4), &ls->faces[0]);
	set_quad_face(quad(1, 2, 6, 5), &ls->faces[1]);
	set_quad_face(quad(2, 3, 7, 6), &ls->faces[2]);
	set_quad_face(quad(4, 5, 9, 8), &ls->faces[3]);
	set_quad_face(quad(5, 6, 10, 9), &ls->faces[4]);
	set_quad_face(quad(6, 7, 11, 10), &ls->faces[5]);
	set_quad_face(quad(8, 9, 13, 12), &ls->faces[6]);
	set_quad_face(quad(9, 10, 14, 13), &ls->faces[7]);
	set_quad_face(quad(10, 11, 15, 14), &ls->faces[8]);

	ls->orient.x = -0.5;
	ls->orient.y = -2.7;
	ls->orient.z = -0.9;
	return (ls);
}

#ifndef WIDTH
# define WIDTH 800
#endif
#ifndef HEIGHT
# define HEIGHT 600
#endif

int	main(int argc, char **argv)
{
	t_window	win;
	int			fd;

	init_win_struct(&win, WIDTH, HEIGHT, "fdf");
	fd = args_parser(argc, argv, &win);
	fdf_parser(fd, &win);
	//win.objs = create_simple_ls();
	create_win(&win);
	mlx_loop(win.mlx);
	free_exit(&win);
	return (0);
}
