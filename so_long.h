/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phautena <phautena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:22:37 by phautena          #+#    #+#             */
/*   Updated: 2024/08/01 11:36:57 by phautena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx-linux/mlx.h" //mlx//
#include "./Libft/libft.h" //libft//
#include <fcntl.h> //open//

//Parsing map files//
int	check_args(int argc, char *argv[]);
int	is_map_file_existing(char *map_file);