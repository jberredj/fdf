/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:44:59 by jberredj          #+#    #+#             */
/*   Updated: 2021/07/15 14:11:59 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <X11/X.h>
#include "mlx.h"
#include "mlx_utils.h"
#include "structs/t_window.h"
#include "window.h"
#include "render_loop.h"
#include "geometry.h"

int	close_mlx(t_window *win)
{
	mlx_loop_end(win->mlx);
	return (0);
}

void	create_win(t_window *win)
{
	win->win = mlx_new_window(win->mlx, win->width, win->height,
			win->title);
	mlx_hook(win->win, ClientMessage, KeyPressMask, close_mlx, win);
	mlx_hook(win->win, KeyPress, KeyPressMask, key_pressed, win);
	mlx_hook(win->win, KeyRelease, KeyReleaseMask, key_released, win);
	mlx_loop_hook(win->mlx, loop, win);
}

void	init_win_struct(t_window *win, int width, int height, char *title)
{
	win->height = 0;
	win->mlx = mlx_init();
	win->title = title;
	win->width = 0;
	win->win = NULL;
	win->width = width;
	win->height = height;
	win->fb.front = new_image(win->mlx, 800, 600);
	win->fb.back = new_image(win->mlx, 800, 600);
	win->camera = vec2d(0, 0);
	win->zoom = 32;
	win->amplitude = 1;
}

void	push_back_fb(void *mlx, void *win, t_fb	*fb, uint32_t clear_color)
{
	t_img	*tmp;

	tmp = fb->front;
	fb->front = fb->back;
	fb->back = tmp;
	mlx_put_image_to_window(mlx, win, fb->front->ptr, 0, 0);
	img_clear(fb->back, clear_color);
}
