/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:21:29 by phautena          #+#    #+#             */
/*   Updated: 2024/08/01 14:21:23 by phautena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_map_rectangle(int fd)
{
	char		*line;
	int			end_of_file;
	size_t		line_len;

	line = NULL;
	end_of_file = 0;
	if (read(fd, line, 1) == 0 || read(fd, line, 0) == -1)
	{
		ft_printf("Error\nInvalid permissions on map file AND/OR map is empty.\n");
		return (1);
	}
	line_len = ft_strlen(get_next_line(fd));
	while (end_of_file != 1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			end_of_file = 1;
		else if (ft_strlen(line) != line_len)
		{
			ft_printf("Error\nThe map is not rectangular.\n");
			return (1);
		}
	}
	ft_printf("Map is rectangle.\n");
	return (0);
}

int	only_valid_map_components(int fd)
{
	char	*line;
	int		end_of_file;
	int		i;

	end_of_file = 0;
	while (end_of_file != 1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			end_of_file = 1;
		else
		{
			i = 0;
			while (line[i] != '\0')
			{
				if (line[i] != '0' && line[i] != '1' && line[i] != 'E' && line[i] != 'C' && line[i] != 'P' && line[i] != '\n')
				{
					ft_printf("Error\nMap contains invalid components\n");
					return (1);
				}
				i++;
			}
		}
	}
	return (0);
}

int	check_map_walls(int fd, int map_line_count)
{
	char	*line;
	int		error;

	error = 0;
	error += check_wall_first_and_last_line(fd);
	map_line_count--;
	while (map_line_count != 1)
	{
		line = get_next_line(fd);
		if (line[0] != '1' || line[ft_strlen(line) - 2] != '1')
			error++;
		map_line_count--;
	}
	error += check_wall_first_and_last_line(fd);
	if (error > 0)
	{
		ft_printf("Error\nThe map is not surrounded by walls. Error: %d\n", error);
		return (1);
	}
	else
		return (0);
}

int	check_wall_first_and_last_line(int fd)
{
	int		i;
	int		error;
	char	*line;
	
	i = 0;
	error = 0;
	line = get_next_line(fd);
	while (line[i] != '\n')	
	{
		if (line[i] != '1')
			error++;
		i++;
	}
	return (error);
}

int	map_number_line(int fd)
{
	int		end_of_file;
	int		count;
	char	*line;

	end_of_file = 0;
	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (count);
		count++;
	}
}