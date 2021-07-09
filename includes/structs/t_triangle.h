/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_triangle.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 10:36:54 by jberredj          #+#    #+#             */
/*   Updated: 2021/06/10 10:52:44 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_TRIANGLE_H
# define T_TRIANGLE_H
# include <stdint.h>
# include "structs/t_vec.h"

typedef struct s_triangle
{
	t_vec2i		a;
	t_vec2i		b;
	t_vec2i		c;
	uint32_t	color;
}				t_triangle;
#endif