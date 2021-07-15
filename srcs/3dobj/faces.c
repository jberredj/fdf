/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   faces.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 13:19:46 by jberredj          #+#    #+#             */
/*   Updated: 2021/07/15 13:22:03 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "structs/t_3dobj.h"

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
