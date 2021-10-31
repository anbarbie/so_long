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
# include <time.h>

# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>

typedef struct s_pos
{
	int		*b;
	int		*x_gump;
	int		*y_gump;
}			t_pos;

typedef struct s_data
{
	int		i;
	int		x;
	int		x_map;
	int		y_map;
	int		x_player;
	int		y_player;
	char	**map;
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;
	int		height;
	int		size_xpm;
	int		cpt_moves;
	int		cpt_sprite;
	int		cpt_exit;
	int		cpt_gump;
	t_img	*img;
	t_img	*wall;
	t_img	*player;
	t_img	*exit;
	t_img	*ground;
	t_img	*sprite;
	t_img	*sprite2;
	t_img	*ennemy;
	t_img	*zero;
	t_img	*one;
	t_img	*two;
	t_img	*three;
	t_img	*four;
	t_img	*five;
	t_img	*six;
	t_img	*seven;
	t_img	*eight;
	t_img	*nine;
	t_pos	*pos;
}			t_data;

//Init
int		init(t_data *data);
void	init_struct(t_data *data);
void	init_struct_parsing(t_data *data);
void	xpm_to_image(t_data *data, t_img **img, char *path);

//Parsing
void	check_format(t_data *data, char *path_ber);
void	read_ber(t_data *data, char *path_ber);
void	parsing(t_data *data, char *s);
void	check_map_is_rec(t_data *data);
void	check_map(t_data *data);
int		realloc_map(t_data *data, char *s);
void	parsing_map(t_data *data, char *str);
int		check_content(char s);

//Render
int		render(t_data *data);
void	render_map(t_data *data);
void	render_items(t_data *data);
void	render_moves(t_data *data);
void	render_numbers(t_data *data, int nb, int x, int y);
void	render_gump(t_data *data);
void	img_pix_put(t_img *img, int x, int y, int color);
void	xpm_pix_put(t_img *img, t_data *data, int x, int y);
int		encode_rgb(uint8_t red, uint8_t green, uint8_t blue);
int		handle_keypress(int keysym, t_data *data);
int		get_color_from_texture(t_img *img, int x, int y);
int		update(t_data *data);

//Keypress
int		handle_keypress(int keysym, t_data *data);
void	play_down(t_data *data);
void	play_up(t_data *data);
void	play_left(t_data *data);
void	play_right(t_data *data);
void	start_move(t_data *data);
void	end_move(t_data *data);
int		check_sprite(t_data *data);
void	check_exit(t_data *data);
int		is_it_solved(t_data *data);
void	gump_patrol(t_data *data);
void	get_gump_pos(t_data *data, int x, int y);

//Exit
void	exit_success(t_data *data);
void	exit_message(t_data *data, char *s);
int		exit_cross(t_data *data);
void	free_map(char **s);
void	free_line(char *s);
void	free_tab(t_data *data);

#endif