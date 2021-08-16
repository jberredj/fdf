/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:54:29 by jberredj          #+#    #+#             */
/*   Updated: 2021/08/16 12:41:53 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include "../libs/libft/includes/libft.h"
#include "error_code.h"
#include "parsers.h"

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

int	ft_compare_base(char *str, char *base)
{
	size_t	base_len;
	size_t	str_len;
	int		i;
	int		j;

	base_len = check_base(base);
	if (base_len < 2)
		return (-1);
	str_len = ft_strlen(str);
	i = -1;
	while (++i < (int)str_len)
	{
		j = -1;
		while (str[i] != base[++j] && j < (int)base_len)
		{
		}
		if (!base[j])
			return (-1);
	}
	return (0);
}

int	check_loaded(t_list *y_list, t_vec2i *mesh_size)
{
	t_load_line	content;

	mesh_size->y = ft_lstsize(y_list);
	if (!y_list->content)
		return (MISSING_VALUE);
	content = *(t_load_line *)y_list->content;
	mesh_size->x = content.nbr;
	y_list = y_list->next;
	while (y_list)
	{
		if (!y_list->content)
			return (MISSING_VALUE);
		content = *(t_load_line *)y_list->content;
		if (content.nbr != mesh_size->x)
			return (INCORRECT_VALUE);
		y_list = y_list->next;
	}
	return (0);
}

bool	init_list(t_list **list)
{
	*list = ft_lstnew(NULL);
	if (!*list)
		return (false);
	return (true);
}
