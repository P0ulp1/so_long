/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:50:40 by phautena          #+#    #+#             */
/*   Updated: 2024/08/06 12:01:59 by phautena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_walls(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.map[0][i])
	{
		if (game->map.map[0][i] != WALL)
			return (MLX_ERROR);
		i++;
	}
	i = 0;
	while (game->map.map[game->map.rows][i])
	{
		if (game->map.map[game->map.rows][i] != WALL)
			return (MLX_ERROR);
		i++;
	}
	i = 1;
	while (i < game->map.rows)
	{
		if (game->map.map[i][0] != WALL || game->map.map[i][game->map.columns] != WALL)
			return (MLX_ERROR);
		i++;
	}
	return (0);
}

int	master_check(t_game *game, char *map_filename, int argc)
{
	if (check_args(argc, map_filename) == 1 || is_map_file_existing(map_filename) == 1)
		return (MLX_ERROR);
	game->map.map = fill_map_struct(map_filename, &game);
	fill_game_struct(&game);
	if (check_map_components(&game) == 1 || check_walls(&game) == 1)
		return (MLX_ERROR);
}