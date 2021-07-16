/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyreleased_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 16:03:28 by jberredj          #+#    #+#             */
/*   Updated: 2021/07/15 16:19:41 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "structs/t_window.h"
#include "qwerty.h"

static	void	mesh_orientation(int keycode, t_key *flags)
{
	if (keycode == KEY_LEFT)
		flags->roty = 0;
	if (keycode == KEY_RIGHT)
		flags->roty = 0;
	if (keycode == KEY_UP)
		flags->rotx = 0;
	if (keycode == KEY_DOWN)
		flags->rotx = 0;
	if (keycode == KEY_NUM_9)
		flags->rotz = 0;
	if (keycode == KEY_NUM_1)
		flags->rotz = 0;
	if (keycode == KEY_R)
		flags->reset_cam = false;
	if (keycode == KEY_C)
		flags->reset_pos = false;
}

static	void	mesh_position_and_zoom(int keycode, t_key *flags)
{
	if (keycode == KEY_A)
		flags->movex = 0;
	if (keycode == KEY_D)
		flags->movex = 0;
	if (keycode == KEY_W)
		flags->movey = 0;
	if (keycode == KEY_S)
		flags->movey = 0;
	if (keycode == KEY_NUM_PLUS)
		flags->zoom = 0;
	if (keycode == KEY_NUM_MINUS)
		flags->zoom = 0;
}

int	key_released(int keycode, t_window *win)
{
	mesh_orientation(keycode, &win->flags);
	mesh_position_and_zoom(keycode, &win->flags);
	if (keycode == KEY_MINUS)
		win->flags.amplitude = 0;
	if (keycode == KEY_EQUAL)
		win->flags.amplitude = 0;
	return (0);
}