/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 02:47:52 by user42            #+#    #+#             */
/*   Updated: 2021/10/29 14:13:20 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

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
}

void	init_xpm_bonus(t_data *data)
{
	xpm_to_image(data, &data->zero, "./images/0.xpm");
	xpm_to_image(data, &data->one, "./images/1.xpm");
	xpm_to_image(data, &data->two, "./images/2.xpm");
	xpm_to_image(data, &data->three, "./images/3.xpm");
	xpm_to_image(data, &data->four, "./images/4.xpm");
	xpm_to_image(data, &data->five, "./images/5.xpm");
	xpm_to_image(data, &data->six, "./images/6.xpm");
	xpm_to_image(data, &data->seven, "./images/7.xpm");
	xpm_to_image(data, &data->eight, "./images/8.xpm");
	xpm_to_image(data, &data->nine, "./images/9.xpm");
	xpm_to_image(data, &data->sprite2, "./images/block.xpm");
	xpm_to_image(data, &data->ennemy, "./images/gumpa.xpm");
}

void	init_xpm(t_data *data)
{
	xpm_to_image(data, &data->wall, "./images/wall.xpm");
	xpm_to_image(data, &data->player, "./images/mario.xpm");
	xpm_to_image(data, &data->exit, "./images/exit.xpm");
	xpm_to_image(data, &data->ground, "./images/ground.xpm");
	xpm_to_image(data, &data->sprite, "./images/shroom.xpm");
	init_xpm_bonus(data);
}

int	init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		exit_message(data, "mlx_init failed");
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->width,
			data->height, "so_long");
	if (data->win_ptr == NULL)
		exit_message(data, "mlx_new_window failed");
	data->img = mlx_new_image(data->mlx_ptr, data->width, data->height);
	if (!data->img)
		exit_message(data, "mlx_new_image failed");
	init_xpm(data);
	return (0);
}
