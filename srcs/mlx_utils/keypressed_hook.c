/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypressed_hook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:09:24 by jberredj          #+#    #+#             */
/*   Updated: 2021/07/16 16:02:31 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "structs/t_window.h"
#include "qwerty.h"

static	void	mesh_orientation(int keycode, t_key *flags)
{
	if (keycode == KEY_LEFT)
		flags->roty = -1;
	if (keycode == KEY_RIGHT)
		flags->roty = 1;
	if (keycode == KEY_UP)
		flags->rotx = -1;
	if (keycode == KEY_DOWN)
		flags->rotx = 1;
	if (keycode == KEY_NUM_9)
		flags->rotz = 1;
	if (keycode == KEY_NUM_1)
		flags->rotz = -1;
	if (keycode == KEY_R)
		flags->reset_cam = true;
	if (keycode == KEY_C)
		flags->reset_pos = true;
}

static	void	mesh_position_and_zoom(int keycode, t_key *flags)
{
	if (keycode == KEY_A)
		flags->movex = 1;
	if (keycode == KEY_D)
		flags->movex = -1;
	if (keycode == KEY_W)
		flags->movey = 1;
	if (keycode == KEY_S)
		flags->movey = -1;
	if (keycode == KEY_NUM_PLUS)
		flags->zoom = 1;
	if (keycode == KEY_NUM_MINUS)
		flags->zoom = -1;
}

#include <stdio.h>

int	key_pressed(int keycode, t_window *win)
{
	mesh_orientation(keycode, &win->flags);
	mesh_position_and_zoom(keycode, &win->flags);
	if (keycode == KEY_MINUS)
		win->flags.amplitude = -1;
	if (keycode == KEY_EQUAL)
		win->flags.amplitude = 1;
	if (keycode == KEY_P)
		printf("position :\t%f\t%f\t%f\norientation :\t%f\t%f\t%f\n", win->camera.x, win->camera.y, win->zoom, win->objs->orient.x, win->objs->orient.y, win->objs->orient.z);
	return (0);
}
