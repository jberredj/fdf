/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_loaders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:37:02 by jberredj          #+#    #+#             */
/*   Updated: 2021/08/16 12:37:16 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "../libs/libft/includes/libft.h"
#include "error_code.h"
#include "parsers.h"

void	ft_str_toupper(char *str)
{
	while (*str)
	{
		*str = ft_toupper(*str);
		str++;
	}
}

int	load_coord_col(char *coord, char *color, t_load_line *new_line)
{
	if (!check_value(coord, true))
		return (INCORRECT_VALUE);
	ft_str_toupper(color);
	if (ft_compare_base(color + 2, "0123456789ABCDEF"))
		return (INCORRECT_VALUE);
	new_line->zs[new_line->last_added] = ft_atof(coord);
	new_line->colors[new_line->last_added] = ft_atoui32_base(color + 2,
			"0123456789ABCDEF");
	new_line->color_loaded[new_line->last_added] = true;
	new_line->last_added++;
	return (0);
}

int	load_coord(char *coord, t_load_line *new_line)
{
	if (!check_value(coord, true))
		return (INCORRECT_VALUE);
	new_line->zs[new_line->last_added] = ft_atof(coord);
	new_line->color_loaded[new_line->last_added] = false;
	new_line->last_added++;
	return (0);
}
