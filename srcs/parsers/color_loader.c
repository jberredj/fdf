/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_loader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:50:32 by jberredj          #+#    #+#             */
/*   Updated: 2021/08/16 12:36:25 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "structs/t_3dobj.h"

uint32_t	get_color_from_z(double z, double z_max)
{
	if (z < (z * z_max) / -8)
		return (0x000133);
	if (z < (z * z_max) / -6)
		return (0x001146);
	if (z < (z * z_max) / -2)
		return (0x00035b);
	if (z < 0)
		return (0x1805db);
	if (z > (z * z_max) / 16)
		return (0xe50000);
	if (z > (z * z_max) / 14)
		return (0x9a0200);
	if (z > (z * z_max) / 12)
		return (0x8f1402);
	if (z > (z * z_max) / 10)
		return (0x922b05);
	if (z > (z * z_max) / 8)
		return (0xb27a01);
	if (z > (z * z_max) / 6)
		return (0xf5bf03);
	if (z > (z * z_max) / 4)
		return (0xfddc5c);
	if (z > (z * z_max) / 2)
		return (0xc8fd3d);
	return (0x56fca2);
}

void	attribute_color(t_vertex *vertices, int nbr)
{
	int		i;
	double	z_max;

	i = -1;
	z_max = 0;
	while (++i < nbr)
		if (vertices[i].coord.z > z_max)
			z_max = vertices[i].coord.z;
	i = -1;
	while (++i < nbr)
		vertices[i].color = get_color_from_z(vertices[i].coord.z, z_max);
}
