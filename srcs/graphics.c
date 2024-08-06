/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:15:49 by phautena          #+#    #+#             */
/*   Updated: 2024/08/06 16:01:35 by phautena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	render(t_game *game)
{
	render_background(game);
	return (0);
}

int	render_background(t_game *game)
{
	unsigned long	x;
	unsigned long	y;

	game->backgroud.img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "./sprites/floor.xpm", &game->backgroud.width, &game->backgroud.height);
	if (game->backgroud.img_ptr == NULL)
		return (MLX_ERROR);
	if (game->win_ptr)
	{
		y = 0;
		while (y < game->map.rows * TILE_SIZE)
		{
			x = 0;
			while (x < game->map.columns * TILE_SIZE)
			{
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->backgroud.img_ptr, x, y);
				x += TILE_SIZE;
			}
			y += TILE_SIZE;
		}
	}
	return (0);
}
