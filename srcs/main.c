/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:22:58 by phautena          #+#    #+#             */
/*   Updated: 2024/08/06 14:57:34 by phautena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;
	
	if (master_check(&game, argv[1], argc) == MLX_ERROR)
	{
		ft_free(&game);
		return (MLX_ERROR);
	}
	return (0);
}
