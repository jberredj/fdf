/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:44:59 by jberredj          #+#    #+#             */
/*   Updated: 2021/06/07 15:49:20 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <X11/X.h>
#include "mlx.h"
#include "structs/t_window.h"

void free_exit(t_window *win)
{
	if (win->win)
		mlx_destroy_window(win->mlx, win->win);
	mlx_destroy_display(win->mlx);
	free(win->mlx);
}

int close_mlx(t_window *win)
{
	mlx_loop_end(win->mlx);
	return (0);
}

void	create_win(t_window *win)
{
	win->win = mlx_new_window(win->mlx, win->width, win->height,
		win->title);
	mlx_hook(win->win, ClientMessage, KeyPressMask, close_mlx, win);
}

void	init_win_struct(t_window *win, char *title)
{
	win->height = 0;
	win->mlx = mlx_init();
	win->title = title;
	win->width = 0;
	win->win = NULL;
}