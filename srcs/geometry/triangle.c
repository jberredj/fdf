/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 10:23:15 by jberredj          #+#    #+#             */
/*   Updated: 2021/06/28 17:16:49 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs/t_vec.h"
#include "structs/t_img.h"
#include "structs/t_triangle.h"
#include "geometry.h"

t_triangle	triangle(t_vec2i a, t_vec2i b, t_vec2i c, uint32_t color)
{
	return((t_triangle){a, b, c, color});
}

void	draw_triangle(t_triangle triangle, t_img *img)
{
	draw_line_bh(triangle.a, triangle.b, img, triangle.color);
	draw_line_bh(triangle.b, triangle.c, img, triangle.color);
	draw_line_bh(triangle.c, triangle.a, img, triangle.color);
}
