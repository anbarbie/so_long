/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 02:20:15 by user42            #+#    #+#             */
/*   Updated: 2021/10/21 18:32:31 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int main(void)
{
    t_data data;
    
    if (init(&data) == 1)
		return (1);

    mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
	
	mlx_destroy_image(data.mlx_ptr, data.img);
	mlx_destroy_image(data.mlx_ptr, data.wall);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}