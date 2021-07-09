/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_camera.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:16:50 by jberredj          #+#    #+#             */
/*   Updated: 2021/06/21 14:18:46 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_CAMERA_H
# define T_CAMERA_H
# include "t_vec.h"
typedef struct s_camera
{
	t_vec3d	position;
	t_vec3d	rotation;
	double	fov;
} 		t_camera;

#endif