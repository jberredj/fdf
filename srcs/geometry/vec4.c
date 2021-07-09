/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:00:53 by jberredj          #+#    #+#             */
/*   Updated: 2021/06/10 11:02:37 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs/t_vec.h"

t_vec4i	vec4i(int x, int y, int z, int w)
{
	return ((t_vec4i){x, y, z, w});
}

t_vec4d	vec4d(double x, double y, double z, double w)
{
	return ((t_vec4d){x, y, z, w});
}
