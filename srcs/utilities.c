/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:55:52 by phautena          #+#    #+#             */
/*   Updated: 2024/08/07 13:57:24 by phautena         ###   ########.fr       */
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
	game->wall.img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "./sprites/wall.xpm", &game->backgroud.width, &game->backgroud.height);
	if (game->wall.img_ptr == NULL)
		return (MLX_ERROR);
	game->backgroud.img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "./sprites/floor.xpm", &game->backgroud.width, &game->backgroud.height);
	if (game->backgroud.img_ptr == NULL)
		return (MLX_ERROR);
	game->exit.img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "./sprites/exit.xpm", &game->exit.width, &game->exit.height);
	if (game->exit.img_ptr == NULL)
		return (MLX_ERROR);
	game->collectible.img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "./sprites/collectible.xpm", &game->collectible.width, &game->collectible.height);
	if (game->collectible.img_ptr == NULL)
		return (MLX_ERROR);
	return (0);
}