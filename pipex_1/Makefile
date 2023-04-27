SRCS	=	main.c quit.c
OBJS	=	$(SRCS:.c=.o)
CFLAGS	=	-Wall -Wextra -Werror -I.
CC		= gcc
NAME	= pipex
all		: $(NAME) clean
$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)
clean	:
	rm -f $(OBJS)
fclean	: clean
	rm -f $(NAME)
re	: fclean all
