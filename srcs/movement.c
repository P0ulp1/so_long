/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:45:15 by phautena          #+#    #+#             */
/*   Updated: 2024/08/08 14:28:32 by phautena         ###   ########.fr       */
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
	else if (keysym == XK_a && movement_possible('U', game) == 0)
		game->player.x -= 1;
	game->render_again = 1;
	return (0);
}

int	movement_possible(char direction, t_game *game)
{
	if (direction == 'U')
	{
		if (game->player.y - 1 >= 0)
			return (0);
	}
	else if (direction == 'D')
	{
		if (game->player.y + 1 <= game->map.rows)
			return (0);
	}
	else if (direction == 'R')
	{
		if (game->player.x + 1 <= game->map.columns)
			return (0);
	}
	else if (direction == 'L')
	{
		if (game->player.x - 1 >= 0)
			return (0);
	}
	return (MLX_ERROR);
}
