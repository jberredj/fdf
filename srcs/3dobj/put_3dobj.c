/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_3dobj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:04:19 by jberredj          #+#    #+#             */
/*   Updated: 2021/07/15 13:28:44 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "structs/t_window.h"
#include "color_utils.h"
#include "structs/t_3dobj.h"
#include "structs/t_point.h"
#include "geometry.h"

uint32_t	get_color_from_z(double z)
{
	if (z < -8)
		return (0x000133);
	if (z < -6)
		return (0x001146);
	if (z < -2)
		return (0x00035b);
	if (z < 0)
		return (0x1805db);
	if (z > 16)
		return (0xe50000);
	if (z > 14)
		return (0x9a0200);
	if (z > 12)
		return (0x8f1402);
	if (z > 10)
		return (0x922b05);
	if (z > 8)
		return (0xb27a01);
	if (z > 6)
		return (0xf5bf03);
	if (z > 4)
		return (0xfddc5c);
	if (z > 2)
		return (0xc8fd3d);
	return (0x56fca2);
}

void	put_model_line(t_edge edge, t_vertex *vertices, t_window *win)
{
	t_vec2i	p0;
	t_vec2i	p1;
	t_point	pp0;
	t_point	pp1;

	p0 = vec2d_to_i(vertices[edge.a].projected);
	p1 = vec2d_to_i(vertices[edge.b].projected);
	p0.x += win->width / 2;
	p0.y += win->height / 2;
	p1.x += win->width / 2;
	p1.y += win->height / 2;
	pp0.coord = p0;
	pp1.coord = p1;
	pp0.color = get_color_from_z(vertices[edge.a].coord.z);
	pp1.color = get_color_from_z(vertices[edge.b].coord.z);
	draw_line_bh_gradient(pp0, pp1, win->fb.back);
}

void	put_face_edge(int face, t_3dobj obj, uint32_t color, t_window *win)
{
	int	i;
	int	nbr_edges;

	nbr_edges = obj.faces[face].nbr_edges;
	i = -1;
	while (++i < nbr_edges)
		put_model_line(obj.faces[face].edges[i], obj.vertices, win);
}
