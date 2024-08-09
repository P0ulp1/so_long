/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:19:22 by phautena          #+#    #+#             */
/*   Updated: 2024/08/09 13:59:21 by marvin           ###   ########.fr       */
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
		return (MLX_ERROR);
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
		return (MLX_ERROR);
	}
}

int	is_map_file_existing(char *map_file)
{
	int		fd;
	char	*buffer;

	fd = open(map_file, O_RDONLY);
	buffer = NULL;
	if (fd < 0)
	{
		ft_printf("Error\nMap file not found.\n");
		close(fd);
		return (MLX_ERROR);
	}
	if (read(fd, &buffer, 0) == -1 || read(fd, &buffer, 1) != 1)
	{
		ft_printf("Error\nThe map file is not readable and/or empty.\n");
		close(fd);
		return (MLX_ERROR);
	}
	close(fd);
	return (0);
}

char	**fill_map_struct(char *map_file, t_game *game)
{
	int			fd;
	char		**map;
	char		*line;
	size_t		i;

	count_rows(map_file, game);
	fd = open(map_file, O_RDONLY);
	map = malloc(sizeof(char*) * game->map.rows);
	i = 0;
	while (i < game->map.rows)
	{
		line = get_next_line(fd);
		map[i] = ft_strdup(line);
		free(line);
		i++;
	}
	get_next_line(fd);
	game->map.columns = ft_strlen(map[0]) - 1;
	close(fd);
	return (map);
}

void	fill_game_struct(t_game *game)
{
	game->map.rows = 0;
	game->map.columns = 0;
	game->map.collectible = 0;
	game->map.exit = 0;
	game->map.player = 0;
	game->render_again = 1;
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->map.map = NULL;
	game->background.img_ptr = NULL;
	game->wall.img_ptr = NULL;
	game->exit.img_ptr = NULL;
	game->collectible.img_ptr = NULL;
	game->player.player.img_ptr = NULL;
	game->player.movements = 0;
}

int		check_map_components(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] == EXIT)
				game->map.exit++;
			else if (game->map.map[i][j] == PLAYER)
				game->map.player++;
			else if (game->map.map[i][j] == COLLECTIBLE)
				game->map.collectible++;
			j++;
		}
		i++;
	}
	if (game->map.exit != 1 || game->map.player != 1 || game->map.collectible < 1)
	{
		ft_printf("Error\nThe map doesn't have the required elements.\n");
		return (MLX_ERROR);
	}
	return (0);
}
