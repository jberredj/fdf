/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_window.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:48:01 by jberredj          #+#    #+#             */
/*   Updated: 2021/07/09 18:54:01 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_WINDOW_H
# define T_WINDOW_H
# include <stdbool.h>
# include "t_img.h"
# include "structs/t_3dobj.h"
typedef struct s_window
{
	void	*mlx;
	void	*win;
	bool	load_res;
	int		width;
	int		height;
	char	*title;
	t_3dobj	*objs;
	t_vec2d	camera;
	double	zoom;
	double	amplitude;
	t_fb	fb;
}			t_window;

#endif