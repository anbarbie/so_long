/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 02:20:15 by user42            #+#    #+#             */
/*   Updated: 2021/10/31 03:10:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	free_bonus(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->zero);
	mlx_destroy_image(data->mlx_ptr, data->one);
	mlx_destroy_image(data->mlx_ptr, data->two);
	mlx_destroy_image(data->mlx_ptr, data->three);
	mlx_destroy_image(data->mlx_ptr, data->four);
	mlx_destroy_image(data->mlx_ptr, data->five);
	mlx_destroy_image(data->mlx_ptr, data->six);
	mlx_destroy_image(data->mlx_ptr, data->seven);
	mlx_destroy_image(data->mlx_ptr, data->eight);
	mlx_destroy_image(data->mlx_ptr, data->nine);
	mlx_destroy_image(data->mlx_ptr, data->sprite2);
	mlx_destroy_image(data->mlx_ptr, data->ennemy);
}

void	so_long_hooks(t_data *data)
{
	init_struct_parsing(data);
	mlx_loop_hook(data->mlx_ptr, update, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, handle_keypress, data);
	mlx_hook(data->win_ptr, ClientMessage, StructureNotifyMask,
		exit_cross, data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img);
	mlx_destroy_image(data->mlx_ptr, data->wall);
	mlx_destroy_image(data->mlx_ptr, data->player);
	mlx_destroy_image(data->mlx_ptr, data->exit);
	mlx_destroy_image(data->mlx_ptr, data->ground);
	mlx_destroy_image(data->mlx_ptr, data->sprite);
	free_bonus(data);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}

int	main(int ac, char **av)
{
	t_data	data;

	init_struct(&data);
	if (ac != 2)
		exit_message(&data, "Wrong number of arg");
	else
	{
		check_format(&data, av[1]);
		so_long_hooks(&data);
	}
	return (0);
}
