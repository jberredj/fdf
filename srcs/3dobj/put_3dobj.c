/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_3dobj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:04:19 by jberredj          #+#    #+#             */
/*   Updated: 2021/07/21 21:52:40 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "structs/t_window.h"
#include "color_utils.h"
#include "structs/t_3dobj.h"
#include "structs/t_point.h"
#include "geometry.h"

void	put_model_line(t_edge edge, t_vertex *vertices, t_window *win)
{
	t_point	p0;
	t_point	p1;

	p0.coord = vec2d_to_i(vertices[edge.a].projected);
	p1.coord = vec2d_to_i(vertices[edge.b].projected);
	p0.coord.x += win->width / 2;
	p0.coord.y += win->height / 2;
	p1.coord.x += win->width / 2;
	p1.coord.y += win->height / 2;
	p0.color = vertices[edge.a].color;
	p1.color = vertices[edge.b].color;
	if ((p0.coord.x < 0 && p1.coord.x < 0)
		|| (p0.coord.x > win->width && p1.coord.x > win->width)
		|| (p0.coord.y < 0 && p1.coord.y < 0)
		|| (p0.coord.y > win->height && p1.coord.y > win->height))
		return ;
	draw_line_bh_gradient(p0, p1, win->fb.back);
}

void	put_face_edge(int face, t_3dobj obj, t_window *win)
{
	int	i;
	int	nbr_edges;

	nbr_edges = obj.faces[face].nbr_edges;
	i = -1;
	while (++i < nbr_edges)
		put_model_line(obj.faces[face].edges[i], obj.vertices, win);
}
