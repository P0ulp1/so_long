/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:22:37 by phautena          #+#    #+#             */
/*   Updated: 2024/08/06 12:03:39 by phautena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE 16
# define HEIGHT 500
# define WIDTH 500
# define MLX_ERROR 1
# define EXIT 'E'
# define PLAYER 'P'
# define COIN 'C'
# define WALL '1'

# include "./minilibx-linux/mlx.h" //mlx//
# include "./Libft/libft.h" //libft//
# include "./ft_printf/includes/ft_printf.h" //ft_printf//
# include "./get_next_line/get_next_line.h" //GNL//
# include <fcntl.h> //open//
# include <X11/X.h> //mlx events//
# include <X11/keysym.h> //mlx keysyms//
# include <stdio.h> //size_t//

typedef struct s_map
{
	char		**map;
	size_t		rows;
	size_t		columns;
	int			coins;
	int			exit;
	int			player;
}	t_map;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	map;
}	t_game;

////init_checks.c////
int		check_args(int argc, char *map_file); //Check number of args and map file extensions//
int		is_map_file_existing(char *map_file); //Check if the map file is existing in the current dir//
char	**fill_map_struct(char *map_file, t_game *game); //Fill the map game object//
void	fill_game_struct(t_game *game); //Fill the whole game struct//
int		check_map_components(t_game *game); //Fill the components found in the map, and check if the number is good//
////other_checks.c////
int		check_walls(t_game *game); //Check if the map is entirely surrounded by walls// 
int		master_check(t_game *game, char *map_filename, int argc); //Perform all the check/initializations above//


#endif