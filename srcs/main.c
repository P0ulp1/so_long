/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:22:58 by phautena          #+#    #+#             */
/*   Updated: 2024/08/01 15:23:04 by phautena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../ft_printf/includes/ft_printf.h"

int	main(int argc, char *argv[])
{
	int	fd;
	int	nlines;
	
	if (check_args(argc, argv) == 1)
		return (1);
	if (is_map_file_existing(argv[1]) == 1)
		return (1);
	fd = open(argv[1], O_RDONLY);
	is_map_rectangle(fd);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	only_valid_map_components(fd);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	nlines = map_number_line(fd);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	check_map_walls(fd, nlines);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	check_map_components(fd);
	close(fd);
	return (0);
}
