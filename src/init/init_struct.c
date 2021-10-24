/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 17:22:31 by user42            #+#    #+#             */
/*   Updated: 2021/10/24 05:15:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	init_struct(t_data *data)
{
	data->i = 0;
	data->x = 0;
	data->cpt_exit = 0;
	data->cpt_sprite = 0;
	data->cpt_moves = 0;
	data->x_player = 0;
	data->y_player = 0;
	data->size_xpm = 32;
	data->map = NULL;
	data->img = NULL;
	data->wall = NULL;
	data->player = NULL;
	data->exit = NULL;
	data->ground = NULL;
	data->sprite = NULL;
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
}

void	init_struct_parsing(t_data *data)
{
	data->y_map = data->x;
	data->x_map = ft_strlen(data->map[0]);
	data->width = data->x_map * data->size_xpm;
	data->height = data->y_map * data->size_xpm;
}