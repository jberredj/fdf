/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arwing_vertices.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 15:59:00 by jberredj          #+#    #+#             */
/*   Updated: 2021/07/09 17:23:57 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "structs/t_3dobj.h"
#include "geometry.h"

void	arwing_vertices_next(t_vertex *vertices)
{
	vertices[18].coord = vec3d(-2.000000, 0.000000, 0.000000);
	vertices[19].coord = vec3d(2.000000, 0.000000, 0.000000);
	vertices[20].coord = vec3d(0.000000, 0.000001, -8.000000);
	vertices[21].coord = vec3d(0.000000, -0.500000, -0.000000);
	vertices[22].coord = vec3d(0.000000, -0.000000, 1.500000);
	vertices[23].coord = vec3d(-9.000000, 0.249999, 5.000000);
	vertices[24].coord = vec3d(-2.500000, -0.500000, -1.500000);
	vertices[25].coord = vec3d(-4.000000, 0.500000, -2.000000);
	vertices[26].coord = vec3d(9.000000, 0.249999, 5.000000);
	vertices[27].coord = vec3d(2.500000, -0.500000, -1.500000);
	vertices[28].coord = vec3d(4.000000, 0.500000, -2.000000);
	vertices[29].coord = vec3d(0.000000, 0.621200, 1.983500);
	vertices[30].coord = vec3d(-1.980000, 0.002450, 0.003500);
	vertices[31].coord = vec3d(0.000000, 1.239950, 0.003500);
	vertices[32].coord = vec3d(1.980000, 0.002450, 0.003500);
	vertices[33].coord = vec3d(0.000000, -0.492550, 0.003500);
	vertices[34].coord = vec3d(0.000000, 0.002450, 1.488500);
	vertices[35].coord = vec3d(0.000000, 0.656222, 0.003500);
	vertices[36].coord = vec3d(0.729758, 0.200124, 0.003500);
	vertices[37].coord = vec3d(-0.729758, 0.200124, 0.003500);
	vertices[38].coord = vec3d(0.000000, 0.017684, 0.003500);
}

t_vertex	*arwing_vertices(void)
{
	t_vertex	*vertices;

	vertices = (t_vertex *)malloc(39 * sizeof(t_vertex));
	if (!vertices)
		return (NULL);
	vertices[0].coord = vec3d(0.737129, 0.199671, 0.000000);
	vertices[1].coord = vec3d(0.000000, 0.660376, 0.000000);
	vertices[2].coord = vec3d(-0.737129, 0.199671, 0.000000);
	vertices[3].coord = vec3d(0.000000, 0.015388, 0.000000);
	vertices[4].coord = vec3d(2.000000, 0.500000, 2.000000);
	vertices[5].coord = vec3d(3.000000, 3.000000, 3.000000);
	vertices[6].coord = vec3d(2.000000, -0.500000, -2.000000);
	vertices[7].coord = vec3d(-2.000000, 0.500000, 2.000000);
	vertices[8].coord = vec3d(-3.000000, 3.000000, 3.000000);
	vertices[9].coord = vec3d(-2.000000, -0.500000, -2.000000);
	vertices[10].coord = vec3d(2.010000, 0.500000, 2.000000);
	vertices[11].coord = vec3d(2.010000, -0.500000, -2.000000);
	vertices[12].coord = vec3d(3.010000, 3.000000, 3.000000);
	vertices[13].coord = vec3d(-1.990000, 0.500000, 2.000000);
	vertices[14].coord = vec3d(-1.990000, -0.500000, -2.000000);
	vertices[15].coord = vec3d(-2.990000, 3.000000, 3.000000);
	vertices[16].coord = vec3d(0.000000, 0.625000, 2.000000);
	vertices[17].coord = vec3d(0.000000, 1.250000, 0.000000);
	arwing_vertices_next(vertices);
	return (vertices);
}
