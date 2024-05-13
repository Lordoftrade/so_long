/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   working_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgreshne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:22:37 by mgreshne          #+#    #+#             */
/*   Updated: 2024/04/24 22:13:30 by mgreshne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_choose_draw(t_GameData *data, t_position *pos, int x, int y)
{
	if (data->main_map[y][x] == '1')
		ft_draw_static(data, data->images[0], y, x);
	else if (data->main_map[y][x] == '+')
		ft_draw_static(data, data->images[1], y, x);
	else if (data->main_map[y][x] == 'P' && pos->x == -1)
	{
		pos->x = x * data->size;
		pos->y = y * data->size;
		ft_draw_dynamic(data, data->images[2], y, x);
	}
	else if (data->main_map[y][x] == 'c')
		ft_draw_dynamic(data, data->images[3], y, x);
	else if (data->main_map[y][x] == 'e')
		ft_draw_static(data, data->images[4], y, x);
}

void	ft_draw_static(t_GameData *data, void *cell, int y, int x)
{
	x = x * data->size;
	y = y * data->size;
	mlx_put_image_to_window(data->mlx, data->window, cell, x, y);
}

void	ft_draw_dynamic(t_GameData *data, void *cell, int y, int x)
{
	x = x * data->size;
	y = y * data->size;
	mlx_put_image_to_window(data->mlx, data->window,
		data->images[1], x, y);
	mlx_put_image_to_window(data->mlx, data->window, cell, x, y);
}

void	ft_drawing_map(t_GameData *data, t_position *pos)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->window_height)
	{
		x = 0;
		while (x < data->window_width)
		{
			ft_choose_draw(data, pos, x, y);
			x++;
		}
		y++;
	}
}

void	uploading_image(t_GameData *data)
{
	data->textures[0] = "./imgs/wall.xpm";
	data->textures[1] = "./imgs/floor.xpm";
	data->textures[2] = "./imgs/player.xpm";
	data->textures[3] = "./imgs/coin.xpm";
	data->textures[4] = "./imgs/exit.xpm";
	data->images[0] = mlx_xpm_file_to_image(data->mlx,
			data->textures[0], &data->size, &data->size);
	data->images[1] = mlx_xpm_file_to_image(data->mlx,
			data->textures[1], &data->size, &data->size);
	data->images[2] = mlx_xpm_file_to_image(data->mlx,
			data->textures[2], &data->size, &data->size);
	data->images[3] = mlx_xpm_file_to_image(data->mlx,
			data->textures[3], &data->size, &data->size);
	data->images[4] = mlx_xpm_file_to_image(data->mlx,
			data->textures[4], &data->size, &data->size);
	if (!data->images[0] || !data->images[1]
		|| !data->images[2] || !data->images[3] || !data->images[4])
		ft_print_error("error\n");
}
