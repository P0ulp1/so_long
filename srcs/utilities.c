/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:55:52 by phautena          #+#    #+#             */
/*   Updated: 2024/08/06 15:08:05 by phautena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free(t_game *game)
{
	int	i;

	i = game->map.rows - 1;
	while (i != -1)
		free(game->map.map[i--]);
	free(game->map.map);
	if (game->mlx_ptr != NULL)
	{
		free(game->mlx_ptr);
		game->mlx_ptr = NULL;
	}
}