/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:28:26 by phautena          #+#    #+#             */
/*   Updated: 2024/08/05 15:02:14 by phautena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	render(t_data *data)
{
	render_background(data);
	return (0);
}

void	render_square(t_img *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < 50)
	{
		j = 0;
		while (j < 50)
			my_mlx_pixel_put(img, j++, i, 0x00FF00);
		++i;
	}
}

void	render_background(t_data *data)
{
	int	x;
	int	y;

	if (data->win_ptr != NULL)
	{
		data->background.bck_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "./sprites/tile.xpm", &data->background.width, &data->background.height);
		y = 0;
		while (y < HEIGHT)
		{
			x = 0;
			while (x < WIDTH)
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->background.bck_ptr, x, y);
				x += 16;
			}
			y += 16;
		}
	}
}