/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 17:22:31 by user42            #+#    #+#             */
/*   Updated: 2021/10/29 12:53:13 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	init_struct(t_data *data)
{
	data->x = 0;
	data->x_player = 0;
	data->y_player = 0;
	data->cpt_exit = 0;
	data->cpt_sprite = 0;
	data->cpt_moves = 0;
	data->map = NULL;
}

void	init_struct_parsing(t_data *data)
{
	data->size_xpm = 32;
	data->y_map = data->x;
	data->x_map = ft_strlen(data->map[0]);
	data->width = data->x_map * data->size_xpm;
	data->height = data->y_map * data->size_xpm;
	data->img = 0;
	data->wall = 0;
	data->player = 0;
	data->exit = 0;
	data->ground = 0;
	data->sprite = 0;
	init(data);
}
