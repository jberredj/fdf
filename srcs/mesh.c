/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:10:06 by jberredj          #+#    #+#             */
/*   Updated: 2021/06/14 15:53:17 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "structs/t_vec.h"
#include "geometry.h"
#include "../libs/libft/includes/ft_lst.h"

typedef struct	s_mesh
{
	char		*name;
	t_vec3d		*vertices;
	t_vec3d		position;
	t_vec3d		rotation;
}		t_mesh;

t_mesh	*mesh(char *name, int nbr_vert)
{
	t_mesh	*mesh;

	mesh = NULL;
	mesh = (t_mesh *)ft_calloc(1, sizeof(t_mesh));
	if (!mesh)
		return (NULL);
	mesh->name = name;
	mesh->vertices = NULL;
	mesh->vertices = (t_vec3d *)ft_calloc(nbr_vert, sizeof(t_vec3d));
	if (!mesh->vertices)
	{
		free(mesh);
		return (NULL);
	}
	return (mesh);
}