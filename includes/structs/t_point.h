/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_point.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 18:40:33 by jberredj          #+#    #+#             */
/*   Updated: 2021/07/15 10:37:05 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_POINT_H
# define T_POINT_H
# include <stdint.h>
# include "t_vec.h"

typedef struct s_point
{
	t_vec2i		coord;
	uint32_t	color;
}				t_point;

#endif