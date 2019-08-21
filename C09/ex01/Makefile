# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: shamlaou <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/08/20 19:05:41 by shamlaou     #+#   ##    ##    #+#        #
#    Updated: 2019/08/21 17:33:17 by shamlaou    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libft.a

HEADER = ./includes/

SRCS = srcs/ft_putchar.c\
	   srcs/ft_swap.c\
	   srcs/ft_putstr.c\
	   srcs/ft_strlen.c\
	   srcs/ft_strcmp.c

OBJS = $(SRCS:.c=.o)

CC = gcc 

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -I ${HEADER}

$(NAME) : $(OBJS)
		ar rc ${NAME} ${OBJS}
		ranlib ${NAME}

.c.o:
		$(CC) ${CFLAGS} -c $< -o ${<:.c=.o}

all : $(NAME)

clean : 
		$(RM) $(OBJS)
	
fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY: all clean re fclean
