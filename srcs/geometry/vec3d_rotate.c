/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3d_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 18:00:40 by jberredj          #+#    #+#             */
/*   Updated: 2021/06/22 10:36:42 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "structs/t_vec.h"

t_vec3d	vec3d_rot_x(t_vec3d v, double angle)
{
	return ((t_vec3d)
		{
			.x = v.x,
			.y = v.y * cos(angle) - v.z * sin(angle),
			.z = v.y * sin(angle) + v.z * cos(angle)
		}
	);
}

t_vec3d	vec3d_rot_y(t_vec3d v, double angle)
{
	return ((t_vec3d)
		{
			.x = v.x * cos(angle) - v.z * sin(angle),
			.y = v.y,
			.z = v.x * sin(angle) + v.z * cos(angle)
		}
	);
}

t_vec3d	vec3d_rot_z(t_vec3d v, double angle)
{
	return ((t_vec3d)
		{
			.x = v.x * cos(angle) - v.y * sin(angle),
			.y = v.x * sin(angle) + v.y * cos(angle),
			.z = v.z
		}
	);
}
