/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgreshne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:14:58 by mgreshne          #+#    #+#             */
/*   Updated: 2024/04/20 16:14:58 by mgreshne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_perimeter_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] != '\n' && line[i] != 13))
	{
		if (line[i++] != '1')
		{
			free(line);
			ft_print_error("There is no perimeter wall\n");
		}
	}
}

void	check_perimeter_wall(char *str, t_GameData *data)
{
	int		fd;
	char	*line;
	int		row;

	ft_open_fd(str, &fd, &line);
	row = 0;
	while (line)
	{
		if (row == 0 || row == data->window_height - 1)
			check_perimeter_line(line);
		else
		{
			if (line[0] != '1' || line[data->window_width - 1] != '1')
			{
				free(line);
				ft_print_error("There is no perimeter wall\n");
			}
		}
		free(line);
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		row++;
	}
	close(fd);
}

void	count_width(char *str, t_GameData *data)
{
	int		i;
	int		fd;
	char	*line;

	ft_open_fd(str, &fd, &line);
	i = 0;
	data->window_width = 0;
	while (line[i] && (line[i] != '\n' && line[i] != 13))
	{
		data->window_width++;
		i++;
	}
	free(line);
	close(fd);
}

void	checking_extension(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (str[i - 5] && str[i - 4] == '.'
		&& str[i - 3] == 'b' && str[i - 2] == 'e'
		&& str[i - 1] == 'r')
	{
		i = open(str, O_RDONLY);
		if (i == -1)
		{
			ft_print_error("error opening or the file is missing!\n");
			close(i);
		}
		else
			close(i);
	}
	else
		ft_print_error("A map in the format is required .ber\n");
}

void	checking_rectangle(char *str)
{
	int		fd;
	int		len;
	int		len2;
	char	*line;

	ft_open_fd(str, &fd, &line);
	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		len--;
	while (line)
	{
		len2 = ft_strlen(line) - 1;
		if (line[len2] != '\n')
			len2++;
		if (len != len2)
		{
			free(line);
			ft_print_error("not rectangle\n");
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
