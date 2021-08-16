/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_3dobj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 12:08:08 by jberredj          #+#    #+#             */
/*   Updated: 2021/08/16 12:39:48 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libs/libft/includes/ft_lst.h"
#include "parsers.h"
#include "error_code.h"
#include "objects.h"
#include "structs/t_3dobj.h"
#include "structs/t_vec.h"
#include "geometry.h"

t_quad	mesh_face_index(t_vec2i size, t_vec2i offset)
{
	return (
		quad(
			(offset.y * size.x) + offset.x,
			(offset.y * size.x) + offset.x + 1,
			((offset.y + 1) * size.x) + offset.x + 1,
			((offset.y + 1) * size.x) + offset.x
		)
	);
}

t_face	*create_faces(t_vec2i mesh_size, int *obj_nbr)
{
	int		nbr_f;
	t_face	*faces;
	t_vec2i	vert_list;

	nbr_f = (mesh_size.x - 1) * (mesh_size.y - 1);
	faces = (t_face *)malloc(sizeof(t_face) * nbr_f);
	if (!faces)
		return (NULL);
	*obj_nbr = nbr_f;
	while (--nbr_f >= 0)
		faces[nbr_f].nbr_edges = 4;
	vert_list.y = -1;
	while (++vert_list.y < mesh_size.y - 1)
	{
		vert_list.x = -1;
		while (++vert_list.x < mesh_size.x - 1)
		{
			nbr_f++;
			faces[nbr_f].edges = (t_edge *)malloc(sizeof(t_edge) * 4);
			if (!faces[nbr_f].edges)
				return (error_faces(&faces, nbr_f));
			set_quad_face(mesh_face_index(mesh_size, vert_list), &faces[nbr_f]);
		}
	}
	return (faces);
}

int	create_mesh(t_list **y_list, t_3dobj **obj)
{
	int		error;
	t_vec2i	m_size;
	t_3dobj	*new_mesh;

	error = check_loaded(*y_list, &m_size);
	if (error)
		return (error_free_coord_list(error, y_list));
	new_mesh = (t_3dobj *)malloc(sizeof(t_3dobj));
	if (!new_mesh)
		return (error_free_coord_list(MALLOC_ERROR, y_list));
	*new_mesh = blank_obj();
	new_mesh->nbr_vert = m_size.x * m_size.y;
	new_mesh->vertices = list_to_vertices(*y_list, new_mesh->nbr_vert, m_size);
	free_coord_list(y_list);
	if (!new_mesh->nbr_vert)
		return (error_free(MALLOC_ERROR, new_mesh));
	new_mesh->faces = create_faces(m_size, &new_mesh->nbr_faces);
	if (!new_mesh->faces)
	{
		free_3dobj(new_mesh);
		return (error_free(MALLOC_ERROR, new_mesh));
	}
	new_mesh->orient = vec3d(0.523599, 0.523599, 0.9);
	*obj = new_mesh;
	return (0);
}
