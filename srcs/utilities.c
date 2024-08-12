/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:55:52 by phautena          #+#    #+#             */
/*   Updated: 2024/08/12 11:12:47 by phautena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free(t_game *game)
{
	int	i;

	if  (game->win_ptr)
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		game->win_ptr = NULL;
	}
	if (game->map.map != NULL)
	{
		i = game->map.rows - 1;
		while (i != -1)
			free(game->map.map[i--]);
		free(game->map.map);
	}
	mlx_destroy_display(game->mlx_ptr);
	if (game->mlx_ptr != NULL)
	{
		free(game->mlx_ptr);
		game->mlx_ptr = NULL;
	}
}

void	free_images(t_game *game)
{
	if (game->background.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->background.img_ptr);
	if (game->wall.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->wall.img_ptr);
	if (game->exit.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->exit.img_ptr);
	if (game->collectible.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->collectible.img_ptr);
	if (game->player.player.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->player.player.img_ptr);
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
	long int	x;
	long int	y;

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
