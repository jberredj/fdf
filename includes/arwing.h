/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arwing.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 16:04:04 by jberredj          #+#    #+#             */
/*   Updated: 2021/07/09 16:26:46 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ARWING_H
# define ARWING_H
# include "structs/t_3dobj.h"

t_3dobj		*create_arwing(void);
t_vertex	*arwing_vertices(void);
t_face		*arwing_faces(void);

#endif