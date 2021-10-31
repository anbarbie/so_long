/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 04:04:23 by user42            #+#    #+#             */
/*   Updated: 2021/10/31 02:47:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	realloc_map(t_data *data, char *s)
{
	int		i;
	char	**new_map;

	i = 0;
	new_map = malloc(sizeof(char **) * (data->x + 2));
	if (!new_map)
		exit_message(data, "malloc map");
	while (i < data->x)
	{
		new_map[i] = data->map[i];
		i++;
	}
	new_map[i] = s;
	new_map[i + 1] = NULL;
	if (data->map)
		free(data->map);
	data->map = new_map;
	return (0);
}

void	parsing_map(t_data *data, char *str)
{
	realloc_map(data, str);
	data->x++;
}

void	parsing(t_data *data, char *s)
{
	if (ft_isdigit(s[data->i]))
		parsing_map(data, s);
	else if (!s[data->i])
	{
		free_line(s);
		exit_message(data, "Empty line in .ber");
	}
	else
		exit_message(data, "Wrong .ber elem");
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
		exit_message(data, "not a valid file");
	while (gnl != 0)
	{
		gnl = get_next_line(fd, &line_read);
		if (gnl == -1)
			exit_message(data, "gnl failed");
		data->i = 0;
		if (gnl > 0)
			parsing(data, line_read);
		if (gnl == 0)
			free(line_read);
	}
	check_map(data);
}
