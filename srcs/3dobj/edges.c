/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edges.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 13:18:22 by jberredj          #+#    #+#             */
/*   Updated: 2021/07/15 13:22:07 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "structs/t_3dobj.h"

t_edge	*new_edge(int a, int b)
{
	t_edge	*edge;

	edge = (t_edge *)malloc(sizeof(t_edge));
	if (!edge)
		return (NULL);
	edge->a = a;
	edge->b = b;
	return (edge);
}

t_edge	set_edge(int a, int b)
{
	return ((t_edge){.a = a, .b = b});
}
