/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_pix_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 20:53:16 by user42            #+#    #+#             */
/*   Updated: 2021/10/29 13:41:40 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	get_color_from_texture(t_img *img, int x, int y)
{
	return (*(int *)(img->data + (y * img->size_line + x * (img->bpp / 8))));
}

int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->data + (y * img->size_line + x * (img->bpp / 8));
	*(int *)pixel = color;
}

void	xpm_pix_put(t_img *img, t_data *data, int x, int y)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	x *= data->size_xpm;
	y *= data->size_xpm;
	while (i < data->size_xpm)
	{
		j = 0;
		while (j < data->size_xpm)
		{
			color = get_color_from_texture(img, j, i);
			if (color != encode_rgb(255, 255, 255))
				img_pix_put(data->img, j + x, i + y, color);
			j++;
		}
		i++;
	}
}
