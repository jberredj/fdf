/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:43:38 by jberredj          #+#    #+#             */
/*   Updated: 2021/06/07 16:01:34 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "structs/t_window.h"
#include "mlx_utils.h"
#include "window.h"

int	loop(t_window *win)
{
	return (0);
}


int	main(int argc, char **argv)
{
	t_window	win;
	init_win_struct(&win, "fdf");
	win.width = 800;
	win.height = 600;
	create_win(&win);
	mlx_loop_hook(win.mlx, loop, &win);
	mlx_loop(win.mlx);
	free_exit(&win);
	
	return (0);
}