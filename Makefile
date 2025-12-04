NAME            = push_swap
CC              = gcc
CFLAGS          = -Wall -Wextra -Werror -g
LIBFT_DIR       = libft
FT_PRINTF_DIR   = ft_printf
LIBFT           = $(LIBFT_DIR)/libft.a
FT_PRINTF       = $(FT_PRINTF_DIR)/libftprintf.a
OBJ_DIR         = obj
SRC_DIR         = .
SRCS            = push_swap.c \
                  str_utils.c \
                  parsing.c \
                  swap.c push.c rotate.c reverse_rotate.c \
				  sort.c sort_small.c
OBJS            = $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME):$(FT_PRINTF) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) $(FT_PRINTF) -lft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

$(LIBFT):
	make bonus -C $(LIBFT_DIR)

$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re