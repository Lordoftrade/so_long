/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgreshne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:15:40 by mgreshne          #+#    #+#             */
/*   Updated: 2024/04/20 16:15:40 by mgreshne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_open_fd(char *str, int *fd, char **line)
{
	*fd = open(str, O_RDONLY);
	if (*fd == -1)
		ft_print_error("Error: unable to open file\n");
	*line = get_next_line(*fd);
	if (*line == NULL)
		ft_print_error("Error, check the map scale!\n");
}

static void	init_data(t_GameData *data, t_position *pos)
{
	pos->x = -1;
	pos->y = -1;
	data->player_moves = 0;
	data->mlx = mlx_init();
	if (data->mlx == NULL)
	{
		ft_print_error("error: mlx_init\n");
	}
}

void	checks(char *str, t_GameData *data)
{
	checking_extension(str);
	checking_rectangle(str);
	count_width(str, data);
	count_height(str, data);
	check_perimeter_wall(str, data);
	fill_map(str, data);
	validate_map(data);
	check_counts(data);
	data->collected_coins = data->count_coin;
	ft_check_flood_fill(data);
}

void	ft_print_error(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(2, &s[i], 1);
		i++;
	}
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_GameData	data;
	t_position	pos;

	if (argc == 1 || argc > 2)
		ft_print_error("there must be 2 arguments\n");
	checks(argv[1], &data);
	init_data(&data, &pos);
	data.size = 64;
	data.window = mlx_new_window(data.mlx,
			data.window_width * data.size,
			data.window_height * data.size, "so_long");
	if (data.window == NULL)
	{
		ft_print_error("error in mlx window\n");
	}
	uploading_image(&data);
	ft_drawing_map(&data, &pos);
	mlx_hook(data.window, 2, 0, moving_the_map, &data);
	mlx_hook(data.window, 17, 0, ft_close, &data);
	mlx_loop(data.mlx);
	return (0);
}
