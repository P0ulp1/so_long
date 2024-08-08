/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:15:33 by phautena          #+#    #+#             */
/*   Updated: 2024/08/08 14:22:32 by phautena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	initialize(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		return (MLX_ERROR);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map.columns * TILE_SIZE, game->map.rows * TILE_SIZE, "so_long");
	if (game->win_ptr == NULL)
		return (MLX_ERROR);
	if (initialize_xpm(game) == MLX_ERROR)
		return (MLX_ERROR);
	mlx_loop_hook(game->mlx_ptr, &render, game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, &handle_input, game);
	mlx_loop(game->mlx_ptr);
	mlx_destroy_display(game->mlx_ptr);
	return (0);
}

int	handle_escape(t_game *game)
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
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	game->win_ptr = NULL;
	return (0);
}

int	handle_input(int keysym, t_game *game)
{
	if (game->win_ptr)
	{
		if (keysym == XK_Escape)
			handle_escape(game);
		else
			handle_movement(keysym, game);
	}
	return (0);
}