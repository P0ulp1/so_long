/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:28:26 by phautena          #+#    #+#             */
/*   Updated: 2024/08/05 11:56:39 by phautena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	render(t_data *data)
{
	if (data->win_ptr == NULL || data->img.mlx_img == NULL)
		return (1);
	render_square(&data->img);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 100, 100);
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