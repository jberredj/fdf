/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:01:56 by jberredj          #+#    #+#             */
/*   Updated: 2021/07/16 17:56:36 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs/t_vec.h"

t_vec2d	ortho_projection(t_vec3d point, double zoom)
{
	return ((t_vec2d){.x = point.x * zoom, .y = point.y * zoom});
}
