# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phautena <phautena@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/24 10:51:34 by phautena          #+#    #+#              #
#    Updated: 2024/08/01 10:55:49 by phautena         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc -Wall -Wextra -Werror -ggdb -I./minilibx-linux

SRC_DIR = ./srcs/

SRC_FILES = main.c

SRC = ${addprefix ${SRC_DIR},${SRC_FILES}}

OBJ = ${SRC:.c=.o}

MLX_LIB = ./minilibx-linux/libmlx.a -lX11 -lXext
LIBFT_LIB = ./Libft/libft.a
FT_PRINTF_LIB = ./ft_printf/libftprintf.a

.c.o:
	${CC} -c $< -o $@

all: ${NAME}

${NAME}: ${MLX_LIB} ${LIBFT_LIB} ${FT_PRINTF_LIB} ${OBJ}
	${CC} ${OBJ} ${LIBFT_LIB} ${FT_PRINTF_LIB} ${MLX_LIB} -o ${NAME}

${MLX_LIB}:
	${MAKE} -C ./minilibx-linux

${LIBFT_LIB}:
	${MAKE} -C ./Libft

${FT_PRINTF_LIB}:
	${MAKE} -C ./ft_printf

clean:
	${MAKE} clean -C ./minilibx-linux/
	${MAKE} clean -C ./Libft/
	${MAKE} clean -C ./ft_printf/
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}
	rm -f ./Libft/libft.a
	rm -f ./ft_printf/libftprintf.a

re: fclean all

.PHONY: all clean fclean re