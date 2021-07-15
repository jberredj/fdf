/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:09:24 by jberredj          #+#    #+#             */
/*   Updated: 2021/07/15 14:18:00 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "structs/t_window.h"
#include "qwerty.h"

void	mesh_orientation(int keycode, t_window *win)
{
	if (keycode == KEY_LEFT)
		win->objs->orient.y -= 0.1;
	if (keycode == KEY_RIGHT)
		win->objs->orient.y += 0.1;
	if (keycode == KEY_UP)
		win->objs->orient.x -= 0.1;
	if (keycode == KEY_DOWN)
		win->objs->orient.x += 0.1;
	if (keycode == KEY_NUM_9)
		win->objs->orient.z += 0.1;
	if (keycode == KEY_NUM_1)
		win->objs->orient.z -= 0.1;
}

void	mesh_position_and_zoom(int keycode, t_window *win)
{
	if (keycode == KEY_A)
		win->camera.x++;
	if (keycode == KEY_D)
		win->camera.x--;
	if (keycode == KEY_W)
		win->camera.y++;
	if (keycode == KEY_S)
		win->camera.y--;
	if (keycode == KEY_NUM_PLUS)
		win->zoom++;
	if (keycode == KEY_NUM_MINUS)
		win->zoom--;
}

int	key_pressed(int keycode, t_window *win)
{
	mesh_orientation(keycode, win);
	mesh_position_and_zoom(keycode, win);
	if (keycode == KEY_MINUS)
		win->amplitude += 0.1;
	if (keycode == KEY_EQUAL)
		win->amplitude -= 0.1;
	return (0);
}

int	key_released(int keycode, t_window *win)
{
	return (0);
}
