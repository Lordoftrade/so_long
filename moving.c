/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgreshne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:30:10 by mgreshne          #+#    #+#             */
/*   Updated: 2024/04/24 22:29:06 by mgreshne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}

void	ft_print_steps(t_GameData *data)
{
	data->player_moves += 1;
	write(1, "step = ", 7);
	ft_putnbr(data->player_moves);
	write(1, "\n", 1);
}

void	ft_player_step(t_GameData *data, int y, int x)
{
	if (data->main_map[data->player_y - y][data->player_x - x] == '1')
		return ;
	if (data->main_map[data->player_y - y][data->player_x - x] == 'c')
	{
		data->main_map[data->player_y - y][data->player_x - x] = '+';
		data->count_coin--;
	}
	if (data->main_map[data->player_y - y][data->player_x - x] == 'e')
	{
		if (data->collected_coins == data->count_coin)
		{
			ft_close(data);
		}
		else
			return ;
	}
	ft_print_steps(data);
	ft_draw_dynamic(data, data->images[1], data->player_y, data->player_x);
	data->player_x -= x;
	data->player_y -= y;
	ft_draw_dynamic(data, data->images[2], data->player_y, data->player_x);
}

int	moving_the_map(int key, t_GameData *data)
{
	if (key == 13)
		ft_player_step(data, 1, 0);
	if (key == 1)
		ft_player_step(data, -1, 0);
	if (key == 0)
		ft_player_step(data, 0, 1);
	if (key == 2)
		ft_player_step(data, 0, -1);
	if (key == 53)
		ft_close(data);
	return (0);
}
