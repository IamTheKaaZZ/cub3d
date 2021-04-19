# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/15 11:35:49 by bcosters          #+#    #+#              #
#    Updated: 2021/04/19 15:30:26 by bcosters         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	~ CUB 3D ~	#

# -*- Definitions of variables -*-

NAME	= my_awesome_game

LIBXDR	= minilibx_mms/
OPENGLDR	= minilibx_opengl/
OBJDR	= obj/
LIBFTDR	= libft/
SRCDIR	= src/

MINILIB = libmlx.dylib
HEADER	= cub3d.h

GAMESRC	= my_awesome_game.c
SRCS	= ${shell find src -type f -name "*.c"}
OBJS	= ${SRCS:src/%.c=obj/%.o}

CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

# -*- The Rules -*-

#	Implicit rules

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

obj/%.o: src/%.c
			@echo "Compiling cub3D source object: $@"
			@$(CC) $(CFLAGS) -c $< -o $@

#	Active rules

all:		$(NAME)

minilibx:
			@$(MAKE) --silent -C $(LIBXDR)
			@cp $(LIBXDR)$(MINILIB) .
			@$(MAKE) --silent -C $(OPENGLDR)
			@$(MAKE) --silent -C $(LIBFTDR)

$(NAME):	minilibx $(OBJDR) $(OBJS) $(HEADER)
			@echo "Compiling $(NAME)"
			@$(CC) $(CFLAGS) -g $(GAMESRC) $(OBJS) -L$(LIBXDR) -lmlx -framework OpenGL -framework AppKit -L$(LIBFTDR) -lft -o $(NAME)
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
			@echo "Removing $(NAME)"
			@${RM} ${NAME} ${MINILIB}
			@echo "Removing minilibx library"
			@$(MAKE) -C ${LIBXDR} clean
			@echo "Removing opengl library"
			@$(MAKE) -C ${OPENGLDR} clean
			@echo "Removing libft library"
			@$(MAKE) -C ${LIBFTDR} fclean

re:			fclean all

.PHONY:		all clean fclean re