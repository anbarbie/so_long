/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_etc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 21:40:22 by user42            #+#    #+#             */
/*   Updated: 2021/10/29 13:46:35 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	is_nearby(int i, int j, int x, int y)
{
	if ((i == x - 1) && (j == y - 1))
		return (1);
	else if ((i == x) && (j == y - 1))
		return (1);
	else if ((i == x + 1) && (j == y - 1))
		return (1);
	else if ((i == x - 1) && (j == y))
		return (1);
	else if ((i == x + 1) && (j == y))
		return (1);
	else if ((i == x - 1) && (j == y + 1))
		return (1);
	else if ((i == x) && (j == y + 1))
		return (1);
	else if ((i == x + 1) && (j == y + 1))
		return (1);
	else
		return (0);
}

void	render_coll(t_data *data, int x, int y)
{
	if (is_nearby(data->x_player, data->y_player, x, y))
		xpm_pix_put(data->sprite, data, x, y);
	else
		xpm_pix_put(data->sprite2, data, x, y);
}

void	render_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->y_map)
	{
		j = 0;
		while (j < data->x_map)
		{
			if (data->map[i][j] == '1')
				xpm_pix_put(data->wall, data, j, i);
			else
				xpm_pix_put(data->ground, data, j, i);
			j++;
		}
		i++;
	}
	j = 0;
	while (j < data->x_map)
	{
		xpm_pix_put(data->ground, data, j, i);
		j++;
	}
}

void	get_player_pos(t_data *data, int x, int y)
{
	data->x_player = x;
	data->y_player = y;
	xpm_pix_put(data->player, data, x, y);
}

void	render_items(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->y_map)
	{
		j = 0;
		while (j < data->x_map)
		{
			if (data->map[i][j] == 'E')
				xpm_pix_put(data->exit, data, j, i);
			else if (data->map[i][j] == 'P')
				get_player_pos(data, j, i);
			else if (data->map[i][j] == 'C')
				render_coll(data, j, i);
			else if (data->map[i][j] == 'G')
				get_gump_pos(data, j, i);
			else if (data->map[i][j] == 'Z')
				xpm_pix_put(data->player, data, j, i);
			j++;
		}
		i++;
	}
}
