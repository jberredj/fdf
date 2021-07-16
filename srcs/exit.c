/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:54:12 by jberredj          #+#    #+#             */
/*   Updated: 2021/07/15 17:11:44 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "error_code.h"
#include "structs/t_window.h"
#include "objects.h"
#include "../libs/libft/includes/libft.h"
#include "mlx_utils.h"
#include "mlx.h"

void	free_exit(t_window *win)
{
	mlx_destroy_image(win->mlx, win->fb.front->ptr);
	free(win->fb.front);
	mlx_destroy_image(win->mlx, win->fb.back->ptr);
	free(win->fb.back);
	if (win->win)
		mlx_destroy_window(win->mlx, win->win);
	mlx_destroy_display(win->mlx);
	free_3dobj(win->objs);
	free(win->mlx);
}

void	print_code_desc2(int code)
{
	if (code == MAP_INCORRECT)
		ft_putstr_fd("Map is incorrect\n", 2);
	else if (code == CANT_READ_FILE)
		ft_putstr_fd("Can\'t read file\n", 2);
	else if (code == FILE_NOT_DOT_FDF)
		ft_putstr_fd("File isn\'t a .fdf file\n", 2);
	else if (code == FILE_IS_DIR)
		ft_putstr_fd("File is a directory\n", 2);
	else if (code == INCORRECT_ORDER)
		ft_putstr_fd("Incorrect order\n", 2);
	else if (code == EMPTY_LINE_IN_MESH)
		ft_putstr_fd("Found an empty line while parsing mesh\n", 2);
	else if (code == MAP_TOO_SMALL)
		ft_putstr_fd("The map is too small to be playable\n", 2);
	else if (code == GNL_ERROR)
		ft_putstr_fd("get_next_line() could not read file until end\n", 2);
	else
		ft_putstr_fd("Unknown error\n", 2);
}

void	print_code_desc(int code)
{
	if (code == MALLOC_ERROR)
		ft_putstr_fd("Malloc error\n", 2);
	else if (code == INCORRECT_VALUE)
		ft_putstr_fd("Incorrect value\n", 2);
	else if (code == OUT_OF_RANGE)
		ft_putstr_fd("Out of range value\n", 2);
	else if (code == NOT_ENOUGH)
		ft_putstr_fd("Not enough element\n", 2);
	else if (code == TOO_MANY)
		ft_putstr_fd("Too many element\n", 2);
	else if (code == ALREADY_LOADED)
		ft_putstr_fd("Value can only be declared once\n", 2);
	else if (code == CANT_OPEN_FILE)
		ft_putstr_fd("Can't open file\n", 2);
	else if (code == INVALID_PARAMETER)
		ft_putstr_fd("Invalide parameter\n", 2);
	else if (code == MISSING_VALUE)
		ft_putstr_fd("Missing value\n", 2);
	print_code_desc2(code);
}

void	error_exit(int code, t_window *win)
{
	ft_putstr_fd("Error\nCode : ", 2);
	ft_putnbr_fd(-code, 2);
	ft_putstr_fd("\nCode description : ", 2);
	print_code_desc(code);
	ft_putstr_fd("\n", 2);
	free_exit(win);
	exit(-code);
}
