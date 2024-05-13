/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgreshne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:11:09 by mgreshne          #+#    #+#             */
/*   Updated: 2024/04/21 16:11:09 by mgreshne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_flood_fill(t_GameData *data, int y, int x)
{
	if (data->main_map[y][x] == 'c' || data->main_map[y][x] == 'e'
		|| data->main_map[y][x] == '1' ||
		data->main_map[y][x] == '+')
		return (0);
	else if (data->main_map[y][x] == '0')
		data->main_map[y][x] = '+';
	else if (data->main_map[y][x] == 'E')
	{
		data->count_exit -= 1;
		data->main_map[y][x] = 'e';
		return (0);
	}
	else if (data->main_map[y][x] == 'C')
	{
		data->collected_coins -= 1;
		data->main_map[y][x] = 'c';
	}
	ft_flood_fill(data, y - 1, x);
	ft_flood_fill(data, y + 1, x);
	ft_flood_fill(data, y, x - 1);
	ft_flood_fill(data, y, x + 1);
	if (data->collected_coins != 0 || data->count_exit != 0)
		return (1);
	else
		return (0);
}

void	ft_check_flood_fill(t_GameData *data)
{
	if (ft_flood_fill(data, data->player_y, data->player_x) == 1)
		ft_print_error("It's closed!");
}

char	*ft_strcpy1(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] && (src[i] != '\n' && src[i] != 13))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	fill_map(char *str, t_GameData *data)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_print_error("Error: unable to open file\n");
	line = get_next_line(fd);
	if (line == NULL)
		ft_print_error("error\n");
	i = 0;
	data->main_map = (char **)malloc(data->window_height * sizeof(char *));
	if (data->main_map == NULL)
		ft_print_error("error\n");
	while (line)
	{
		data->main_map[i] = (char *)malloc((data->window_width + 1)
				* sizeof(char));
		if (data->main_map[i] == NULL)
			ft_print_error("error\n");
		ft_strcpy1(data->main_map[i++], line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
