# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 16:01:07 by mwilsch           #+#    #+#              #
#    Updated: 2023/01/23 16:10:34 by mwilsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Marcos ##
NAME			=	philo
SRC_DIR		=	src/
OBJ_DIR		=	obj/
CC				=	gcc
CFLAGS		= -pthread 
HEADERS 	= -I inc
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

SRC_FILES	= philo

SRC				=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ				=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJF			=	test

all:	$(NAME)

$(NAME):	$(OBJ)
			@$(CC) $(CLFAGS) $(OBJ) $(HEADERS) $(NAME)
			@echo "$(Magenta)Philo complied$(Reset)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@$(CC) $(CFLAGS) -c $< $(HEADERS) -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)
	@echo "$(Red)All libs cleaned$(Reset)"

re: fclean start
	@echo "$(Yellow)Recomplied everything$(Reset)"

.PHONY: all clean fclean re