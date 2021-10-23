/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_etc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 21:40:22 by user42            #+#    #+#             */
/*   Updated: 2021/10/23 05:18:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	render_map(t_data *data)
{
	int	i;
	int	j;
	
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
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
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'E')
				xpm_pix_put(data->exit, data, j, i);
			if (data->map[i][j] == 'P')
				xpm_pix_put(data->player, data, j, i);
			if (data->map[i][j] == 'C')
				xpm_pix_put(data->sprite, data, j, i);
			j++;
		}
		i++;
	}
}
