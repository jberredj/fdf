/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 11:58:13 by jberredj          #+#    #+#             */
/*   Updated: 2021/06/07 17:38:19 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdio.h>
#include "structs/t_argb.h"

uint8_t	get_a(uint32_t argb)
{
	return ((argb & 0xFF000000) >> 24);
}

uint8_t	get_r(uint32_t argb)
{
	return ((argb & 0x00FF0000) >> 16);
}

uint8_t	get_g(uint32_t argb)
{
	return ((argb & 0x0000FF00) >> 8);
}

uint8_t	get_b(uint32_t argb)
{
	return (argb & 0x000000FF);
}
 
int addShade(uint32_t color, double shade)
{
	uint8_t a;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;

	a = ((color >> 24) & 0xFF) - (((color >> 24) & 0xFF) * shade);
	r = ((color >> 16) & 0xFF) - (((color >> 16) & 0xFF) * shade);
	g = ((color >> 8) & 0xFF) - (((color >> 8) & 0xFF) * shade);
	b = (color & 0xFF) - ((color & 0xFF) * shade);
	return(a << 24 | r << 16 | g << 8 | b);
}

uint32_t	argb(uint8_t a, uint8_t r, uint8_t g, uint8_t b)
{
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
	// c_out.a = 255 - ca.a + (cb.a * (255 - ca.a) / 255);
	// c_out.r = (ca.r * ca.a / 255) + (cb.r * cb.a * (255 - ca.a) / (255*255));
	// c_out.g = (ca.g * ca.a / 255) + (cb.g * cb.a * (255 - ca.a) / (255*255));
	// c_out.b = (ca.g * ca.a / 255) + (cb.b * cb.a * (255 - ca.a) / (255*255));
	return (argb(c_out.a, c_out.r, c_out.g, c_out.b));
}