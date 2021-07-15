/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 13:21:11 by jberredj          #+#    #+#             */
/*   Updated: 2021/07/15 13:25:24 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs/t_3dobj.h"
#include "objects.h"

t_tri	tri(int a, int b, int c)
{
	return ((t_tri){.a = a, .b = b, .c = c});
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
