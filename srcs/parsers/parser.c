/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 15:36:41 by jberredj          #+#    #+#             */
/*   Updated: 2021/07/10 17:19:13 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "error_code.h"
#include "structs/t_window.h"
#include "../libs/libft/includes/libft.h"



bool	check_value(char *str, bool point)
{
	if (str == NULL)
		return (false);
	while (*str)
	{
		if (!ft_isdigit(*str) && *str != '-' && *str != '+')
		{
			if (point == true && *str == '.')
			{
				str++;
				continue ;
			}
			return (false);
		}
		str++;
	}
	return (true);
}

int parse_raw_map(char *line, char **rawmap)
{
	char	*new_rawmap;

	new_rawmap = ft_strjoin_free(*rawmap, line);
	if (new_rawmap == NULL)
		return (MALLOC_ERROR);
	*rawmap = ft_strjoin_free(new_rawmap, "\n");
	if (*rawmap == NULL)
		return (MALLOC_ERROR);
	return (0);
}

int	parser_selector(t_window *win, char *line, char **rawmap)
{
	char	**split;
	int 	error;

	if (is_in(line, (char *[]){"R", "NO", "SO", "WE", "EA", "S", "F", "C"}, 8))
	{
		if (ft_strlen(*rawmap) == 1)
		{
			split = NULL;
			split = ft_split(line, ' ');
			if (split == NULL)
				return (MALLOC_ERROR);
			error = parameters_parser(win, split);
			ft_free_split(split, ft_split_size(split));
		}
		else
			return (INCORRECT_ORDER);
	}
	else 
		error = parse_raw_map(line, rawmap);
	return (error);
}

int		longuest_line(char **split, size_t size)
{
	int i;
	size_t	longuest;
	size_t	current;

	longuest = 0;
	i = -1;
	while (++i < (int)size)
	{
		current = ft_strlen(split[i]);
		if (current > longuest)
			longuest = current;
	}
	return (longuest);
}

int	create_map_from_raw(t_map *map, char *raw)
{
	char	**split;
	int 	x;
	int		y;
	size_t	len;

	split = ft_split(raw, '\n');
	if (split == NULL)
		return (MALLOC_ERROR);
	map->y = ft_split_size(split);
	map->x = longuest_line(split, map->y);
	map->grid = new_map_grid(map->x, map->y);
	if (map->grid == NULL)
	{
		ft_free_split(split, ft_split_size(split));
		return (MALLOC_ERROR);
	}
	y = -1;
	while (++y < map->y)
	{
		x = -1;
		len = ft_strlen(split[y]);
		while (++x < map->x)
		{
			if (x < (int)len)
				map->grid[x][y] = (int)split[y][x];
			else
				map->grid[x][y] = ' ';
		}
	}
	ft_free_split(split, ft_split_size(split));
	return (0);
}

int	finish_read(int fd, int code)
{
	int		read_line;
	char	*line;

	read_line = 1;
	while (read_line)
	{
		read_line = get_next_line(fd, &line);
		free(line);
		line = NULL;
	}
	
	return (code);
}

int	read_fdf_file(t_window *win, int fd, char **raw_map)
{
	char	*line;
	int		read_line;
	int 	error;
	bool	empty_in_map;

	read_line = 1;
	line = NULL;
	empty_in_map = false;
	while (read_line)
	{
		read_line = get_next_line(fd, &line);
		if (empty_in_map && *line != '\0')
			return (EMPTY_LINE_IN_MESH);
		if (read_line == -1)
			return (CANT_READ_FILE);
		if (*line != '\0')
			error = parser_selector(win, line, raw_map);
		else if (ft_strlen(*raw_map) > 1)
			empty_in_map = true;
		free(line);
		line = NULL;
		if (error < 0)
			return(finish_read(fd, error));
	}
	return (0);
}

void fdf_parser(int fd)
{
	char	*raw_map;
	int 	error;

	raw_map = ft_calloc(2, sizeof(char));
	if (raw_map == NULL)
		return (MALLOC_ERROR);
	raw_map[0] = '\n';
	error = read_fdf_file(win, fd, &raw_map);
	close(fd);
	if (error < 0)
	{
		free(raw_map);
		error_exit(error, NULL, "Cub file parser", win);
	}
	error = create_map_from_raw(&win->game.map, raw_map);
	free(raw_map);
	if (error < 0)
		error_exit(error, NULL, "Map loader", win);
	win->game.map.img = new_image(win->mlx, win->game.map.x * TILE_SIZE,
					win->game.map.y * TILE_SIZE);
	if (win->game.map.img == NULL)
		error_exit(MALLOC_ERROR, "Can\'t malloc map img", "Cub file parser", win);
	return (0);
}