NAME = fdf

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT = libs/libft/libft.a
LIB_DEPS = $(shell ls libft/*.c$)

MLX1 = libs/minilibx/libmlx.a
MLX2 = libs/minilibx_macos/libmlx.a

TO_LINK = ft mlx m
LINK = -Llibs/libft -Llibs/minilibx $(foreach LIB,$(TO_LINK), -l$(LIB))

HEADERS = $(wildcard includes/*.h$)

SRCS = $(shell ls srcs/*.c$)
OBJS = $(notdir $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS) $(MLX1) $(MLX2)
	$(CC) .objs/*.o $(LINK) -framework OpenGL -framework AppKit -o $@

$(LIBFT): $(LIBFT_DEPS)
	make -C libs/libft

$(MLX1):
	make -C libs/minilibx

$(MLX2):
	make -C libs/minilibx_macos

$(OBJS): $(SRCS) $(HEADERS) $(LIBFT)
	$(CC) $(CFLAGS) -Iincludes -c $(shell find . -name $(notdir $(@:.o=.c))) -o .objs/$@

.PHONY : clean fclean re print

print :
	@echo $(OBJS)

clean :
	rm -f libft/*\.o$
	rm -f .objs/*\.o$

fclean : clean
	rm -f $(LIBFT)
	rm -f $(NAME)
	rm -f $(MLX1)
	rm -f $(MLX2)

re : fclean all
