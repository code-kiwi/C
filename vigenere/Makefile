# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/14 16:57:32 by mhotting          #+#    #+#              #
#    Updated: 2023/09/16 00:48:10 by mhotting         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	vigenere
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra

INC_DIR		=	./includes/
INC_FILES	=	vigenere.h
INCS		=	$(addprefix $(INC_DIR), $(INC_FILES))

SRC_DIR		=	./srcs/
SRC_FILES	=	main.c				\
				utils.c				\
				utils2.c			\
				file_management.c
SRCS		=	$(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_DIR		=	./objs/
OBJ_FILES	=	$(SRC_FILES:.c=.o)
OBJS		=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -I$(INC_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCS)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
