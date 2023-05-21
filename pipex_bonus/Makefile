SRCS	=	main.c quit.c init.c run_cmds.c get_next_line/get_next_line_bonus.c get_next_line/get_next_line_utils_bonus.c split_quote.c
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
