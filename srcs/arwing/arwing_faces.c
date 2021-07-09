/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arwing_faces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 16:03:33 by jberredj          #+#    #+#             */
/*   Updated: 2021/07/09 16:30:48 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "structs/t_3dobj.h"
#include "objects.h"

void	*free_panic_arwing_faces(t_face *faces, int current_pos)
{
	int	i;

	i = -1;
	while (++i < current_pos)
		free(faces[i].edges);
	free(faces);
	return (NULL);
}

void	set_arwing_quad(t_face *faces)
{
	set_quad_face(quad(0, 1, 2, 3), &faces[0]);
	set_quad_face(quad(35, 36, 32, 31), &faces[21]);
	set_quad_face(quad(37, 35, 31, 30), &faces[22]);
	set_quad_face(quad(36, 38, 33, 32), &faces[23]);
	set_quad_face(quad(38, 37, 30, 33), &faces[24]);
}

void	set_arwing_faces(t_face *faces)
{
	set_tri_face(tri(16, 17, 18), &faces[1]);
	set_tri_face(tri(19, 17, 16), &faces[2]);
	set_tri_face(tri(17, 19, 20), &faces[3]);
	set_tri_face(tri(20, 18, 17), &faces[4]);
	set_tri_face(tri(21, 19, 22), &faces[5]);
	set_tri_face(tri(21, 22, 18), &faces[6]);
	set_tri_face(tri(20, 21, 18), &faces[7]);
	set_tri_face(tri(21, 20, 19), &faces[8]);
	set_tri_face(tri(23, 24, 18), &faces[9]);
	set_tri_face(tri(23, 25, 24), &faces[10]);
	set_tri_face(tri(25, 23, 18), &faces[11]);
	set_tri_face(tri(25, 18, 24), &faces[12]);
	set_tri_face(tri(26, 19, 27), &faces[13]);
	set_tri_face(tri(26, 27, 28), &faces[14]);
	set_tri_face(tri(28, 19, 26), &faces[15]);
	set_tri_face(tri(28, 27, 19), &faces[16]);
	set_tri_face(tri(29, 30, 31), &faces[17]);
	set_tri_face(tri(32, 29, 31), &faces[18]);
	set_tri_face(tri(33, 34, 32), &faces[19]);
	set_tri_face(tri(33, 30, 34), &faces[20]);
	set_tri_face(tri(4, 5, 6), &faces[25]);
	set_tri_face(tri(7, 8, 9), &faces[26]);
	set_tri_face(tri(10, 11, 12), &faces[27]);
	set_tri_face(tri(13, 14, 15), &faces[28]);
	set_arwing_quad(faces);
}

t_face	*arwing_faces(void)
{
	t_face	*faces;
	int		i;
	int		nbr_edges;

	faces = (t_face *)malloc(29 * sizeof(t_face));
	if (!faces)
		return (NULL);
	i = -1;
	while (++i < 29)
	{
		if (i == 0 || (i >= 21 && i <= 24))
			nbr_edges = 4;
		else
			nbr_edges = 3;
		faces[i].nbr_edges = nbr_edges;
		faces[i].edges = (t_edge *)malloc(nbr_edges * sizeof(t_edge));
		if (!faces[i].edges)
			return (free_panic_arwing_faces(faces, i));
	}
	set_arwing_faces(faces);
	return (faces);
}
