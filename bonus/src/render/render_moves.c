/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:40:59 by user42            #+#    #+#             */
/*   Updated: 2021/10/28 04:55:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	render_numbers(t_data *data, int nb, int x, int y)
{
	if (nb == 0)
		xpm_pix_put(data->zero, data, x, y);
	if (nb == 1)
		xpm_pix_put(data->one, data, x, y);
	if (nb == 2)
		xpm_pix_put(data->two, data, x, y);
	if (nb == 3)
		xpm_pix_put(data->three, data, x, y);
	if (nb == 4)
		xpm_pix_put(data->four, data, x, y);
	if (nb == 5)
		xpm_pix_put(data->five, data, x, y);
	if (nb == 6)
		xpm_pix_put(data->six, data, x, y);
	if (nb == 7)
		xpm_pix_put(data->seven, data, x, y);
	if (nb == 8)
		xpm_pix_put(data->eight, data, x, y);
	if (nb == 9)
		xpm_pix_put(data->nine, data, x, y);
}

void	render_moves(t_data *data)
{
	int	i;
	int	j;
	int	base;

	i = data->y_map;
	j = data->x_map - 1;
	base = data->cpt_moves;
	while (base >= 0 && j >= data->x_map - 3 && data->cpt_moves < 1000)
	{
		render_numbers(data, (base % 10), j, i);
		base /= 10;
		j--;
	}
}
