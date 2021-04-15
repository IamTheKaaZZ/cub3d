# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/15 11:35:49 by bcosters          #+#    #+#              #
#    Updated: 2021/04/15 13:19:17 by bcosters         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	~ CUB 3D ~	#

NAME	= map.cub

LIBXDR	= minilibx_mms/
OPENGLDR	= minilibx_opengl/
OBJDR	= obj/
HEADDR	= include/
LIBFTDR	= libft/

# -*- Definitions of variables -*-

#SRCS	= ${shell find src -type f -name "*.c"}
#SRCLIB	= ${shell find libft/src -type f -name "ft_*.c"}

#OBJS	= ${SRCS:src/%.c=obj/%.o}
#OBJLIB	= ${SRCLIB:libft/src/%.c=libft/obj/%.o}

#HEADER	= ${shell find include -type f -name "ft_*.h"}

CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

# -*- The Rules -*-

#	Implicit rules

obj/%.o: src/%.c
			@echo "Compiling printf object: $@"
			@$(CC) -c $< -o $@

#	Active rules

all:		minilibx #$(NAME) #test

minilibx:
			@$(MAKE) --silent -C $(LIBXDR)
			@$(MAKE) --silent -C $(OPENGLDR)
			@$(MAKE) --silent -C $(LIBFTDR)

$(NAME):	$(LIBOBJDR) $(OBJDR) $(OBJLIB) $(OBJS) $(HEADER)
			@echo "Compiling $(NAME)"
			@ar rcs $(NAME) $(OBJS) $(OBJLIB)
			#--------------------------------#
			@echo "Finished compiling $(NAME)"

bonus:		re $(NAME)

$(OBJDR):
			@mkdir -p $(OBJDR)

$(LIBOBJDR):
			@mkdir -p $(LIBOBJDR)

$(LOGDIR):
			mkdir -p $(LOGDIR)

#	Cleaning rules

clean:
			@echo Removing all object files
			@rm -rf ${OBJDR}
			@rm -rf ${LIBOBJDR}

fclean:		clean
			@echo "Removing $(NAME)"
			@${RM} ${NAME}
			@echo "Removing minilibx library"
			@$(MAKE) -C ${LIBXDR} clean
			@echo "Removing opengl library"
			@$(MAKE) -C ${OPENGLDR} clean
			@echo "Removing libft library"
			@$(MAKE) -C ${LIBFTDR} fclean

re:			fclean all

.PHONY:		all clean fclean re