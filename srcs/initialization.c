/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:29:25 by phautena          #+#    #+#             */
/*   Updated: 2024/08/05 15:02:18 by phautena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_map_x(char *filename)
{
	int		fd;
	int		x_len;
	char	*line;

	fd = reset_file_pointer(-1, filename);
	line = get_next_line(fd);
	x_len = ft_strlen(line) - 1;
	free(line);
	close(fd);
	return (x_len * TILE_SIZE);
}

int	get_map_y(char *filename)
{
	int		fd;
	int		y_len;
	char	*line;

	fd = reset_file_pointer(-1, filename);
	y_len = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (y_len * TILE_SIZE);
		y_len++;
	}
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(int *)pixel = color;
}

int	handle_input(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	return (0);
}