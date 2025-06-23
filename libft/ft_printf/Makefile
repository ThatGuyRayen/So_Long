NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC_NAMES = formatter.c formatter_part2.c ft_printf.c
OBJ_DIR = objs/
OBJ_NAMES = $(SRC_NAMES:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_NAMES))

HDR = ft_printf.h
HDRS = $(HDR)
all: $(NAME) $(HDRS)

$(NAME): $(OBJ_DIR) $(OBJS) $(HDRS)
	@ar rc $@ $(OBJS)
	@ranlib $@

$(OBJ_DIR):
	@mkdir $@

OBJ_DIR = objs/

$(OBJ_DIR)%.o: %.c $(HDRS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	@rm -Rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
