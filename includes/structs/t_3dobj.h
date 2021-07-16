/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_3dobj.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 09:53:20 by jberredj          #+#    #+#             */
/*   Updated: 2021/07/15 17:19:15 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_3DOBJ_H
# define T_3DOBJ_H
# include <stdint.h>
# include "t_vec.h"

typedef struct s_edge
{
	int	a;
	int	b;
}	t_edge;

typedef struct s_face
{
	int			nbr_edges;
	t_edge		*edges;
	uint32_t	color;
}	t_face;

typedef struct s_tri
{
	int	a;
	int	b;
	int	c;
}	t_tri;

typedef struct s_quad
{
	int	a;
	int	b;
	int	c;
	int	d;
}	t_quad;

typedef struct s_vertex
{
	t_vec3d		coord;
	t_vec2d		projected;
	uint32_t	color;
}	t_vertex;

typedef struct s_3dobj
{
	int			nbr_vertices;
	t_vertex	*vertices;
	int			nbr_faces;
	t_face		*faces;
	t_vec3d		orient;	
}	t_3dobj;

#endif