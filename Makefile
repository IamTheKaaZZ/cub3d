# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/15 11:35:49 by bcosters          #+#    #+#              #
#    Updated: 2021/04/20 17:26:19 by bcosters         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	~ CUB 3D ~	#

# -*- Definitions of variables -*-

NAME	= my_awesome_game

MINILIBDR	= minilibx_opengl/
OBJDR	= obj/
LIBFTDR	= libft/
DRAWDIR	= drawing_tools/

MINILIB = libmlx.dylib
HEADER	= cub3d.h

GAMESRC	= my_awesome_game.c
SRCS	= ${shell find drawing_tools -type f -name "*.c"}
OBJS	= ${SRCS:drawing_tools/%.c=obj/%.o}

CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

# -*- The Rules -*-

#	Implicit rules

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

obj/%.o: drawing_tools/%.c
			@echo "Compiling cub3D source object: $@"
			@$(CC) $(CFLAGS) -c $< -o $@

#	Active rules

all:		$(NAME)

libx:
			@$(MAKE) --silent -C $(MINILIBDR)
			@$(MAKE) --silent -C $(LIBFTDR)

$(NAME):	libx $(OBJDR) $(OBJS) $(HEADER)
			@echo "Compiling $(NAME)"
			@$(CC) $(CFLAGS) -g $(GAMESRC) $(OBJS) -L$(MINILIBDR) -lmlx -framework OpenGL -framework AppKit -L$(LIBFTDR) -lft -o $(NAME)
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
			@echo "Removing opengl library"
			@$(MAKE) -C ${MINILIBDR} clean
			@echo "Removing libft library"
			@$(MAKE) -C ${LIBFTDR} fclean

re:			fclean all

.PHONY:		all clean fclean re