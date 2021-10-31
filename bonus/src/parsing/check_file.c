/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 05:46:50 by user42            #+#    #+#             */
/*   Updated: 2021/10/29 13:49:22 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	check_format(t_data *data, char *path_ber)
{
	int	i;

	i = 0;
	if (ft_strlen(path_ber) < 4)
		exit_message(data, "File extension need to be: \".ber\".");
	while (path_ber[i] != '\0')
		i++;
	while (path_ber[i] != '.')
	{
		i--;
		if (i < 0)
			exit_message(data, "File extension need to be: \".ber\".");
	}
	if (ft_strlen(path_ber + i) == 4)
	{
		if (path_ber[i + 1] == 'b' && path_ber[i + 2] == 'e'
			&& path_ber[i + 3] == 'r')
			read_ber(data, path_ber);
		else
			exit_message(data, "File extension need to be: \".ber\".");
	}
	else
		exit_message(data, "File extension need to be: \".ber\".");
}
