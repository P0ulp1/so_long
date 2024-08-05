/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:22:37 by phautena          #+#    #+#             */
/*   Updated: 2024/08/02 12:56:06 by phautena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE 100

typedef struct s_data //struct holding mlx pointers//
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

# include "./minilibx-linux/mlx.h" //mlx//
# include "./Libft/libft.h" //libft//
# include "./ft_printf/includes/ft_printf.h" //ft_printf//
# include "./get_next_line/get_next_line.h" //GNL//
# include <fcntl.h> //open//
# include <X11/X.h> //mlx events//
# include <X11/keysym.h> //mlx keysyms//

//Parsing map files//
////check_args.c////
int		check_args(int argc, char *map_file); //Check number of args and map file extensions//
int		is_map_file_existing(char *map_file); //Check if the map file is existing in the current dir//
////map_parsing_walls.c////
int		is_map_rectangle(int fd); //Check if the map is rectangle//
int		only_valid_map_components(int fd); //Check if the map only contains valid components//
int		map_number_line(int fd); //Return the number of line the map is//
int		check_map_walls(int fd, int map_line_count); //Check if the map is surrounded by walls//
int		check_wall_first_and_last_line(int fd); //Helper function for the top and bottom walls//
////map_parsing_components.c////
int		check_map_components(int fd); //Count if the number of components is the right one (no dup)//
void	parse_map_components(char *line, int *collectible, int *exit, int *player); //Helper function for the number of components//
int		reset_file_pointer(int fd, char *map_file); //Close and reopen the given fd/file to reset the pointer//
int		master_map_parsing(int argc, char *map_file); //Master function for all the above ones//
////initialization.c////
int	get_map_x(char *filename); //Returns the number of tiles on the X axis//
int	get_map_y(char *filename); //Returns the number of tiles on the Y axis//
int	handle_keypress(int keysym, t_data *data);
#endif