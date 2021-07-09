/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 10:56:52 by jberredj          #+#    #+#             */
/*   Updated: 2021/06/22 14:09:08 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs/t_vec.h"

t_vec2i	vec2i(int x, int y)
{
	return ((t_vec2i){x, y});
}

t_vec2d	vec2d(double x, double y)
{
	return ((t_vec2d){x, y});
}

t_vec2i	vec2d_to_i(t_vec2d v)
{
	return ((t_vec2i){.x = (int)v.x, .y = (int) v.y});
}
