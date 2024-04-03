NAME	= libftprintf.a

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
COMPILE	= $(CC) $(CFLAGS)

AR		= ar
ARFLAGS	= rcs
ARCHIVE	= $(AR) $(ARFLAGS)
RM		= rm -rf

SRCS	= ft_put_characters.c ft_put_numbers.c ft_printf.c
OBJS	= $(SRCS:%.c=%.o)

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

%.o: %.c
	$(COMPILE) -c $< -o $@

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cp	$(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(LIBFT):
	make -C $(LIBFT_PATH) all

clean:
	make -C $(LIBFT_PATH) clean
	$(RM) $(OBJS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re libft

#create archive of all libft object files (libft.a)
#libftprintf.a = libft.a + ft_printf object files
#create copy of libft.a (libftprintf.a)
#add ft_printf object files to copy