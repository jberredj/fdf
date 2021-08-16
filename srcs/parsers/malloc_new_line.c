/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_new_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 22:15:37 by jberredj          #+#    #+#             */
/*   Updated: 2021/08/16 12:47:33 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parsers.h"
#include "error_code.h"

static int	malloc_zs(t_load_line *elem)
{
	elem->zs = (double *)malloc(sizeof(double) * elem->nbr);
	if (!elem->zs)
	{
		free(elem);
		return (MALLOC_ERROR);
	}
	return (0);
}

static int	malloc_colors(t_load_line *elem)
{
	elem->colors = (uint32_t *)malloc(sizeof(uint32_t) * elem->nbr);
	if (!elem->colors)
	{
		free(elem->zs);
		free(elem);
		return (MALLOC_ERROR);
	}
	return (0);
}

static int	malloc_colors_loaded(t_load_line *elem)
{
	elem->color_loaded = (bool *)malloc(sizeof(bool) * elem->nbr);
	if (!elem->color_loaded)
	{
		free(elem->zs);
		free(elem->colors);
		free(elem);
		return (MALLOC_ERROR);
	}
	return (0);
}

int	malloc_new_line(t_load_line **new_line, int nbr)
{
	t_load_line	*elem;

	elem = (t_load_line *)malloc(sizeof(t_load_line));
	if (!elem)
		return (MALLOC_ERROR);
	elem->nbr = nbr;
	if (malloc_zs(elem))
		return (MALLOC_ERROR);
	if (malloc_colors(elem))
		return (MALLOC_ERROR);
	if (malloc_colors_loaded(elem))
		return (MALLOC_ERROR);
	elem->last_added = 0;
	*new_line = elem;
	return (0);
}
