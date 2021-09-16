/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 15:56:03 by jberredj          #+#    #+#             */
/*   Updated: 2021/09/16 18:06:02 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H
# include "structs/t_3dobj.h"
# include "structs/t_window.h"

t_edge	*new_edge(int a, int b);
t_edge	set_edge(int a, int b);
t_face	*new_face(int nbr_edges);
t_face	set_face(int nbr_edges, t_edge *edges);
t_tri	tri(int a, int b, int c);
t_quad	quad(int a, int b, int c, int d);
int		set_tri_face(t_tri tri, t_face *face);
int		set_quad_face(t_quad quad, t_face *face);
t_3dobj	blank_obj(void);
void	free_3dobj(t_3dobj *obj);
void	put_model_line(t_edge edge, t_vertex *vertices, uint32_t color,
			t_window *win);
void	put_face_edge(int face_index, t_3dobj obj, t_window *win);

#endif