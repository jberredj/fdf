/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:43:38 by jberredj          #+#    #+#             */
/*   Updated: 2021/09/20 12:32:19 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs/t_window.h"
#include "mlx.h"
#include "parsers.h"
#include "window.h"
#include "exit.h"

int	main(int argc, char **argv)
{
	t_window	win;
	int			fd;

	init_win_struct(&win, WIDTH, HEIGHT, "fdf");
	fd = args_parser(argc, argv, &win);
	fdf_parser(fd, &win);
	create_win(&win);
	mlx_loop(win.mlx);
	free_exit(&win);
	return (0);
}
