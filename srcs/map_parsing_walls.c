/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_walls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:21:29 by phautena          #+#    #+#             */
/*   Updated: 2024/08/02 11:32:50 by phautena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_map_rectangle(int fd)
{
	char		*line;
	char		*first_line;
	size_t		line_len;

	line = "";
	if (read(fd, line, 1) == 0 || read(fd, line, 0) == -1)
	{
		ft_printf("Error\nInvalid permissions on map file AND/OR map is empty.\n");
		return (1);
	}
	first_line = get_next_line(fd);
	line_len = ft_strlen(first_line);
	free(first_line);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		else if (ft_strlen(line) != line_len)
		{
			ft_printf("Error\nThe map is not rectangular.\n");
			return (1);
		}
		free(line);
	}
	return (0);
}

int	only_valid_map_components(int fd)
{
	char	*line;	
	int		i;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		else
		{
			i = 0;
			while (line[i] != '\0')
			{
				if (line[i] != '0' && line[i] != '1' && line[i] != 'E' && line[i] != 'C' && line[i] != 'P' && line[i] != '\n')
				{
					ft_printf("Error\nMap contains invalid components.\n");
					return (1);
				}
				i++;
			}
		}
		free(line);
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
		free(line);
	}
	error += check_wall_first_and_last_line(fd);
	if (error > 0)
	{
		ft_printf("Error\nThe map is not surrounded by walls.\n");
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
	free(line);
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
		free(line);
	}
}