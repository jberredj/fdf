/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 15:36:41 by jberredj          #+#    #+#             */
/*   Updated: 2021/09/20 11:17:28 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "error_code.h"
#include "structs/t_window.h"
#include "../libs/libft/includes/libft.h"
#include <math.h>
#include "exit.h"
#include "objects.h"
#include "geometry.h"
#include "parsers.h"

void	panic_gnl_out(int fd, int code, t_list **list, t_window *win)
{
	finish_read(fd, GNL_ERROR);
	free_coord_list(list);
	error_exit(code, win);
}

void	fdf_parser(int fd, t_window *win)
{
	char	*line;
	int		read_line;
	int		error;
	t_list	*y_list;

	y_list = NULL;
	read_line = 1;
	while (read_line == 1)
	{
		read_line = get_next_line(fd, &line);
		if (read_line == -1)
			panic_gnl_out(fd, GNL_ERROR, &y_list, win);
		if (*line != '\0')
			error = parse_line(line, &y_list);
		free(line);
		if (error)
			panic_gnl_out(fd, error, &y_list, win);
	}
	close(fd);
	error = create_mesh(&y_list, &win->objs);
	if (error)
		error_exit(error, win);
}
