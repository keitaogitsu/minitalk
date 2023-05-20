CC		= cc
CFLAGS	= -Wall -Wextra -Werror
NAME	= libftprintf.a
AR		= ar r
RM		= rm -f
SRCS	= ft_printf.c ft_print_c.c ft_print_hexa.c ft_print_int.c ft_print_pointer.c ft_print_s.c ft_print_unint.c ft_putchar.c ft_putstr.c ft_strlcpy.c ft_strlen.c ft_print_per.c
OBJS	= $(SRCS:.c=.o)
LIBNAME	= libft.h

all:	$(NAME)
$(NAME):	$(OBJS)
		$(AR) $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re