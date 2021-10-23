/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 21:50:45 by antbarbi          #+#    #+#             */
/*   Updated: 2021/10/10 21:50:45 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include <mlx_int.h>
# include <math.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdint.h>
# include <get_next_line.h>
# include <libft.h>

#include <X11/X.h>
#include <X11/keysym.h>
#include <stdio.h>

typedef struct s_data
{
	int		i;
	int		x;
	char	**map;
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;
	int		height;
	int		size_xpm;
	t_img	*img;
	t_img	*wall;
	t_img	*player;
	t_img	*exit;
	t_img	*ground;
	t_img	*sprite;
	t_img	*sprite2;
	t_img	*ennemy;
}			t_data;

typedef struct s_rect
{
	int		x;
	int		y;
	int		width;
	int		height;
	int		color;
}			t_rect;

//Init
int 	init(t_data *data);

//Render
int		render(t_data *data);
void	render_map(t_data *data);
void	render_items(t_data *data);
void	img_pix_put(t_img *img, int x, int y, int color);
void	xpm_pix_put(t_img *img, t_data *data, int x, int y);
int		encode_rgb(uint8_t red, uint8_t green, uint8_t blue);
int		handle_keypress(int keysym, t_data *data);
int		get_color_from_texture(t_img *img, int x, int y);

//Parsing
void	read_ber(t_data *data, char *path_ber);
void	parsing(t_data *data, char *s);
void	check_map_is_rec(t_data *data);
void	check_map(t_data *data);
int		realloc_map(t_data *data, char *s);
void	parsing_map(t_data *data, char *str);
int		check_content(char s);

//Exit
void	exit_message(t_data *data, char *s);
void	free_map(t_data *data);

#endif
