/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:22:58 by phautena          #+#    #+#             */
/*   Updated: 2024/08/01 11:36:41 by phautena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../ft_printf/includes/ft_printf.h"

int	main(int argc, char *argv[])
{
	if (check_args(argc, argv) == 1)
		return (1);
	if (is_map_file_existing(argv[1]) == 1)
		return (1);
	ft_printf("Valid file.");
	return (0);
}

int	check_args(int argc, char *argv[])
{
	int		i;
	char	*to_compare;
	char	*map_extension;

	i = 0;
	if (argc != 2)
	{
		ft_printf("Error\nInvalid number of arguments.\n");
		return (1);
	}
	map_extension = ".ber";
	while (argv[1][i] != '.')
		i++;
	to_compare = ft_substr(argv[1], i, 4);
	if (ft_strncmp(map_extension, to_compare, 4) == 0)
		return (0);
	else
	{
		ft_printf("Error\nThe map file doesn't have a valid extension (.ber)\n");
		return (1);
	}
}

int	is_map_file_existing(char *map_file)
{
	int		fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nMap file not found.\n");
		return (1);
	}
	return (0);
}