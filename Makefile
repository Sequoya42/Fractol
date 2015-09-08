#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/12 17:20:35 by rbaum             #+#    #+#              #
#    Updated: 2015/09/08 19:38:55 by rbaum            ###   ########.fr        #
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

SDL_PATH = 		./SDL2-2.0.3/

LIBSDL_PATH_ROOT = 	./libSDL2/

LIBSDL_PATH = ./libSDL2/lib/

LIBSDL =		libSDL2.a

OBJ_NAME =		$(SRC_NAME:.c=.o)

LIBFT_NAME =	libft.a

INC_NAME =		wolf.h

SRC =			$(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ =			$(addprefix $(OBJ_PATH),$(OBJ_NAME))

LIBFT =			$(addprefix $(LIBFT_PATH),$(LIBFT_NAME))

INC =			$(addprefix $(INC_PATH),$(INC_NAME))

INCSDL = 		$(LIBSDL_PATH_ROOT)include/

INCLIBFT = 		$(LIBFT_PATH)inc

SDLBIN = 		$(addprefix $(LIBSDL_PATH),$(LIBSDL))

LIBSDL_FLAG = 	-L$(LIBSDL_PATH) -lSDL2

LIBFT_FLAG = 	-L$(LIBFT_PATH) -lft

SDL_CURL = 		`curl https://www.libsdl.org/release/SDL2-2.0.3.zip -o sdl2.zip` 

all:			libft sdl $(NAME) 

$(NAME):		$(OBJ)
				@$(CC) $(LIBFT_FLAG) $(LIBSDL_FLAG) -o $@ $^
				@echo "Wolf initialised"

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c $(INC)
				@mkdir -p $(OBJ_PATH)
				@$(CC) $(CFLAG) -I$(INC_PATH) -I$(INCLIBFT) -I $(INCSDL) -o $@ -c $<

libft:			$(LIBFT)

$(LIBFT):		$(LIBFT_PATH)
				@make -C $(LIBFT_PATH)

sdl:			$(SDLBIN)

$(SDLBIN): 		
				$(SDL_CURL)
				unzip sdl2.zip
				rm sdl2.zip
				mkdir -p $(LIBSDL_PATH_ROOT)
				cd $(SDL_PATH) &&  ./configure --prefix=$(PWD)/$(LIBSDL_PATH_ROOT)
				make -C $(SDL_PATH)
				make install -C $(SDL_PATH)

clean:
				@make -C $(LIBFT_PATH) clean
				@rm -f $(OBJ)

fclean:			
				@rm -f $(OBJ)
				@make -C $(LIBFT_PATH) fclean
				rm -rf $(LIBSDL_PATH_ROOT)
				rm -rf $(SDL_PATH)
				@rm -f $(NAME)

re: 			fclean all
