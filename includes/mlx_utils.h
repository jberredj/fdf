/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:36:03 by jberredj          #+#    #+#             */
/*   Updated: 2021/07/15 11:58:49 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H
# include "structs/t_img.h"
# include "structs/t_vec.h"
# include "structs/t_window.h"
# include <stdint.h>
void		putImgOnImg(t_img toPut, t_img *dst, t_vec2d orig);
void		img_pixel_put(t_img *data, int x, int y, uint32_t color);
t_img		*new_image(void *mlx, int width, int height);
uint32_t	get_color_from_mlx_img(t_img img, int x, int y);
t_img		*new_image_from_file(void *mlx, char *filename);
void		free_img(void *mlx, t_img **img);
int			close_mlx(t_window *win);
void		img_clear(t_img *img, uint32_t color);
#endif