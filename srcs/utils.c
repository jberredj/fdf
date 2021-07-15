/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 11:50:15 by jberredj          #+#    #+#             */
/*   Updated: 2021/07/15 12:18:09 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	percent(int min, int max, int current)
{
	double	position;
	double	size;

	position = current - min;
	size = max - min;
	if (size == 0)
		return (1.0);
	else
		return (position / size);
}
