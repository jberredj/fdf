/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:45:18 by jberredj          #+#    #+#             */
/*   Updated: 2021/09/16 18:07:16 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H
# include "structs/t_window.h"

int		close_mlx(t_window *win);
void	create_win(t_window *win);
void	init_win_struct(t_window *win, int width, int height, char *title);
void	free_exit(t_window *win);
int		key_pressed(int keycode, t_window *win);
int		key_released(int keycode, t_window *win);
void	push_back_fb(void *mlx, void *win, t_fb	*fb, uint32_t clear_color);
#endif