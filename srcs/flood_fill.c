/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:04:37 by phautena          #+#    #+#             */
/*   Updated: 2024/08/12 13:26:32 by phautena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_game	flood_fill_init(char *filename)
{
	t_game	flood_game;

	fill_game_struct(&flood_game);
	flood_game.map.map = fill_map_struct(filename, &flood_game);
	check_map_components(&flood_game);
	init_player_pos(&flood_game);
	flood_game.map.map[flood_game.player.y][flood_game.player.x] = WALL;
	return (flood_game);
}

int	flood_fill(t_game *flood_game, long int x, long int y)
{
	ft_printf("Tile: %c\n", flood_game->map.map[y][x]);
	if (flood_game->map.map[y][x] == COLLECTIBLE)
			flood_game->map.collectible--;
	if (flood_game->map.map[y][x] == EXIT)
			flood_game->map.exit--;
	if (flood_game->map.map[y + 1][x] == WALL && flood_game->map.map[y - 1][x] == WALL && flood_game->map.map[y][x + 1] == WALL && flood_game->map.map[y][x - 1] == WALL)
		return (0);
	else
	{
		flood_game->map.map[y][x] = WALL;
		if (flood_game->map.map[y][x + 1] != WALL)
			flood_fill(flood_game, x + 1, y);
		if (flood_game->map.map[y][x - 1] != WALL)
			flood_fill(flood_game, x - 1, y);
		if (flood_game->map.map[y + 1][x] != WALL)
			flood_fill(flood_game, x, y + 1);
		if (flood_game->map.map[y - 1][x] != WALL)
			flood_fill(flood_game, x, y - 1);
		return (0);
	}
}

int	flood_fill_master(char *filename)
{
	t_game	flood_game;

	flood_game = flood_fill_init(filename);
	flood_fill(&flood_game, flood_game.player.x, flood_game.player.y);
	if (flood_game.map.collectible != 0 || flood_game.map.exit != 0)
	{
		ft_free(&flood_game);
		return (MLX_ERROR);
	}
	else
	{
		ft_free(&flood_game);
		return (0);
	}
}