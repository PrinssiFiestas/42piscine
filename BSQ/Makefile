NAME = bsq

CFLAGS = -ggdb3 -fsanitize=address -fsanitize=undefined -fsanitize=leak
CFLAGS += -Wall -Wextra -Werror
SRCS = main.c map.c read.c square.c buffer.c
OBJS = $(patsubst %.c,%.o,$(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $@

$(OBJS): %.o : %.c
	cc -c $(CFLAGS) $(SRCS)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME) $(OBJS)

re: fclean all
