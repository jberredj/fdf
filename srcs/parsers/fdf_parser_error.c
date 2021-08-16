/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parser_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:32:58 by jberredj          #+#    #+#             */
/*   Updated: 2021/08/16 11:51:42 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parsers.h"
#include "../libs/libft/includes/ft_lst.h"
#include "structs/t_3dobj.h"

void	free_load_line(void	*elem)
{
	t_load_line	*elem_cast;

	if (!elem)
		return ;
	elem_cast = (t_load_line *)elem;
	if (elem_cast->zs)
		free(elem_cast->zs);
	if (elem_cast->colors)
		free(elem_cast->colors);
	if (elem_cast->color_loaded)
		free(elem_cast->color_loaded);
	free(elem);
}

void	free_coord_list(t_list **list)
{
	ft_lstclear(list, free_load_line);
}

t_face	*error_faces(t_face **faces, int nbr)
{
	int	i;

	i = -1;
	while (++i < nbr)
		free((*faces)[i].edges);
	free(*faces);
	return (NULL);
}

int	error_free_coord_list(int code, t_list **coord)
{
	free_coord_list(coord);
	return (code);
}

int	error_free(int code, void *ptr)
{
	free(ptr);
	return (code);
}
