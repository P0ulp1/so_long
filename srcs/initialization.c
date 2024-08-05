/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:29:25 by phautena          #+#    #+#             */
/*   Updated: 2024/08/02 13:06:51 by phautena         ###   ########.fr       */
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