/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 02:20:15 by user42            #+#    #+#             */
/*   Updated: 2021/10/23 03:23:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int main(int ac, char **av)
{
    t_data data;
    
	if (ac != 2)
		exit_message(&data, "Wrong number of arg");
    if (init(&data) == 1)
		return (1);

	read_ber(&data, av[1]);
	printf("%s\n", data.map[0]);
	printf("%s\n", data.map[1]);
	printf("%s\n", data.map[2]);
    mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
	
	mlx_destroy_image(data.mlx_ptr, data.img);
	mlx_destroy_image(data.mlx_ptr, data.wall);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}