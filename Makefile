# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/15 11:35:49 by bcosters          #+#    #+#              #
#    Updated: 2021/05/17 09:32:30 by bcosters         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	~ CUB 3D ~	#

# -*- Definitions of variables -*-

NAME	= cub3D

MINILIBDR	= minilibx_opengl/
OBJDR	= obj/
LIBFTDR	= libft/
DRAWDIR	= drawing_tools/

MINILIB = libmlx.dylib
CUBLIB	= libcub3d.a
HEADER	= cub3d.h

GAMESRC	= my_awesome_game.c
SRCS	= ${shell find drawing_tools -type f -name "*.c"}
SRCS	+= ${shell find parsing -type f -name "*.c"}
SRCS	+= ${shell find game_setup -type f -name "*.c"}
SRCS	+= ${shell find math_is_fun -type f -name "*.c"}
SRCS	+= ${shell find raycasting -type f -name "*.c"}
OBJS	= ${SRCS:drawing_tools/%.c=obj/%.o}
OBJS	+= ${SRCS:parsing/%.c=obj/%.o}
OBJS	+= ${SRCS:game_setup/%.c=obj/%.o}
OBJS	+= ${SRCS:math_is_fun/%.c=obj/%.o}
OBJS	+= ${SRCS:raycasting/%.c=obj/%.o}

CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

# -*- The Rules -*-

#	Implicit rules

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

obj/%.o: drawing_tools/%.c
			@echo "Compiling drawing_tools source object: $@"
			@$(CC) $(CFLAGS) -c $< -o $@

obj/%.o: parsing/%.c
			@echo "Compiling parsing source object: $@"
			@$(CC) $(CFLAGS) -c $< -o $@

obj/%.o: game_setup/%.c
			@echo "Compiling game_data source object: $@"
			@$(CC) $(CFLAGS) -c $< -o $@

obj/%.o: math_is_fun/%.c
			@echo "Compiling math_is_fun source object: $@"
			@$(CC) $(CFLAGS) -c $< -o $@

obj/%.o: raycasting/%.c
			@echo "Compiling raycasting source object: $@"
			@$(CC) $(CFLAGS) -c $< -o $@

#	Active rules -g ${wildcard drawing_tools/*.c} ${wildcard game_setup/*.c} ${wildcard raycasting/*.c}

all:		$(NAME)

libx:
			@$(MAKE) --silent -C $(MINILIBDR)
			@$(MAKE) --silent -C $(LIBFTDR)

$(NAME):	libx $(OBJDR) $(OBJS) $(HEADER)
			@ar rcs $(CUBLIB) $(OBJS)
			@echo "Compiling $(NAME)"
			@$(CC) $(CFLAGS) $(GAMESRC) -g ${wildcard drawing_tools/*.c} ${wildcard game_setup/*.c} ${wildcard raycasting/*.c} $(CUBLIB) -L$(MINILIBDR) -lmlx -framework OpenGL -framework AppKit -L$(LIBFTDR) -lft -o $(NAME)
			#--------------------------------#
			@echo "Finished compiling $(NAME)"

bonus:		re $(NAME)

$(OBJDR):
			@mkdir -p $(OBJDR)

$(LIBOBJDR):
			@mkdir -p $(LIBOBJDR)

#	Cleaning rules

clean:
			@echo Removing all object files
			@rm -rf ${OBJDR}
			@rm -rf ${LIBOBJDR}

fclean:		clean
			@echo "Removing $(NAME) and $(CUBLIB)"
			@${RM} ${NAME} ${MINILIB} ${CUBLIB}
			@echo "Removing opengl library"
			@$(MAKE) -C ${MINILIBDR} clean
			@echo "Removing libft library"
			@$(MAKE) -C ${LIBFTDR} fclean

re:			fclean all

.PHONY:		all clean fclean re
