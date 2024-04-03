NAME	= libftprintf.a

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
COMPILE	= $(CC) $(CFLAGS)
RM		= rm -rf
AR		= ar rcs

SRCS = ft_printf.c ft_characters.c ft_numbers.c
OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(COMPILE) -I. -c $< -o $@

all:	$(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY = all clean fclean re