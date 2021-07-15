/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 11:59:19 by jberredj          #+#    #+#             */
/*   Updated: 2021/07/15 11:57:27 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_UTILS_H
# define COLOR_UTILS_H
# include <stdint.h>
# include "structs/t_vec.h"
# include "structs/t_point.h"
# define RED 0xFFFF0000
# define GREEN 0xFF00FF00
# define BLUE 0xFF0000FF
# define WHITE 0xFFFFFFFF
# define BLACK 0xFF000000

int			addShade(uint32_t color, double shade);
int			argb(uint8_t a, int8_t r, uint8_t g, uint8_t b);
int			blend_argb(uint32_t colora, uint32_t colorb);
uint8_t		get_a(uint32_t argb);
uint8_t		get_r(uint32_t argb);
uint8_t		get_g(uint32_t argb);
uint8_t		get_b(uint32_t argb);
uint32_t	get_point_color(t_point cur, t_point p0, t_point p1, t_vec2i delta);

#endif