/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 16:42:43 by jberredj          #+#    #+#             */
/*   Updated: 2021/07/16 15:13:13 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include "../libs/libft/includes/libft.h"
#include "structs/t_window.h"
#include "error_code.h"
#include "exit.h"

int	check_fdf_file(char *file)
{
	int		fd;
	char	*check_ext;

	check_ext = ft_strrchr(file, '.');
	if (check_ext == NULL)
		return (FILE_NOT_DOT_FDF);
	if (!ft_strnstr(check_ext, ".fdf", ft_strlen(check_ext)))
		return (FILE_NOT_DOT_FDF);
	fd = open(file, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		return (FILE_IS_DIR);
	}
	fd = open(file, O_RDONLY);
	if (fd != -1)
		return (fd);
	return (CANT_OPEN_FILE);
}

int	parse_arg(int argc, char **argv)
{
	int	fd;

	if (argc < 2)
		return (MISSING_VALUE);
	if (argc > 2)
		return (TOO_MANY);
	fd = check_fdf_file(argv[1]);
	return (fd);
}

int args_parser(int argc, char **argv, t_window *win)
{
	int error;

	error = parse_arg(argc, argv);
	if (error >= 0)
		return (error);
	error_exit(error, win);
	return (0);
}