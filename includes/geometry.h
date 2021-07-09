/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 10:47:58 by jberredj          #+#    #+#             */
/*   Updated: 2021/06/28 17:16:51 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_H
# define GEOMETRY_H
# include <stdint.h>
# include "structs/t_vec.h"
# include "structs/t_img.h"
# include "structs/t_triangle.h"

void		draw_line_bh(t_vec2i p0, t_vec2i p1, t_img	*frame, uint32_t color);
void		draw_triangle(t_triangle triangle, t_img *img);
t_triangle	triangle(t_vec2i a, t_vec2i b, t_vec2i c, uint32_t color);
t_vec2i		vec2i(int x, int y);
t_vec2d		vec2d(double x, double y);
t_vec3i		vec3i(int x, int y, int z);
t_vec3i		*vec3i_new(int x, int y, int z);
t_vec3d		vec3d(double x, double y, double z);
t_vec3i		*vec3d_new(double x, double y, double z);
t_vec4i		vec4i(int x, int y, int z, int w);
t_vec4d		vec4d(double x, double y, double z, double w);
t_vec3d		vec3d_rot_x(t_vec3d v, double angle);
t_vec3d		vec3d_rot_y(t_vec3d v, double angle);
t_vec3d		vec3d_rot_z(t_vec3d v, double angle);
t_vec2i		vec2d_to_i(t_vec2d v);
#endif