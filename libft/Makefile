# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/08 10:32:48 by bcosters          #+#    #+#              #
#    Updated: 2021/04/20 16:08:47 by bcosters         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- MakeFile for LIBFT -*-

# -*- Variable definitions -*-

#	Project sources/objects/headers

HEADER	= libft.h

NAME	= libft.a

CC		= gcc

CFLAGS 	= -Wall -Wextra -Werror

#	Own sources/objects/headers

SRCS_OWN = ${wildcard *.c}

OBJS_OWN = ${SRCS_OWN:%.c=obj/%.o}

HEADERS_OWN = libft.h

OBJDIR = obj/

# -*- Rules -*-
#target: dependencies
#	action

#	Implicit rules

${OBJDIR}%.o : %.c
			@echo Compiling object $@
			@$(CC) -c $(CFLAGS) -I$(HEADER) $< -o $@

#	Normal rules

all:		$(NAME)

mand:		$(OBJDIR) $(OBJS) $(HEADER)
			@echo Compiling MANDATORY LIBFT
			@ar rcs $(NAME) $(OBJS)
			@echo FINISHED: Compiling MANDATORY LIBFT

bonus:		fclean $(OBJDIR) $(OBJS_BONUS) $(HEADER)
			@echo Compiling MANDATORY AND BONUS LIBFT
			@ar rcs $(NAME) $(OBJS_BONUS)
			@echo FINISHED: Compiling MANDATORY AND BONUS LIBFT

$(NAME):	$(OBJDIR) ${OBJS_OWN} ${HEADER}
			@echo "Compiling COMPLETE LIBFT (ALL + OWN FUNCTIONS)"
			@ar rcs ${NAME} ${OBJS_OWN}
			@echo "FINISHED: Compiling COMPLETE LIBFT (ALL + OWN FUNCTIONS)"

$(OBJS):		| $(OBJDIR)
$(OBJS_BONUS):	| $(OBJDIR)
$(OBJS_OWN):	| $(OBJDIR)

$(OBJDIR):
			mkdir -p $(OBJDIR)

.PHONY:		clean

clean:
			@echo Removing object files...
			@rm -rf ${OBJDIR}

fclean:		clean
			@echo Removing library file...
			@rm -f ${NAME}

re:			fclean all