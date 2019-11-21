NAME = fdf
ASSOCIATED_REP = $(NAME).dSYM

LIBFT_REP = libft/
LIBFT = libft/libft.a

INCLUDE_FLAG = -I includes/

SRCS_REP = srcs/
SRCS = colors.c \
		line_drawing.c \
		read_map.c \
		calc_coordinates.c \
		fill_pixel.c \
		grid_drawing.c \
		exit.c \
		key_events.c \
		main.c

SRC = $(addprefix $(SRCS_REP), $(SRCS))

O_SRCS = $(SRC:.c=.o)

W_FLAGS = -Wall -Werror -Wextra

MLX_FLAGS = -I /usr/X11/include -g -L /usr/X11/lib -lmlx -framework OpenGL -framework \
			AppKit

MATH_FLAG = -lm

$(NAME): $(O_SRCS)
	make -C $(LIBFT_REP)
	gcc $(INCLUDE_FLAG) $(MLX_FLAGS) $(MATH_FLAG) $(SRC) $(LIBFT) -o $(NAME)

%.o: %.c
	@gcc $(W_FLAGS) $(INCLUDE_FLAG) -c $< -o $@


all: $(NAME)

clean:
	make clean -C $(LIBFT_REP)
	rm -rf $(O_SRCS)

fclean: clean
	make fclean -C $(LIBFT_REP)
	rm -rf $(NAME) $(ASSOCIATED_REP)

re: fclean all
