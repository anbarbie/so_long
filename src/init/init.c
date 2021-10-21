/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 02:47:52 by user42            #+#    #+#             */
/*   Updated: 2021/10/21 18:41:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	init_struct(t_data *data)
{
	data->size_xpm = 70;
	data->i = 0;
	data->x = 0;
	data->map = NULL;
	data->width = data->size_xpm * 15;
	data->height = data->size_xpm * 10;
	data->wall = 0;
	data->img = 0;
}

void	xpm_to_image(t_data *data, t_img **img, char *path)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	*img = mlx_xpm_file_to_image(data->mlx_ptr, path, &width, &height);
	if (!(*img))
		(printf("mlx_xpm_file_to_image failed\n"));
	(*img)->width = width;
	(*img)->height = height;
	printf("width %d\n", width);
	printf("height %d\n", height);
}

void	init_xpm(t_data *data)
{
	xpm_to_image(data, &data->wall, "./images/ground.xpm");	
}

int init(t_data *data)
{
	init_struct(data);
    data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->width, data->height, "so_long");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return (1);
	}
	data->img = mlx_new_image(data->mlx_ptr, data->width, data->height);
	data->img->data = mlx_get_data_addr(data->img, &data->img->bpp, &data->img->size_line, &data->img->format);
	if (!data->img)
		return (1);
	init_xpm(data);
    return (0);
}
