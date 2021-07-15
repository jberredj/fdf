/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:15:55 by jberredj          #+#    #+#             */
/*   Updated: 2021/07/15 14:16:57 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

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

uint32_t	argb(uint8_t a, uint8_t r, uint8_t g, uint8_t b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}
