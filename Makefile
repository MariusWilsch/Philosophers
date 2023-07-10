TARGET := philo
SRC_DIR := src/
OBJ_DIR := obj/
CC 		:= gcc
CFLAGS := -Wall -Wextra -Werror -pthread
INC 	= -I inc/

SRC := $(wildcard $(SRC_DIR)*.c)
OBJ := $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(TARGET)

$(TARGET): $(OBJ) 
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "$(GREEN)Executable created.$(RESET)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(OBJ_DIR) inc/philo.h
	@$(CC) $(CCFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -f $(OBJ_DIR)*.o
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)Object files removed.$(RESET)"

fclean: clean
	@rm -f $(TARGET)
	@echo "$(RED)Executable removed.$(RESET)"

re: fclean $(OBJ_DIR) all