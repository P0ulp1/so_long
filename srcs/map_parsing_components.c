/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_components.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:59:29 by phautena          #+#    #+#             */
/*   Updated: 2024/08/02 11:25:02 by phautena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_map_components(int fd)
{
	char	*line;
	int		collectible;
	int		exit;
	int		player;

	collectible = 0;
	exit = 0;
	player = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			if (collectible > 0 && exit == 1 && player == 1)
				return (0);
			else
			{
				ft_printf("Error\nUncorrect number of components in the map.\n");
				return (1);
			}
		}
		parse_map_components(line, &collectible, &exit, &player);
		free(line);
	}
}

void	parse_map_components(char *line, int *collectible, int *exit, int *player)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == 'C')
			*collectible += 1;
		else if (line[i] == 'E')
			*exit += 1;
		else if (line[i] == 'P')
			*player += 1;
		i++;
	}
}

int	reset_file_pointer(int fd, char *map_file)
{
	if (fd != -1)
		close(fd);
	fd = open(map_file, O_RDONLY);
	return (fd);
}

int	master_map_parsing(int argc, char *map_file)
{
	int	fd;
	int	lines_number;

	fd = -1;
	if (check_args(argc, map_file) == 1 || is_map_file_existing(map_file) == 1)
		return (1);
	fd = reset_file_pointer(fd, map_file);
	if (is_map_rectangle(fd) == 1)
		return (1);
	fd = reset_file_pointer(fd, map_file);
	if (only_valid_map_components(fd) == 1)
		return (1);
	fd = reset_file_pointer(fd, map_file);
	lines_number = map_number_line(fd);
	fd = reset_file_pointer(fd, map_file);
	if (check_map_walls(fd, lines_number) == 1)
		return (1);
	fd = reset_file_pointer(fd, map_file);
	if (check_map_components(fd) == 1)
		return (1);
	close(fd);
	return (0);
}
