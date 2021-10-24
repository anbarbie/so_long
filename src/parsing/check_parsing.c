/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 04:03:19 by user42            #+#    #+#             */
/*   Updated: 2021/10/24 06:09:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	check_map_is_rec(t_data *data)
{
	int	i;
	int	a;
	int	b;

	i = 1;
	while (i < data->x)
	{
		a = ft_strlen(data->map[i - 1]);
		b = ft_strlen(data->map[i]);
		if (a != b)
			exit_message(data, "Map is not rectangle");
		i++;
	}
}

void	check_map_is_closed(t_data *data)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < data->y_map)
	{
		j = 0;
		while (j < data->x_map)
		{
			if (((i == 0) && (data->map[i][j] != '1')) || ((i == data->y_map - 1) &&
				(data->map[i][j] != '1')) || ((j == 0) && (data->map[i][j] != '1')) ||
				((i == data->x_map - 1) && (data->map[i][j] != '1')))
				exit_message(data, "Map is not closed");
			j++;
		}
		i++;
	}
}

int	check_content(char s)
{	
	if (s != '0' && s != '1' && s != 'C' && s != 'E' && s != 'P')
		return (1);
	return (0);
}

void	check_map_content(t_data *data, int	e, int p, int c)
{
	int	i;
	int j;
	

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (check_content(data->map[i][j]))
				exit_message(data, "Map : Wrong characters");
			if (data->map[i][j] == 'E')
			{
				e++;
				data->cpt_exit++;
			}
			if (data->map[i][j] == 'P')
				p++;
			if (data->map[i][j] == 'C')
			{
				c++;
				data->cpt_sprite++;
			}
			j++;
		}
		i++;		
	}
	if (e == 0 || p != 1 || c == 0)
		exit_message(data, "Map : Content not solvable");
}

void	check_map(t_data *data)
{
	static int	e = 0;
	static int	p = 0;
	static int	c = 0;

	check_map_is_rec(data);
	check_map_is_closed(data);
	check_map_content(data, e, p, c);
}