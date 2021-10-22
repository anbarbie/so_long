/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_etc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 21:40:22 by user42            #+#    #+#             */
/*   Updated: 2021/10/22 03:56:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	render_map(t_data *data)
{
	int	i;
	int j;
	int	x;
	int	y;

	i = 0;
	x = 0;
	while ((i + x) < data->height)
	{
		j = 0;
		y = 0;
		while ((j + y) < data->width)
		{
			if ((j == 0) || (j == 14) ||
			(i == 0) || (i == 9))
				xpm_pix_put(data->wall, data, j, i);
			else
				xpm_pix_put(data->ground, data, j, i);
			j++;
			y += data->size_xpm;
		}
		x += data->size_xpm;
		i++;
	}	
}

void	render_items(t_data *data)
{
	static int i = 0;

	xpm_pix_put(data->player, data, 4, 4);
	
	if (i == 0)
	{
		xpm_pix_put(data->sprite, data, 6, 6);
		i = 1;
	}
	else
	{
		xpm_pix_put(data->sprite2, data, 6, 6);
		i = 0;
	}
	xpm_pix_put(data->exit, data, 8, 8);
}
