/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_argb.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 17:37:11 by jberredj          #+#    #+#             */
/*   Updated: 2021/06/07 17:38:00 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_ARGB_H
# define T_ARGB_H
# include <stdint.h>
typedef	struct s_argb
{
	uint8_t	a;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
}			t_argb;
#endif