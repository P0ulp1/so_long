/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:50:40 by phautena          #+#    #+#             */
/*   Updated: 2024/08/06 15:52:05 by phautena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_walls_top(t_game *game)
{
	size_t	i;

	i = 0;
	while (game->map.map[0][i] != '\n')
	{
		if (game->map.map[0][i] != WALL)
		{
			ft_printf("Error\nThe map is not surrounded by walls.\n");
			return (MLX_ERROR);
		}
		i++;
	}
	return (0);
}

int	check_walls_bottom(t_game *game)
{
	int	i;
	
	i = 0;
	while (game->map.map[game->map.rows - 1][i] != '\n')
	{
		if (game->map.map[game->map.rows - 1][i] != WALL)
		{
			ft_printf("Error\nThe map is not surrounded by walls.\n");
			return (MLX_ERROR);
		}
		i++;
	}
	return (0);
}

int	check_walls_middle(t_game *game)
{
	size_t	i;
	
	i = 1;
	while (i < game->map.rows)
	{
		if (game->map.map[i][0] != WALL)
		{
			ft_printf("Error\nThe map is not surrounded by walls.\n");
			return (MLX_ERROR);
		}
		i++;
	}
	return (0);
}

int	master_check(t_game *game, char *map_filename, int argc)
{
	size_t 	i;

	if (check_args(argc, map_filename) == MLX_ERROR || is_map_file_existing(map_filename) == MLX_ERROR)
		return (MLX_ERROR);
	fill_game_struct(game);
	game->map.map = fill_map_struct(map_filename, game);
	i = 0;
	while (i < game->map.rows)
	{
		if (ft_strlen(game->map.map[i]) != game->map.columns)
		{
			//ft_printf("Len: %d\nColumns: %d\n", ft_strlen(game->map.map[i]), game->map.columns);
			ft_printf("Error\nThe map file is not rectangle.\n");
			return (MLX_ERROR);
		}
		i++;
	}
	if (check_map_components(game) == MLX_ERROR || check_walls_top(game) == MLX_ERROR || check_walls_middle(game) == MLX_ERROR || check_walls_bottom(game) == MLX_ERROR)
		return (MLX_ERROR);
	return (0);
}

void	count_rows(char *map_file, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(map_file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			close(fd);
			return;
		}
		game->map.rows++;
		free(line);
	}
}
