/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:05:00 by jberredj          #+#    #+#             */
/*   Updated: 2021/07/15 13:30:21 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "structs/t_vec.h"
#include "structs/t_img.h"
#include "structs/t_point.h"
#include <math.h>
#include "../libs/libft/includes/ft_utils.h"
#include "color_utils.h"
#include "mlx_utils.h"

static	t_vec2i	set_d(t_vec2i p0, t_vec2i p1)
{
	return ((t_vec2i){ft_abs(p1.x - p0.x), -ft_abs(p1.y - p0.y)});
}

static	t_vec2i	set_s(t_vec2i p0, t_vec2i p1)
{
	t_vec2i	s;

	if (p0.x < p1.x)
		s.x = 1;
	else
		s.x = -1;
	if (p0.y < p1.y)
		s.y = 1;
	else
		s.y = -1;
	return (s);
}

void	draw_line_dda(t_vec2i p0, t_vec2i p1, t_img	*frame, uint32_t color)
{
	t_vec2i	delta;
	int		s_len;
	t_vec2d	step;
	t_vec2d	curr;
	int		i;

	delta.x = (p1.x - p0.x);
	delta.y = (p1.y - p0.y);
	s_len = ft_abs(delta.x);
	if (s_len < ft_abs(delta.y))
		s_len = ft_abs(delta.y);
	step.x = delta.x / (double)s_len;
	step.y = delta.y / (double)s_len;
	curr.x = p0.x;
	curr.y = p0.y;
	i = -1;
	while (++i < s_len)
	{
		img_pixel_put(frame, round(curr.x), round(curr.y), color);
		curr.x += step.x;
		curr.y += step.y;
	}
}

void	draw_line_bh_gradient(t_point p0, t_point p1, t_img *frame)
{
	t_vec2i	d;
	t_vec2i	s;
	t_point	start;
	int		err[2];

	d = set_d(p0.coord, p1.coord);
	s = set_s(p0.coord, p1.coord);
	err[0] = d.x + d.y;
	start = p0;
	while (p0.coord.x != p1.coord.x || p0.coord.y != p1.coord.y)
	{
		img_pixel_put(frame, p0.coord.x, p0.coord.y,
			get_point_color(p0, start, p1, d));
		err[1] = 2 * err[0];
		if (err[1] >= d.y)
		{
			err[0] += d.y;
			p0.coord.x += s.x;
		}
		if (err[1] <= d.x)
		{
			err[0] += d.x;
			p0.coord.y += s.y;
		}
	}
}

void	draw_line_bh(t_vec2i p0, t_vec2i p1, t_img	*frame, uint32_t color)
{
	t_vec2i	d;
	t_vec2i	s;
	int		err;
	int		err2;

	d = set_d(p0, p1);
	s = set_s(p0, p1);
	err = d.x + d.y;
	while (p0.x != p1.x || p0.y != p1.y)
	{
		img_pixel_put(frame, p0.x, p0.y, color);
		err2 = 2 * err;
		if (err2 >= d.y)
		{
			err += d.y;
			p0.x += s.x;
		}
		if (err2 <= d.x)
		{
			err += d.x;
			p0.y += s.y;
		}
	}
}
