/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:19:22 by phautena          #+#    #+#             */
/*   Updated: 2024/08/06 11:44:55 by phautena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_args(int argc, char *map_file)
{
	int		i;
	char	*to_compare;
	char	*map_extension;

	i = 0;
	if (argc != 2)
	{
		ft_printf("Error\nInvalid number of arguments.\n");
		return (1);
	}
	map_extension = ".ber";
	while (map_file[i] != '.')
		i++;
	to_compare = ft_substr(map_file, i, 4);
	if (ft_strncmp(map_extension, to_compare, 4) == 0)
	{
		free(to_compare);
		return (0);
	}
	else
	{
		free(to_compare);
		ft_printf("Error\nThe map file doesn't have a valid extension (.ber)\n");
		return (1);
	}
}

int	is_map_file_existing(char *map_file)
{
	int		fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nMap file not found.\n");
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

char	**fill_map_struct(char *map_file, t_game *game)
{
	int		fd;
	int		i;
	int		rows;
	char	**map;
	char	*line;

	fd = open(map_file, O_RDONLY);
	rows = 0;
	while (get_next_line(fd) != NULL)
		rows++;
	map = malloc(sizeof(char*));
	reset_file_pointer(fd, map_file);
	i = 0;
	while (i < rows)
	{
		line = get_next_line(fd);
		map[i] = ft_strdup(line);
		i++;
	}
	free(line);
	game->map.rows = rows;
	game->map.columns = ft_strlen(map[0]);	
	return (map);
}

void	fill_game_struct(t_game *game)
{
	game->map.rows = 0;
	game->map.columns = 0;
	game->map.coins = 0;
	game->map.exit = 0;
	game->map.player = 0;
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
}

int		check_map_components(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] == EXIT)
				game->map.exit++;
			else if (game->map.map[i][j] == PLAYER)
				game->map.player++;
			else if (game->map.map[i][j] == COIN)
				game->map.coins++;
			j++;
		}
		i++;
	}
	if (game->map.exit != 1 || game->map.player != 1 || game->map.coins < 1)
		return (MLX_ERROR);
}
