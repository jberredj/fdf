/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 10:47:58 by jberredj          #+#    #+#             */
/*   Updated: 2021/07/21 21:57:18 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_H
# define GEOMETRY_H
# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif
# include <stdint.h>
# include "structs/t_vec.h"
# include "structs/t_point.h"
# include "structs/t_img.h"

void		draw_line_bh(t_vec2i p0, t_vec2i p1, t_img	*frame, uint32_t color);
void		draw_line_bh_gradient(t_point p0, t_point p1, t_img *frame);
t_vec2i		vec2i(int x, int y);
t_vec2d		vec2d(double x, double y);
t_vec3i		vec3i(int x, int y, int z);
t_vec3i		*vec3i_new(int x, int y, int z);
t_vec3d		vec3d(double x, double y, double z);
t_vec3i		*vec3d_new(double x, double y, double z);
t_vec3d		vec3d_rot_x(t_vec3d v, double angle);
t_vec3d		vec3d_rot_y(t_vec3d v, double angle);
t_vec3d		vec3d_rot_z(t_vec3d v, double angle);
t_vec2i		vec2d_to_i(t_vec2d v);
t_vec2d		ortho_projection(t_vec3d point, double zoom);
double		normalizeAngle(double angle);

#endif