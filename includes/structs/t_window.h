/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_window.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:48:01 by jberredj          #+#    #+#             */
/*   Updated: 2021/06/07 15:43:25 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_WINDOW_H
# define T_WINDOW_H
# include <stdbool.h>
typedef struct s_window
{
	void		*mlx;
	void		*win;
	bool		load_res;
	int			width;
	int			height;
	char		*title;
}			t_window;

#endif