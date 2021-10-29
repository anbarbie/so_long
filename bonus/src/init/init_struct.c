/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 17:22:31 by user42            #+#    #+#             */
/*   Updated: 2021/10/29 14:14:28 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	init_struct_bonus(t_data *data)
{
	data->sprite2 = 0;
	data->ennemy = 0;
	data->zero = 0;
	data->one = 0;
	data->two = 0;
	data->three = 0;
	data->four = 0;
	data->five = 0;
	data->six = 0;
	data->seven = 0;
	data->eight = 0;
	data->nine = 0;
	data->pos->x_gump = malloc(sizeof(int) * data->cpt_gump);
	if (!(data->pos->x_gump))
		exit_message(data, "malloc x_gump fail");
	data->pos->y_gump = malloc(sizeof(int) * data->cpt_gump);
	if (!(data->pos->y_gump))
		exit_message(data, "malloc y_gump fail");
	data->pos->b = malloc(sizeof(int) * data->cpt_gump);
	if (!(data->pos->b))
		exit_message(data, "malloc b fail");
}

void	init_struct(t_data *data)
{
	data->x = 0;
	data->x_player = 0;
	data->y_player = 0;
	data->cpt_exit = 0;
	data->cpt_sprite = 0;
	data->cpt_moves = 0;
	data->cpt_gump = 0;
	data->map = NULL;
	data->pos = malloc(sizeof(struct s_pos));
	if (data->pos == NULL)
		exit_message(data, "malloc struct failed");
}

void	init_struct_parsing(t_data *data)
{
	static int	i = 0;

	data->size_xpm = 32;
	data->y_map = data->x;
	data->x_map = ft_strlen(data->map[0]);
	data->width = data->x_map * data->size_xpm;
	data->height = (data->y_map + 1) * data->size_xpm;
	data->img = 0;
	data->wall = 0;
	data->player = 0;
	data->exit = 0;
	data->ground = 0;
	data->sprite = 0;
	init_struct_bonus(data);
	while (i < data->cpt_gump)
	{
		data->pos->b[i] = 0;
		i++;
	}
	init(data);
}
