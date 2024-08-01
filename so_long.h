/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:22:37 by phautena          #+#    #+#             */
/*   Updated: 2024/08/01 15:21:06 by phautena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx-linux/mlx.h" //mlx//
#include "./Libft/libft.h" //libft//
#include "./ft_printf/includes/ft_printf.h" //ft_printf//
#include "./get_next_line/get_next_line.h" //GNL//
#include <fcntl.h> //open//

//Parsing map files//
int		check_args(int argc, char *argv[]);
int		is_map_file_existing(char *map_file);
int		is_map_rectangle(int fd);
int		only_valid_map_components(int fd);
int		map_number_line(int fd);
int		check_map_walls(int fd, int map_line_count);
int		check_wall_first_and_last_line(int fd);
int		check_map_components(int fd);
void	parse_map_components(char *line, int *collectible, int *exit, int *player);