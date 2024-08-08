/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:55:52 by phautena          #+#    #+#             */
/*   Updated: 2024/08/08 14:16:27 by phautena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free(t_game *game)
{
	int	i;

	if (game->map.map != NULL)
	{
		i = game->map.rows - 1;
		while (i != -1)
			free(game->map.map[i--]);
		free(game->map.map);
	}
	if (game->mlx_ptr != NULL)
	{
		free(game->mlx_ptr);
		game->mlx_ptr = NULL;
	}
}

int	initialize_xpm(t_game *game)
{
	game->wall.img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "./sprites/wall.xpm", &game->wall.width, &game->wall.height);
	if (game->wall.img_ptr == NULL)
		return (MLX_ERROR);
	game->background.img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "./sprites/floor.xpm", &game->background.width, &game->background.height);
	if (game->background.img_ptr == NULL)
		return (MLX_ERROR);
	game->exit.img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "./sprites/exit.xpm", &game->exit.width, &game->exit.height);
	if (game->exit.img_ptr == NULL)
		return (MLX_ERROR);
	game->collectible.img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "./sprites/collectible.xpm", &game->collectible.width, &game->collectible.height);
	if (game->collectible.img_ptr == NULL)
		return (MLX_ERROR);
	game->player.player.img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "./sprites/player.xpm", &game->player.player.width, &game->player.player.height);
	if (game->player.player.img_ptr == NULL)
		return (MLX_ERROR);
	init_player_pos(game);
	return (0);
}

void	init_player_pos(t_game *game)
{
	unsigned long x;
	unsigned long y;

	if (game->win_ptr)
	{
		y = 0;
		while (y < game->map.rows)
		{
			x = 0;
			while (x < game->map.columns)
			{
				if (game->map.map[y][x] == PLAYER)
				{
					game->player.x = x;
					game->player.y = y;
					return;
				}
				x++;
			}
			y++;
		}
	}
}