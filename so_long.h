/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:22:37 by phautena          #+#    #+#             */
/*   Updated: 2024/08/16 10:25:41 by phautena         ###   ########.fr       */
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

typedef struct s_img
{
	void	*img_ptr;
	int		height;
	int		width;
}	t_img;

typedef struct s_player
{
	long int		x;
	long int		y;
	long int		movements;
	t_img			player;
}	t_player;

typedef struct s_map
{
	char		**map;
	long int	rows;
	long int	columns;
	int			collectible;
	int			exit;
	int			player;
	int			up;
	int			down;
	int			left;
	int			right;
}	t_map;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		map;
	t_img		background;
	t_img		wall;
	t_img		collectible;
	t_img		exit;
	t_player	player;
	int			render_again;
}	t_game;

////init_checks.c////
int		check_args(int argc, char *map_file);
int		is_map_file_existing(char *map_file);
char	**fill_map_struct(char *map_file, t_game *game);
void	fill_game_struct(t_game *game);
int		check_map_components(t_game *game);
////other_checks.c////
int		check_walls_top(t_game *game);
int		check_walls_bottom(t_game *game);
int		check_walls_middle(t_game *game);
int		master_check(t_game *game, char *map_filename, int argc);
void	count_rows(char *map_file, t_game *game);
////utilities.c////
int		initialize_xpm(t_game *game);
void	ft_free(t_game *game);
void	init_player_pos(t_game *game);
void	free_images(t_game *game);
////graphics.c////
int		render(t_game *game);
int		render_tile(t_game *game, int x, int y, char tile);
int		render_map(t_game *game);
int		render_player(t_game *game);
////game.c////
int		handle_escape(t_game *game);
int		initialize(t_game *game);
int		handle_input(int keysym, t_game *game);
int		handle_cross(t_game *game);
////movement.c////
int		handle_movement(int keysym, t_game *game);
int		movement_possible(char direction, t_game *game);
int		display_movements_number(t_game *game);
void	handle_move_tile(t_game *game);
////flood_fill.c////
t_game	flood_fill_init(char *filename);
int		flood_fill(t_game *flood_game, long int x, long int y);
int		flood_fill_master(char *filename);

#endif
