/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 11:58:13 by jberredj          #+#    #+#             */
/*   Updated: 2021/07/15 14:46:05 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "structs/t_argb.h"
#include "structs/t_vec.h"
#include "structs/t_point.h"
#include "color_utils.h"

static uint8_t	color_linear_interpolation(uint8_t c1, uint8_t c2, double pct)
{
	return (((1 - pct) * c1 + pct * c2));
}

static double	percent(int min, int max, int current)
{
	double	position;
	double	size;

	position = current - min;
	size = max - min;
	if (size == 0)
		return (1.0);
	else
		return (position / size);
}

uint32_t	get_point_color(t_point cur, t_point p0, t_point p1, t_vec2i delta)
{
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
	double		pct;

	if (cur.color == p1.color)
		return (cur.color);
	if (delta.x > delta.y)
		pct = percent((int)p0.coord.x, (int)p1.coord.x, (int)cur.coord.x);
	else
		pct = percent((int)p0.coord.y, (int)p1.coord.y, (int)cur.coord.y);
	r = color_linear_interpolation(get_r(p0.color), get_r(p1.color), pct);
	g = color_linear_interpolation(get_g(p0.color), get_g(p1.color), pct);
	b = color_linear_interpolation(get_b(p0.color), get_b(p1.color), pct);
	return (argb(0xFF, r, g, b));
}

int	addShade(uint32_t color, double shade)
{
	uint8_t	a;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;

	a = ((color >> 24) & 0xFF) - (((color >> 24) & 0xFF) * shade);
	r = ((color >> 16) & 0xFF) - (((color >> 16) & 0xFF) * shade);
	g = ((color >> 8) & 0xFF) - (((color >> 8) & 0xFF) * shade);
	b = (color & 0xFF) - ((color & 0xFF) * shade);
	return (a << 24 | r << 16 | g << 8 | b);
}

uint32_t	blend_argb(uint32_t colora, uint32_t colorb)
{
	t_argb	ca;
	t_argb	cb;
	t_argb	c_out;

	ca.a = 255 - get_a(colora);
	ca.r = get_r(colora);
	ca.g = get_g(colora);
	ca.b = get_b(colora);
	cb.a = 255 - get_a(colorb);
	cb.r = get_r(colorb);
	cb.g = get_g(colorb);
	cb.b = get_b(colorb);
	if (ca.a == 0 && cb.b == 0)
		return (0xFF000000);
	c_out.a = ca.a + (cb.a * (255 - ca.a) / 255);
	c_out.r = (ca.r * ca.a + cb.r * cb.a * (255 - ca.a) / 255) / c_out.a;
	c_out.g = (ca.g * ca.a + cb.g * cb.a * (255 - ca.a) / 255) / c_out.a;
	c_out.b = (ca.b * ca.a + cb.b * cb.a * (255 - ca.a) / 255) / c_out.a;
	c_out.a = 255 - c_out.a;
	return (argb(c_out.a, c_out.r, c_out.g, c_out.b));
}

