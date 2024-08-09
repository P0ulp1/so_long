/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:45:15 by phautena          #+#    #+#             */
/*   Updated: 2024/08/09 14:11:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	handle_movement(int keysym, t_game *game)
{
	if (keysym == XK_w && movement_possible('U', game) == 0)
		game->player.y -= 1;
	else if (keysym == XK_s && movement_possible('D', game) == 0)
		game->player.y += 1;
	else if (keysym == XK_d && movement_possible('R', game) == 0)
		game->player.x += 1;
	else if (keysym == XK_a && movement_possible('L', game) == 0)
		game->player.x -= 1;
	//Handle if on special tile//
	handle_move_tile(game);
	game->render_again = 1;
	return (0);
}

int	movement_possible(char direction, t_game *game)
{
	if (direction == 'U' && game->map.map[game->player.y - 1][game->player.x] != WALL)
	{
		if (game->player.y - 1 >= 0)
			return (display_movements_number(game));
	}
	else if (direction == 'D' && game->map.map[game->player.y + 1][game->player.x] != WALL)
	{
		if (game->player.y + 1 < game->map.rows)
			return (display_movements_number(game));
	}
	else if (direction == 'R' && game->map.map[game->player.y][game->player.x + 1] != WALL)
	{
		if (game->player.x + 1 < game->map.columns)
			return (display_movements_number(game));
	}
	else if (direction == 'L' && game->map.map[game->player.y][game->player.x - 1] != WALL)
	{
		if (game->player.x - 1 >= 0)
			return (display_movements_number(game));
	}
	return (MLX_ERROR);
}

int	display_movements_number(t_game *game)
{
	game->player.movements++;
	ft_printf("Number of moves: %d\n", game->player.movements);
	return (0);
}

void	handle_move_tile(t_game *game)
{
	if (game->map.map[game->player.y][game->player.x] == COLLECTIBLE)
	{
		game->map.map[game->player.y][game->player.x] = FLOOR;
		game->map.collectible--;
	}
	else if (game->map.map[game->player.y][game->player.x] == EXIT)
	{
		if (game->map.collectible == 0)
			handle_escape(game);
	}
}
