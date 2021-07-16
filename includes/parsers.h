/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 16:52:07 by jberredj          #+#    #+#             */
/*   Updated: 2021/07/16 15:09:16 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSERS_H
# define PARSERS_H
# include "structs/t_window.h"

int	args_parser(int argc, char **argv, t_window *win);
void fdf_parser(int fd, t_window *win);
#endif