NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -O3 -I. -Iminilibx-linux -I/usr/include

LFLAGS = -Lminilibx-linux -lmlx -L/usr/lib -lXext -lX11 -lm -lz

SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft
INCLUDES = -Iinclude
LIBFT = $(LIBFT_DIR)/libft.a



SRCS_DIR = draw.c free.c game_and_events.c initialize.c main.c map_checker.c map_checker_structs.c player_moves.c player_moves_2.c utils.c
SRCS = $(addprefix $(SRC_DIR)/, $(SRCS_DIR))
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(MAKE) -C minilibx-linux
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) -o $(NAME) $(LFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) -r $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

