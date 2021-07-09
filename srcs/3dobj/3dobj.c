/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3dobj.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 15:54:27 by jberredj          #+#    #+#             */
/*   Updated: 2021/07/09 16:31:30 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "structs/t_3dobj.h"
#include "geometry.h"

t_edge	*new_edge(int a, int b)
{
	t_edge	*edge;

	edge = (t_edge *)malloc(sizeof(t_edge));
	if (!edge)
		return (NULL);
	edge->a = a;
	edge->b = b;
	return (edge);
}

t_edge	set_edge(int a, int b)
{
	return ((t_edge){.a = a, .b = b});
}

t_face	*new_face(int nbr_edges)
{
	t_face	*face;

	if (nbr_edges < 3)
		return (NULL);
	face = NULL;
	face = (t_face *)malloc(sizeof(t_face));
	if (!face)
		return (NULL);
	face->nbr_edges = nbr_edges;
	face->edges = NULL;
	face->edges = (t_edge *)malloc(nbr_edges * sizeof(t_edge));
	if (!face->edges)
	{
		free(face);
		return (NULL);
	}
	return (face);
}

t_face	set_face(int nbr_edges, t_edge *edges)
{
	return ((t_face){.nbr_edges = nbr_edges, .edges = edges});
}

t_tri	tri(int a, int b, int c)
{
	return ((t_tri){.a = a, .b = b, .c = c});
}

t_quad	quad(int a, int b, int c, int d)
{
	return ((t_quad){.a = a, .b = b, .c = c, .d = d});
}

int	set_tri_face(t_tri tri, t_face *face)
{
	if (face->nbr_edges != 3)
		return (-1);
	if (!face->edges)
		return (-2);
	face->edges[0] = set_edge(tri.a, tri.b);
	face->edges[1] = set_edge(tri.b, tri.c);
	face->edges[2] = set_edge(tri.c, tri.a);
	return (0);	
}

int	set_quad_face(t_quad quad, t_face *face)
{
	if (face->nbr_edges != 4)
		return (-1);
	if (!face->edges)
		return (-2);
	face->edges[0] = set_edge(quad.a, quad.b);
	face->edges[1] = set_edge(quad.b, quad.c);
	face->edges[2] = set_edge(quad.c, quad.d);
	face->edges[3] = set_edge(quad.d, quad.a);
	return (0);	
}

t_3dobj	blank_obj(void)
{
	return((t_3dobj){.nbr_vertices = 0, .vertices = NULL,
					.nbr_faces = 0, .faces = NULL,
					.orient = vec3d(0,0,0)});
}

void	*free_3dobj(t_3dobj *obj)
{
	if (obj->faces)
		free(obj->faces);
	if (obj->vertices)
		free(obj->vertices);
	free(obj);
	return (NULL);
}