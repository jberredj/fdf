/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 10:40:48 by jberredj          #+#    #+#             */
/*   Updated: 2021/07/15 11:51:20 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H
#include <stdint.h>

int		ft_abs(int nbr);
void	ft_swap(uint64_t *a, uint64_t *b);
int		check_base(char *str);
#endif
