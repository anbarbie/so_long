/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 02:57:23 by user42            #+#    #+#             */
/*   Updated: 2021/10/31 04:37:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	update(t_data *data)	
{
	static int	i = 0;
	if (data->win_ptr == NULL)
			return (1);
	if (i == 200)
	{
		gump_patrol(data);
		check_exit(data);
		i = 0;
	}
	i++;
	render(data);
	return (0);
}