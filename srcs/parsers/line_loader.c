/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_loader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:35:15 by jberredj          #+#    #+#             */
/*   Updated: 2021/08/16 12:44:34 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/libft/includes/libft.h"
#include "error_code.h"
#include "parsers.h"

int	selector(char **coord_strs, t_load_line *new_line, int line_size)
{
	int			i;
	char		*comma_location;
	int			error;

	i = -1;
	while (++i < line_size)
	{
		comma_location = ft_strrchr(coord_strs[i], ',');
		if (comma_location)
		{
			*comma_location = '\0';
			error = load_coord_col(coord_strs[i], comma_location + 1, new_line);
		}
		else
			error = load_coord(coord_strs[i], new_line);
		if (error)
		{
			free_load_line(new_line);
			return (error);
		}
	}
	return (0);
}

int	line_loader_selector(char **coord_strs, t_list **coord_list)
{
	t_load_line	*new_line;
	int			error;
	int			line_size;
	t_list		*new_elem;

	line_size = ft_split_size(coord_strs);
	if (malloc_new_line(&new_line, line_size))
		return (MALLOC_ERROR);
	new_elem = ft_lstnew(new_line);
	if (!new_elem)
		return (MALLOC_ERROR);
	error = selector(coord_strs, new_line, line_size);
	if (error)
		return (error);
	ft_lstadd_back(coord_list, new_elem);
	return (0);
}

int	parse_line(char	*line, t_list **y_list)
{
	char	**coord;
	int		error;

	coord = ft_split(line, ' ');
	if (!coord)
		return (MALLOC_ERROR);
	error = line_loader_selector(coord, y_list);
	ft_free_split(coord, ft_split_size(coord));
	if (error)
		return (error);
	return (0);
}
