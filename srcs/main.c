/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:43:38 by jberredj          #+#    #+#             */
/*   Updated: 2021/07/15 14:43:38 by jberredj         ###   ########.fr       */
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
#include "structs/t_window.h"
#include "structs/t_vec.h"
#include "mlx.h"
#include "geometry.h"
#include "objects.h"
#include "color_utils.h"
#include "window.h"

void	project_mesh(t_3dobj *obj, t_vec2d cam, double zoom, double amplitude)
{
	t_vec3d	point;
	int		i;

	printf("%f, %f, %f\n", obj->orient.x, obj->orient.y, obj->orient.z);
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

int	loop(t_window *win)
{
	int		i;
	t_vec2d	projected;

	project_mesh(win->objs, win->camera, win->zoom, win->amplitude);
	i = -1;
	while (++i < win->objs->nbr_faces)
		put_face_edge(i, *win->objs, WHITE, win);
	push_back_fb(win->mlx, win->win, &win->fb, 0x313131);
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

	ls->orient.x = 0.7;
	ls->orient.y = 0.3;
	ls->orient.z = -0.4;
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
	//fd = args_parser(argc, argv, &win);
	win.objs = create_simple_ls();
	create_win(&win);
	mlx_loop(win.mlx);
	free_exit(&win);
	return (0);
}
