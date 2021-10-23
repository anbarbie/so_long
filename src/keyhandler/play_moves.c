/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 21:23:42 by user42            #+#    #+#             */
/*   Updated: 2021/10/24 00:40:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	play_left(t_data *data)
{
	if (data->x_player > 0)
	{
		if (data->map[data->y_player][data->x_player - 1] != '1')
		{
			data->map[data->y_player][data->x_player] = '0';
			data->x_player--;
			data->map[data->y_player][data->x_player] = 'P';
		}
	}
}

void	play_right(t_data *data)
{
	if (data->x_player < data->x_map)
	{
		if (data->map[data->y_player][data->x_player + 1] != '1')
		{
			data->map[data->y_player][data->x_player] = '0';
			data->map[data->y_player][data->x_player + 1] = 'P';
			data->x_player++;
			data->map[data->y_player][data->x_player] = 'P';
		}
	}
}

void	play_up(t_data *data)
{
	if (data->y_player > 0)
	{
		if (data->map[data->y_player - 1][data->x_player] != '1')
		{
			data->map[data->y_player][data->x_player] = '0';
			data->y_player--;
			data->map[data->y_player][data->x_player] = 'P';
		}
	}
}

void	play_down(t_data *data)
{
	if (data->y_player < data->y_map)
	{
		if (data->map[data->y_player + 1][data->x_player] != '1')
		{
			data->map[data->y_player][data->x_player] = '0';
			data->y_player++;
			data->map[data->y_player][data->x_player] = 'P';
		}
	}
}
