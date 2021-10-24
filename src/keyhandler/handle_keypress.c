/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 20:55:07 by user42            #+#    #+#             */
/*   Updated: 2021/10/24 05:36:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_w || keysym == XK_W)
		play_up(data);
	if (keysym == XK_a || keysym == XK_A)
		play_left(data);
	if (keysym == XK_s || keysym == XK_S)
		play_down(data);
	if (keysym == XK_d || keysym == XK_D)
		play_right(data);
	if (keysym == XK_Escape)
	{
		free_map(data->map);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	check_exit(data);
	return (0);
}
