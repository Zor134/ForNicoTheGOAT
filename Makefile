# Nom de l'exécutable final
NAME = push_swap

# Dossiers
SRC_DIR = .
OBJ_DIR = obj
LIBFT_DIR = ./libft
INCLUDES = -I$(LIBFT_DIR) -I.

# Fichiers sources
SRCS = $(SRC_DIR)/main.c instructions.c  cross_instructions.c parsing.c

# Objets
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Flags de compilation
CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g

# Libft
LIBFT = $(LIBFT_DIR)/libft.a

# Couleurs (optionnel)
GREEN = \033[0;32m
RESET = \033[0m

all: $(NAME)

# Compilation de l'exécutable
$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)✔ Compilation réussie !$(RESET)"

# Compilation des .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compilation de la libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
