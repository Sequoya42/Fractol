#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/12 17:20:35 by rbaum             #+#    #+#              #
#    Updated: 2015/09/12 19:57:36 by rbaum            ###   ########.fr        #
#                                                                              #
#******************************************************************************#


.PHONY:			all, libft, clean, fclean, re

CC =			gcc

CFLAG =			-Wall -Wextra -Werror

NAME =			fractol

SRC_PATH =		./src/

OBJ_PATH =		./obj/

LIBFT_PATH =	./libft/

INC_PATH =		./inc/

SRC_NAME =		main.c \
				fractol.c\
				rainbow_color.c\
				event.c\
				ft_init.c\
				julia.c\

OBJ_NAME =		$(SRC_NAME:.c=.o)

LIBFT_NAME =	libft.a

INC_NAME =		fractol.h

SRC =			$(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ =			$(addprefix $(OBJ_PATH),$(OBJ_NAME))

LIBFT =			$(addprefix $(LIBFT_PATH),$(LIBFT_NAME))

INC =			$(addprefix $(INC_PATH),$(INC_NAME))

INCLIBFT = 		$(LIBFT_PATH)inc

LIBSDL_FLAG = 	 -lmlx -framework OpenGL -framework Appkit

LIBFT_FLAG = 	-L$(LIBFT_PATH) -lft

all:			libft $(NAME) 

$(NAME):		$(OBJ)
				@$(CC) $(LIBFT_FLAG) $(LIBSDL_FLAG) -o $@ $^
				@echo "Fractol initialised"

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c $(INC)
				@mkdir -p $(OBJ_PATH)
				@$(CC) $(CFLAG) -I$(INC_PATH) -I$(INCLIBFT) -o $@ -c $<

libft:			$(LIBFT)

$(LIBFT):		$(LIBFT_PATH)
				@make -C $(LIBFT_PATH)

clean:
				@make -C $(LIBFT_PATH) clean
				@rm -f $(OBJ)

fclean:			
				@rm -f $(OBJ)
				@make -C $(LIBFT_PATH) fclean
				@rm -f $(NAME)

re: 			fclean all
