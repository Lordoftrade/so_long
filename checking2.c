/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgreshne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:18:29 by mgreshne          #+#    #+#             */
/*   Updated: 2024/04/24 21:18:23 by mgreshne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_set_player_xy(t_GameData *data, int y, int x)
{
	data->count_player++;
	data->player_x = x;
	data->player_y = y;
}

void	check_counts(t_GameData *data)
{
	if (data->count_player != 1 || data->count_exit != 1
		|| data->count_coin < 1)
		ft_print_error("invalid number of players, exits, or coins\n");
}

void	validate_map(t_GameData *data)
{
	int	i;
	int	j;

	data->count_player = 0;
	data->count_coin = 0;
	data->count_exit = 0;
	i = 1;
	j = 1;
	while (i < data->window_height - 1)
	{
		j = 1;
		while (j < data->window_width - 1)
		{
			if (data->main_map[i][j] == 'P')
				ft_set_player_xy(data, i, j);
			else if (data->main_map[i][j] == 'E')
				data->count_exit++;
			else if (data->main_map[i][j] == 'C')
				data->count_coin++;
			else if (data->main_map[i][j] != '0' && data->main_map[i][j] != '1')
				ft_print_error("invalid character\n");
			j++;
		}
		i++;
	}
}

void	count_height(char *str, t_GameData *data)
{
	int		fd;
	char	*line;

	ft_open_fd(str, &fd, &line);
	data->window_height = 0;
	while (line)
	{
		data->window_height++;
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	free(line);
	close(fd);
}
