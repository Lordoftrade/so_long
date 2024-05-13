/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgreshne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:08:38 by mgreshne          #+#    #+#             */
/*   Updated: 2024/04/24 22:29:36 by mgreshne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_GameData *data)
{
	mlx_destroy_image(data->mlx, data->images[0]);
	mlx_destroy_image(data->mlx, data->images[1]);
	mlx_destroy_image(data->mlx, data->images[2]);
	mlx_destroy_image(data->mlx, data->images[3]);
	mlx_destroy_image(data->mlx, data->images[4]);
	mlx_destroy_window(data->mlx, data->window);
	ft_free_game(data);
	exit (0);
	return (0);
}

void	ft_free_game(t_GameData *data)
{
	int	i;

	i = 0;
	while (i < data->window_height)
	{
		free(data->main_map[i]);
		i++;
	}
	free(data->main_map);
}
