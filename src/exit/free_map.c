/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 03:33:59 by user42            #+#    #+#             */
/*   Updated: 2021/10/29 13:32:21 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	free_map(char **s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			if (s[i])
			{
				free(s[i]);
				s[i] = NULL;
			}
			i++;
		}
		free(s);
		s = NULL;
	}
}

void	free_line(char *s)
{
	if (s)
	{
		free(s);
		s = NULL;
	}
}
