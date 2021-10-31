/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_moves2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 04:53:25 by user42            #+#    #+#             */
/*   Updated: 2021/10/31 04:55:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	start_move(t_data *data)
{
	if (data->map[data->y_player][data->x_player] == 'Z')
		data->map[data->y_player][data->x_player] = 'E';
	else
		data->map[data->y_player][data->x_player] = '0';
}

void	end_move(t_data *data)
{
	if (data->map[data->y_player][data->x_player] == 'E')
		data->map[data->y_player][data->x_player] = 'Z';
	else
		data->map[data->y_player][data->x_player] = 'P';
}
