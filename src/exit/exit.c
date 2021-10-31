/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 19:46:46 by user42            #+#    #+#             */
/*   Updated: 2021/10/24 04:54:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	exit_message(t_data *data, char *s)
{
	free_map(data->map);
	printf("Error\n%s\n", s);
	exit(1);
}

void	exit_success(t_data *data)
{
	free_map(data->map);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
}

int	exit_cross(t_data *data)
{
	exit_success(data);
	return (0);
}
