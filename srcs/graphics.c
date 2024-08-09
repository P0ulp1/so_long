/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:15:49 by phautena          #+#    #+#             */
/*   Updated: 2024/08/09 13:08:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	render(t_game *game)
{
	if (game->win_ptr && game->render_again == 1)
	{
		if (render_map(game) == MLX_ERROR)
			return (MLX_ERROR);
		game->render_again = 0;
	}
	return (0);
}

int	render_map(t_game *game)
{
	unsigned long	x;
	unsigned long	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (game->player.x == x && game->player.y == y)
				render_player(game);
			else
				render_tile(game, x, y, game->map.map[y][x]);
			x++;
		}
		y++;
	}
	return (0);
}

int	render_tile(t_game *game, int x, int y, char tile)
{
	if (tile == FLOOR && game->background.img_ptr)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->background.img_ptr, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == WALL && game->wall.img_ptr)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->wall.img_ptr, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == EXIT && game->exit.img_ptr)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->exit.img_ptr, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == COLLECTIBLE && game->collectible.img_ptr)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->collectible.img_ptr, x * TILE_SIZE, y * TILE_SIZE);
	return (0);
}

int	render_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player.player.img_ptr, game->player.x * TILE_SIZE, game->player.y * TILE_SIZE);
	return (0);
}
