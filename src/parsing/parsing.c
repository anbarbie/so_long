/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 04:04:23 by user42            #+#    #+#             */
/*   Updated: 2021/10/22 04:18:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long>

void	parsing(t_data *data, char *s)
{
	if (ft_isdigit(s[data->i]))
		parsing_map(data, s);
	else if (!s[data->i])
	{
		free_str(s);
		exit_error(data, "Empty line in .ber");
	}
	else
		printf("Wrong .ber elem");
}

void	read_ber(t_data *data, char *path_ber)
{
	int		fd;
	int		gnl;
	char	*line_read;

	gnl = -1;
	line_read = NULL;
	fd = open(path_ber, O_RDONLY);
	if (fd == -1)
		return (1);
	while (gnl != 0)
	{
		gnl = get_next_line(fd, &line_read);
		if (gnl == -1)
			return (1);
		data->i = 0;
		if (gnl > 0)
			parsing(data, line_read);
		if (gnl == 0)
			free_str(line_read);
	}
	check_map(data);
}
