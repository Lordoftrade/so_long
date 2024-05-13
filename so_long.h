/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgreshne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:15:45 by mgreshne          #+#    #+#             */
/*   Updated: 2024/04/20 16:15:45 by mgreshne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"
# include <fcntl.h>

typedef struct GameData
{
	void	*mlx;
	void	*window;
	int		size;
	void	*textures[5];
	void	*images[5];
	char	**main_map;
	int		window_width;
	int		window_height;
	int		player_x;
	int		player_y;
	int		collected_coins;
	int		player_moves;
	int		count_player;
	int		count_coin;
	int		count_exit;
}	t_GameData;

typedef struct t_position
{
	int	x;
	int	y;
}	t_position;

void	ft_print_error(char *s);
void	checks(char *str, t_GameData *data);
void	ft_open_fd(char *str, int *fd, char **line);
void	checking_extension(char *str);
void	checking_rectangle(char *str);
void	count_width(char *str, t_GameData *data);
void	count_height(char *str, t_GameData *data);
void	check_perimeter_wall(char *str, t_GameData *data);
void	fill_map(char *str, t_GameData *data);
void	validate_map(t_GameData *data);
void	check_counts(t_GameData *data);
void	ft_check_flood_fill(t_GameData *data);
void	uploading_image(t_GameData *data);
void	ft_drawing_map(t_GameData *data, t_position *pos);
void	ft_choose_draw(t_GameData *data, t_position *pos, int x, int y);
void	ft_draw_dynamic(t_GameData *data, void *cell, int y, int x);
void	ft_draw_static(t_GameData *data, void *cell, int y, int x);
int		moving_the_map(int key, t_GameData *data);
void	ft_player_step(t_GameData *game, int y, int x);
void	ft_print_steps(t_GameData *data);
void	ft_putnbr(int n);
void	ft_putchar(char c);
int		ft_close(t_GameData *data);
void	ft_free_game(t_GameData *data);

#endif
