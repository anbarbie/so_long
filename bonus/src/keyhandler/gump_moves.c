/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gump_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:53:00 by user42            #+#    #+#             */
/*   Updated: 2021/11/01 04:14:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	get_gump_pos(t_data *data, int x, int y)
{
	static int	i = 0;

	if (i < data->cpt_gump)
	{
		data->pos->x_gump[i] = x;
		data->pos->y_gump[i] = y;
		xpm_pix_put(data->ennemy, data, x, y);
		i++;
	}
	if (i == data->cpt_gump)
		i = 0;
}

int	gump_stomp(char c)
{
	if (c == '0' || c == 'P')
		return (1);
	return (0);
}

int	gump_obstacle(char c)
{
	if (c == '1' || c == 'C' || c == 'E'
		|| c == 'G')
		return (1);
	else
		return (0);
}

void	gump_patrol(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->cpt_gump)
	{
		if ((gump_obstacle(data->map[data->pos->y_gump[i]]
					[data->pos->x_gump[i] - 1])))
			data->pos->b[i] = 1;
		if ((gump_obstacle(data->map[data->pos->y_gump[i]]
					[data->pos->x_gump[i] + 1])))
			data->pos->b[i] = 0;
		if ((gump_stomp(data->map[data->pos->y_gump[i]]
					[data->pos->x_gump[i] - 1])) && data->pos->b[i] == 0)
		{
			data->map[data->pos->y_gump[i]][data->pos->x_gump[i] - 1] = 'G';
			data->map[data->pos->y_gump[i]][data->pos->x_gump[i]] = '0';
		}
		if ((gump_stomp(data->map[data->pos->y_gump[i]]
					[data->pos->x_gump[i] + 1])) && data->pos->b[i] == 1)
		{
			data->map[data->pos->y_gump[i]][data->pos->x_gump[i] + 1] = 'G';
			data->map[data->pos->y_gump[i]][data->pos->x_gump[i]] = '0';
		}
		i++;
	}
}
