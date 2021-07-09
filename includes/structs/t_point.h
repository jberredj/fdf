/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_point.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:35:21 by jberredj          #+#    #+#             */
/*   Updated: 2021/06/07 16:37:52 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_POINT_H
# define T_POINT_H
# include <stdint.h>
typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
	uint32_t	color;
}				t_point;

#endif