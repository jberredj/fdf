/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_vertices.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:21:10 by jberredj          #+#    #+#             */
/*   Updated: 2021/08/16 11:28:08 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libs/libft/includes/ft_lst.h"
#include "structs/t_vec.h"
#include "structs/t_3dobj.h"
#include "parsers.h"
#include "geometry.h"

void	set_loaded_color(t_list *lines, t_vec2i	mesh_size, t_vertex *vertices)
{
	int			x;
	int			y;
	t_load_line	elem;

	y = -1;
	while (++y < mesh_size.y)
	{
		x = -1;
		elem = *(t_load_line *)lines->content;
		while (++x < mesh_size.x)
			if (elem.color_loaded[x])
				vertices[y * mesh_size.x + x].color = elem.colors[x];
		lines = lines->next;
	}
}

t_vertex	*list_to_vertices(t_list *y_list, int nbr_vert, t_vec2i	mesh_size)
{
	t_list		*lines;
	t_vertex	*vertices;
	t_load_line	elem;
	int			x;
	int			y;

	vertices = (t_vertex *)malloc(sizeof(t_vertex) * nbr_vert);
	if (!vertices)
		return (NULL);
	lines = y_list;
	y = -1;
	while (++y < mesh_size.y)
	{
		x = -1;
		elem = *(t_load_line *)lines->content;
		while (++x < mesh_size.x)
			vertices[y * mesh_size.x + x].coord = vec3d(x - (mesh_size.x / 2.0),
					y - (mesh_size.y / 2.0), elem.zs[x]);
		lines = lines->next;
	}
	attribute_color(vertices, nbr_vert);
	set_loaded_color(y_list, mesh_size, vertices);
	return (vertices);
}
