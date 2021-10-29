/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_etc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 21:40:22 by user42            #+#    #+#             */
/*   Updated: 2021/10/29 11:45:28 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

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
			{
				data->x_player = j;
				data->y_player = i;
				xpm_pix_put(data->player, data, j, i);
			}
			else if (data->map[i][j] == 'C')
				xpm_pix_put(data->sprite, data, j, i);
			else if (data->map[i][j] == 'Z')
				xpm_pix_put(data->player, data, j, i);
			j++;
		}
		i++;
	}
}
