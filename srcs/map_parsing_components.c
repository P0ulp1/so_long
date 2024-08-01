/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_components.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:59:29 by phautena          #+#    #+#             */
/*   Updated: 2024/08/01 15:23:00 by phautena         ###   ########.fr       */
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