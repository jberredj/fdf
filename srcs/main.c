/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:43:38 by jberredj          #+#    #+#             */
/*   Updated: 2021/07/09 17:32:34 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <X11/X.h>
#include "structs/t_window.h"
#include "../libs/libft/includes/libft.h"
#include "mlx.h"
#include "mlx_utils.h"
#include "window.h"
#include "geometry.h"
#include "qwerty.h"
#include "color_utils.h"
#include "arwing.h"
#include "objects.h"
#define	FOV_FAC	32

t_vec3d camera_pos = {0, 0, -25};

t_vec2d	ortho_projection(t_vec3d point)
{
	return ((t_vec2d){.x = point.x * FOV_FAC, .y = point.y * FOV_FAC});
}

t_vec2d perspec_projection(t_vec3d point)
{
	return ((t_vec2d){.x = point.x * 640 / point.z, .y = point.y * 640 / point.z});
}

void	img_clear(t_img *img, uint32_t color)
{
	int	x;
	int	y;

	x = -1;
	while (++x < img->width)
	{
		y = -1;
		while (++y < img->height)
			img_pixel_put(img, x, y, color);
	}
}

void	push_back_fb(void *mlx, void *win, t_fb	*fb, uint32_t clear_color)
{
	t_img	*tmp;
	
	tmp = fb->front;
	fb->front = fb->back;
	fb->back = tmp;
	mlx_put_image_to_window(mlx, win, fb->front->ptr, 0, 0);
	img_clear(fb->back, clear_color);
}

void	put_model_line(t_edge edge, t_vertex *vertices, uint32_t color, t_window *win)
{
	t_vec2i	p0;
	t_vec2i	p1;
	p0 = vec2d_to_i(vertices[edge.a].projected);
	p1 = vec2d_to_i(vertices[edge.b].projected);
	p0.x += win->width / 2;
	p0.y += win->height / 2;
	p1.x += win->width / 2;
	p1.y += win->height / 2;
	draw_line_bh(p0, p1, win->fb.back, color);
}

void	put_face_edge(int face_index, t_3dobj obj, uint32_t color, t_window *win)
{
	int	i;
	int	nbr_edges;

	nbr_edges = obj.faces[face_index].nbr_edges;
	i = -1;
	while (++i < nbr_edges)
		put_model_line(obj.faces[face_index].edges[i], obj.vertices, color, win); 
}



int	loop(t_window *win)
{
	int		i;
	t_vec3d	point;
	t_vec2d	projected;

	i = -1;
	while (++i < win->objs->nbr_vertices)
	{
		point = win->objs->vertices[i].coord;
		point = vec3d_rot_y(point, win->rot_y);
		point = vec3d_rot_x(point, win->rot_x);
		point = vec3d_rot_z(point, win->rot_z);
		point.z -= camera_pos.z;
		point.y -= camera_pos.y;
		point.x -= camera_pos.x;
		win->objs->vertices[i].projected = ortho_projection(point);/*perspec_projection(point);*/
	}
	i = -1;
	while(++i < win->objs->nbr_vertices)
	{
		projected = win->objs->vertices[i].projected;
		img_pixel_put(win->fb.back, projected.x + win->width / 2, projected.y + win->height / 2, WHITE);
	}
	i = -1;
	while(++i < win->objs->nbr_faces)
		put_face_edge(i, *win->objs, WHITE, win);
	
	push_back_fb(win->mlx, win->win, &win->fb, BLACK);
	return (0);
}

int	key_pressed(int keycode, t_window *win)
{
	if (keycode == KEY_LEFT)
		win->rot_y -= 0.1;
	if (keycode == KEY_RIGHT)
		win->rot_y += 0.1;
	if (keycode == KEY_UP)
		win->rot_x -= 0.1;
	if (keycode == KEY_DOWN)
		win->rot_x += 0.1;
	if (keycode == KEY_NUM_9)
		win->rot_z += 0.1;
	if (keycode == KEY_NUM_1)
		win->rot_z -= 0.1;
	if (keycode == KEY_A)
		camera_pos.x++;
	if (keycode == KEY_D)
		camera_pos.x--;
	if (keycode == KEY_W)
		camera_pos.y++;
	if (keycode == KEY_S)
		camera_pos.y--;
	if (keycode == KEY_NUM_PLUS)
		camera_pos.z++;
	if (keycode == KEY_NUM_MINUS)
		camera_pos.z--;
	return (0);
}

int	key_released(int keycode, t_window *win)
{
	return (0);
}


int	main(int argc, char **argv)
{
	t_window	win;
	init_win_struct(&win, "fdf");
	win.width = 800;
	win.height = 600;
	win.fb.front = new_image(win.mlx, 800, 600);
	win.fb.back = new_image(win.mlx, 800, 600);
	win.rot_x = 0;
	win.rot_y = 0;
	win.rot_z = 0;
	win.objs = create_arwing();
	create_win(&win);
	mlx_hook(win.win, KeyPress, KeyPressMask, key_pressed, &win);
	mlx_hook(win.win, KeyRelease, KeyReleaseMask, key_released, &win);
	mlx_loop_hook(win.mlx, loop, &win);
	mlx_loop(win.mlx);
	free_exit(&win);
	
	return (0);
}