/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:22:37 by phautena          #+#    #+#             */
/*   Updated: 2024/08/07 13:41:24 by phautena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE 64
# define MLX_ERROR 1
# define EXIT 'E'
# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define WALL '1'
# define FLOOR '0'

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
	int			collectible;
	int			exit;
	int			player;
}	t_map;

typedef struct s_img
{
	void	*img_ptr;
	int		height;
	int		width;
}	t_img;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	map;
	t_img	backgroud;
	t_img	wall;
	t_img	collectible;
	t_img	player;
	t_img	exit;
}	t_game;

////init_checks.c////
int		check_args(int argc, char *map_file); //Check number of args and map file extensions//
int		is_map_file_existing(char *map_file); //Check if the map file is existing in the current dir//
char	**fill_map_struct(char *map_file, t_game *game); //Fill the map game object//
void	fill_game_struct(t_game *game); //Fill the whole game struct//
int		check_map_components(t_game *game); //Fill the components found in the map, and check if the number is good//
////other_checks.c////
int		check_walls_top(t_game *game); //Check if the map is entirely surrounded by walls// 
int		check_walls_bottom(t_game *game); //Check if the map is entirely surrounded by walls// 
int		check_walls_middle(t_game *game); //Check if the map is entirely surrounded by walls// 
int		master_check(t_game *game, char *map_filename, int argc); //Perform all the check/initializations above//
void	count_rows(char *map_file, t_game *game); //Calculate the number of rows on the map//
////utilities.c////
int	initialize_xpm(t_game *game);
void	ft_free(t_game *game);
////graphics.c////
int	render(t_game *game);
int	render_tile(t_game *game, int x, int y, char tile);
int	render_map(t_game *game);
////game.c////
int	handle_escape(int keysym, t_game *game);
int	initialize(t_game *game);


#endif