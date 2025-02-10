# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbouyi <mbouyi@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 17:35:11 by mbouyi            #+#    #+#              #
#    Updated: 2025/02/10 20:48:05 by mbouyi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c check_args.c on_top.c utils.c utils2.c list.c ft_split.c initstack.c push.c reverse_rotate.c rotate.c swap.c stack.c sort_three.c
OBJS = $(SRCS:.c=.o)

SRCB = checker.c check_args.c utils.c utils2.c list.c ft_split.c initstack.c push.c reverse_rotate.c rotate.c swap.c stack.c sort_three.c on_top.c get_next_line.c
OBJB = $(SRCB:.c=.o)

NAME = push_swap
BONUS = checker

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

bonus: $(BONUS)

$(BONUS): $(OBJB)
	$(CC) $(CFLAGS) -o $(BONUS) $(OBJB)

clean:
	rm -f $(OBJS) $(OBJB)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all
