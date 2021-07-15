/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:37:11 by jberredj          #+#    #+#             */
/*   Updated: 2021/07/15 14:28:14 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include "mlx.h"
#include "mlx_utils.h"

void	img_pixel_put(t_img *data, int x, int y, uint32_t color)
{
	char	*dst;

	if (x >= 0 && x < data->width && y >= 0 && y < data->height)
	{
		dst = data->addr + (y * data->line_length + x
				* (data->bits_per_pixel / 8));
		*(uint32_t *)dst = color;
	}
}

t_img	*new_image(void *mlx, int width, int height)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (img == NULL)
		return (NULL);
	img->ptr = mlx_new_image(mlx, width, height);
	if (img->ptr == NULL)
	{
		free(img);
		return (NULL);
	}
	img->addr = mlx_get_data_addr(img->ptr, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	img->width = width;
	img->height = height;
	return (img);
}

uint32_t	get_color_from_mlx_img(t_img img, int x, int y)
{
	char	*dst;

	dst = img.addr + (y * img.line_length + x
			* (img.bits_per_pixel / 8));
	return (*(uint32_t *)dst);
}

t_img	*new_image_from_file(void *mlx, char *filename)
{
	t_img	*img;
	int		width;
	int		height;

	img = (t_img *)malloc(sizeof(t_img));
	if (img == NULL)
		return (NULL);
	img->ptr = mlx_xpm_file_to_image(mlx, filename, &width, &height);
	if (img->ptr == NULL)
	{
		free(img);
		return (NULL);
	}
	img->addr = mlx_get_data_addr(img->ptr, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	img->width = width;
	img->height = height;
	return (img);
}

void	free_img(void *mlx, t_img **img)
{
	t_img	*tofree;

	tofree = NULL;
	if (img != NULL)
		tofree = *img;
	if (tofree != NULL && tofree->ptr != NULL)
	{
		mlx_destroy_image(mlx, tofree->ptr);
		free(*img);
	}
	*img = NULL;
}
