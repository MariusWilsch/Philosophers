# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: verdant <verdant@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 16:01:07 by mwilsch           #+#    #+#              #
#    Updated: 2023/04/27 13:28:32 by verdant          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Marcos ##
NAME			=	philo
LIBFT			= libft/libft.a
SRC_DIR		=	src/
OBJ_DIR		=	obj/
CC				=	gcc
CFLAGS		= -pthread -fsanitize=thread -g3 # -Wall -Wextra -Werror
INC				= -I inc/
RM				=	rm -rf


## Debugging ##
ifdef DEBUG
	CFLAGS += -g -fsanitize=address
endif

## Colors ##

Reset			=	\033[0m
Black			=	\033[30m
Red				=	\033[31m
Green			=	\033[32m
Yellow		=	\033[33m
Blue			=	\033[34m
Magenta		=	\033[35m
Cyan			=	\033[36m
White			=	\033[37m

## Files ##

SRC_FILES	= main parser print_msg time dining actions

SRC				=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ				=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJF			=	test

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m


all: libft $(NAME)

$(NAME):	$(OBJ) $(LIBFT)
			@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(INC) -o $(NAME)
			@echo "$(Magenta)Philo complied$(Reset)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@$(CC) $(CFLAGS) -c $< $(INC) -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@echo "$(GREEN)Building libft ...$(RESET)"
	@$(MAKE) -C libft 

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(OBJF)
	@$(MAKE) -C libft fclean

fclean: clean
	@rm -rf $(NAME)delete
	@echo "$(RED)Cleaning ...$(RESET)"

re: fclean all

.PHONY: all clean fclean re