/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_vec.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:13:16 by jberredj          #+#    #+#             */
/*   Updated: 2021/09/16 18:06:45 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_VEC_H
# define T_VEC_H

typedef struct s_vec2i
{
	int	x;
	int	y;
}	t_vec2i;

typedef struct s_vec2d
{
	double	x;
	double	y;
}	t_vec2d;

typedef struct s_vec3i
{
	int	x;
	int	y;
	int	z;
}	t_vec3i;

typedef struct s_vec3d
{
	double	x;
	double	y;
	double	z;	
}	t_vec3d;
#endif