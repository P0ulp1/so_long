/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:22:58 by phautena          #+#    #+#             */
/*   Updated: 2024/08/05 11:56:49 by phautena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (master_map_parsing(argc, argv[1]) == 1)
		return (1);
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "so_long");
	if (data.win_ptr == NULL)
	{
		free(data.mlx_ptr);
		return (1);
	}
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &user_input, &data);
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, 100, 100);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}

int	user_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
		data->img.mlx_img = NULL;
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	}
	return (0);
}