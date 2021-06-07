/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:45:18 by jberredj          #+#    #+#             */
/*   Updated: 2021/06/07 15:49:37 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H
#include "structs/t_window.h"
int		close_mlx(t_window *win);
void	create_win(t_window *win);
void	init_win_struct(t_window *win, char *title);
void	free_exit(t_window *win);
#endif