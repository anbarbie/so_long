/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_enabled.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 00:40:30 by user42            #+#    #+#             */
/*   Updated: 2021/10/29 13:36:06 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	check_sprite(t_data *data)
{
	int	i;
	int	j;
	int	cpt;

	i = 0;
	cpt = 0;
	while (i < data->y_map)
	{
		j = 0;
		while (j < data->x_map)
		{
			if (data->map[i][j] == 'C')
				cpt++;
			j++;
		}
		i++;
	}
	return (cpt);
}

int	check_death(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->y_map)
	{
		j = 0;
		while (j < data->x_map)
		{
			if (data->map[i][j] == 'P' || data->map[i][j] == 'Z')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_it_solved(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->y_map)
	{
		j = 0;
		while (j < data->x_map)
		{
			if (data->map[i][j] == 'Z')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	check_exit(t_data *data)
{
	if ((check_death(data)))
	{
		printf("Game over!\n");
		exit_success(data);
	}
	else if (!(check_sprite(data)))
	{
		if (is_it_solved(data))
			exit_success(data);
	}
}
