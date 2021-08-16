/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3dobj.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 15:54:27 by jberredj          #+#    #+#             */
/*   Updated: 2021/08/16 11:31:33 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "structs/t_3dobj.h"
#include "geometry.h"

t_3dobj	blank_obj(void)
{
	return ((t_3dobj){.nbr_vert = 0, .vertices = NULL,
		.nbr_faces = 0, .faces = NULL,
		.orient = vec3d(0, 0, 0)});
}

void	free_3dobj(t_3dobj *obj)
{
	int	i;

	i = -1;
	if (obj)
	{
		while (++i < obj->nbr_faces)
			free(obj->faces[i].edges);
		if (obj->faces)
			free(obj->faces);
		if (obj->vertices)
			free(obj->vertices);
		free(obj);
	}
}
