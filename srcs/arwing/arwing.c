/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arwing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 11:33:36 by jberredj          #+#    #+#             */
/*   Updated: 2021/07/09 16:35:40 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "structs/t_3dobj.h"
#include "objects.h"
#include "arwing.h"

t_3dobj	*create_arwing(void)
{
	t_3dobj	*arwing;

	arwing = (t_3dobj *)malloc(sizeof(t_3dobj));
	if (!arwing)
		return (NULL);
	*arwing = blank_obj();
	arwing->vertices = arwing_vertices();
	if (!arwing->vertices)
		return (free_3dobj(arwing));
	arwing->nbr_vertices = 39;
	arwing->faces = arwing_faces();
	if (!arwing->faces)
		return (free_3dobj(arwing));
	arwing->nbr_faces = 29;
	return (arwing);
}
