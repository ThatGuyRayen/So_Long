#Project Name
NAME = so_long

#Compiler &Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -O3 -I. -Iminilibx-linux -I/usr/include

#Linker Flags
LFLAGS = -Lminilibx-linux -lmlx -L/usr/lib -lXext -lX11 -lm -lz

#Directories
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft
INCLUDES = -Iinclude
#Libft
LIBFT = $(LIBFT_DIR)/libft.a

#Source &Object files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Rules
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
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

