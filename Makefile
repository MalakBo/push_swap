# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbouyi <mbouyi@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 17:35:11 by mac               #+#    #+#              #
#    Updated: 2025/02/07 23:22:58 by mbouyi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c check_args.c h.c initstack_a.c ft_atoi.c ft_error.c ft_isdigit.c ft_lstaddback.c ft_lstnew.c ft_split.c ft_strchr.c push.c reverse_rotate.c rotate.c swap.c stack.c sort_stack.c sort_three.c
OBJS = $(SRCS:.c=.o)
BONUS = checker.c check_args.c ft_strcmp.c initstack_a.c ft_atoi.c ft_error.c ft_isdigit.c ft_lstaddback.c ft_lstnew.c ft_split.c ft_strchr.c push.c reverse_rotate.c rotate.c swap.c stack.c sort_stack.c sort_three.c
OBJB = $(BONUS: .c=.o)
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
