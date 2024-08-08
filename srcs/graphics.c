/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:15:49 by phautena          #+#    #+#             */
/*   Updated: 2024/08/07 13:57:27 by phautena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	render(t_game *game)
{
	if (render_map(game) == MLX_ERROR)
		return (MLX_ERROR);
	return (0);
}

int	render_map(t_game *game)
{
	unsigned long	x;
	unsigned long	y;

	if (game->win_ptr)
	{
		y = 0;
		while (y < game->map.rows)
		{
			x = 0;
			while (x < game->map.columns)
			{
				if (render_tile(game, x, y, game->map.map[y][x]) == MLX_ERROR)
					return (MLX_ERROR);
				x++;
			}
			y++;
		}
	}
	return (0);
}

int	render_tile(t_game *game, int x, int y, char tile)
{
	if (tile == FLOOR && game->backgroud.img_ptr)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->backgroud.img_ptr, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == WALL && game->wall.img_ptr)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->wall.img_ptr, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == EXIT && game->exit.img_ptr)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->exit.img_ptr, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == COLLECTIBLE && game->collectible.img_ptr)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->collectible.img_ptr, x * TILE_SIZE, y * TILE_SIZE);
	return (0);
}
