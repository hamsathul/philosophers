# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 21:17:06 by hkunnam-          #+#    #+#              #
#    Updated: 2023/03/11 21:17:06 by hkunnam-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Philo

INC		= includes/philo.h

SRC		= 	srcs/main.c \
			srcs/init.c \
			srcs/free.c \
			srcs/process.c \
			srcs/actions.c \
			srcs/failure.c \
			srcs/utils.c \

CC		= cc

CFLAGS	= -Wall -Wextra -Werror -pthread -g

OBJS	= $(SRC:.c=.o)

# Colors
GR	= \033[32;1m
RE	= \033[31;1m
YE	= \033[33;1m
CY	= \033[36;1m
RC	= \033[0m

$(NAME): $(OBJS)
	@echo "\n$(CY)Generating philo executable...$(RC)\n"
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	@echo "$(GR)Done!$(RC)\n\n"

all: $(NAME) $(OBJS) $(INC)



clean:
	@echo "\n$(YE)Cleaning all object files...$(RC)\n"
	@rm -rf $(OBJS)
	@echo "$(RE)objects removed!$(RC)\n"

fclean: clean
	@echo "\n$(YE)Cleaning executable files...$(RC)\n"
	@rm -rf $(NAME)
	@echo "$(RE)executable removed!$(RC)\n"

re: fclean all

.silent: all

.PHONY: all clean fclean re