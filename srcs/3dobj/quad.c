/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quad.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 13:22:26 by jberredj          #+#    #+#             */
/*   Updated: 2021/07/15 13:29:03 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs/t_3dobj.h"
#include "objects.h"

t_quad	quad(int a, int b, int c, int d)
{
	return ((t_quad){.a = a, .b = b, .c = c, .d = d});
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
