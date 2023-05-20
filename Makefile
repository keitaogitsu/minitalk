CC		= cc
CFLAGS	= -Wall -Wextra -Werror
NAME	= minitalk
SERVER_NAME	= server
CLIENT_NAME	= client
AR		= ar r
RM		= rm -f
SERVER_SRCS	= server.c
SERVER_OBJS	= $(SERVER_SRCS:.c=.o)
CLIENT_SRCS	= client.c
CLIENT_OBJS	= $(CLIENT_SRCS:.c=.o)
MAKE = make
LIBFT_DIR = libft
FT_PRINTF_DIR = ft_printf
LIBFT_NAME = libft/libft.a
FT_PRINTF_NAME = ft_printf/libftprintf.a
SERVER_BONUS_SRCS = server_bonus.c
CLIENT_BONUS_SRCS = client_bonus.c
BONUS_SERVER_OBJS = $(SERVER_BONUS_SRCS:.c=.o)
BONUS_CLIENT_OBJS = $(CLIENT_BONUS_SRCS:.c=.o)
ifdef	BONUS_FLAG
SERVER_OBJS = $(BONUS_SERVER_OBJS)
CLIENT_OBJS = $(BONUS_CLIENT_OBJS)
endif


all:	$(NAME)
$(NAME):	$(SERVER_NAME) $(CLIENT_NAME)
$(SERVER_NAME): $(SERVER_OBJS)
	$(MAKE) -C $(FT_PRINTF_DIR)
	$(CC) $(CFLAGS) $(FT_PRINTF_NAME) $(SERVER_OBJS) -o $(SERVER_NAME)
$(CLIENT_NAME): $(CLIENT_OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(FT_PRINTF_DIR)
	$(CC) $(CFLAGS) $(LIBFT_NAME) $(FT_PRINTF_NAME) $(CLIENT_OBJS) -o $(CLIENT_NAME)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(FT_PRINTF_DIR)
	$(RM) $(SERVER_OBJS) $(CLIENT_OBJS) $(BONUS_SERVER_OBJS) $(BONUS_CLIENT_OBJS)

fclean: clean
	$(RM) $(LIBFT_NAME) $(FT_PRINTF_NAME) $(SERVER_NAME) $(CLIENT_NAME)

re:		fclean all

bonus:
	make BONUS_FLAG=1

.PHONY: all clean fclean re