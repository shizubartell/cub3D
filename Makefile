# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abartell <abartell@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 10:43:49 by abartell          #+#    #+#              #
#    Updated: 2023/01/30 13:05:47 by abartell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# VARIABLES

NAME						:=			cub3D

CFLAGS						:=			-Wall -Wextra -Werror -g
CC							:=			gcc
RM							:=			rm -rf

INC							:=			-I ./inc/
HEADER						:=			./inc/cub3D.h

LIBFT_DIR					:=			libft
LIBFT_A						:=			./libft/libft.a

GET_NEXT_LINE_DIR			:=			get_next_line
GET_NEXT_LINE_A				:=			./get_next_line/get_next_line.a

MLX_DIR						:=			minilibx_opengl_20191021
MLX_A						:=			./minilibx_opengl_20191021/libmlx.a

SRC_DIR						:=			./src/
OBJ_DIR						:=			./obj/

# **************************************************************************** #
# COLORS

GREEN		:= \033[0;92m
YELLOW		:= \033[0;93m
BLUE		:= \033[0;94m
END_COLOR	:= \033[0;39m

# **************************************************************************** #
# SOURCES

SRC_FILES					:=	main.c \
								parsing.c \
								errors.c \

OBJ_FILES					:= ${SRC_FILES:.c=.o}
SRC							:= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ							:= $(addprefix $(OBJ_DIR), $(OBJ_FILES))

# **************************************************************************** #
# RULES -fsanitize=address

all :	$(OBJ_DIR) $(NAME)

$(NAME): $(OBJ)
	echo "make $(MLX_DIR)"
	make -C $(MLX_DIR)
	echo "make $(LIBFT_DIR)"
	make -C $(LIBFT_DIR)
	echo "make $(GET_NEXT_LINE_DIR)"
	make -C $(GET_NEXT_LINE_DIR)
	$(CC) $(OBJ) $(MLX_A) $(LIBFT_A) $(GET_NEXT_LINE_A) -framework OpenGL -framework AppKit -fsanitize=address -o $(NAME)
	echo "$(BLUE)$(NAME) compiled and ready to play! :D$(END_COLOR)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean: 
	$(RM) $(OBJ)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
	make clean -C $(GET_NEXT_LINE_DIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(OBJ_DIR)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(GET_NEXT_LINE_DIR)

re: fclean all
	echo "$(GREEN)Cleaned up all files for $(NAME)!"

.PHONY:		all clean fclean re
