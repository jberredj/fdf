/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 10:58:53 by jberredj          #+#    #+#             */
/*   Updated: 2021/07/15 13:31:29 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs/t_vec.h"
#include "../libs/libft/includes/libft.h"

t_vec3i	vec3i(int x, int y, int z)
{
	return ((t_vec3i){x, y, z});
}

t_vec3d	vec3d(double x, double y, double z)
{
	return ((t_vec3d){x, y, z});
}

t_vec3i	*vec3i_new(int x, int y, int z)
{
	t_vec3i	*ptr;

	ptr = (t_vec3i *)ft_calloc(1, sizeof(t_vec3i));
	if (!ptr)
		return (NULL);
	*ptr = vec3i(x, y, z);
	return (ptr);
}

t_vec3d	*vec3d_new(double x, double y, double z)
{
	t_vec3d	*ptr;

	ptr = (t_vec3d *)ft_calloc(1, sizeof(t_vec3d));
	if (!ptr)
		return (NULL);
	*ptr = vec3d(x, y, z);
	return (ptr);
}
