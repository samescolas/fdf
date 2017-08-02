NAME = fdf

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT = libs/libft/libft.a
LIB_DEPS = $(shell ls libft/*.c$)

TO_LINK = ft mlx m
LINK = -Llibs/libft -Llibs/minilibx $(foreach LIB,$(TO_LINK), -l$(LIB))

HEADERS = $(wildcard includes/*.h$)

SRCS = $(shell ls srcs/*.c$)
OBJS = $(notdir $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) .objs/*.o $(LINK) -framework OpenGL -framework AppKit -o $@

$(LIBFT): $(LIBFT_DEPS)
	make -C libs/libft

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

re : fclean all
