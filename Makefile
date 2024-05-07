# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgomes-l <bgomes-l@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/07 19:01:04 by bgomes-l          #+#    #+#              #
#    Updated: 2024/05/07 19:59:54 by bgomes-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= push_swap
LIBFT		:= libft/libft.a
LIBFT_PATH	:= ./libft
CFLAGS		:= -Wall -Wextra -Werror

SRC_PUSH_SWAP = src/push_swap.c

all: $(LIBFT) $(NAME) 

$(LIBFT):
	@make -C libft --no-print-directory

$(NAME): $(SRC_PUSH_SWAP) $(LIBFT)
	$(CC) $(CFLAGS) $(SRC_PUSH_SWAP) -Llibft -lft -o $(NAME)

clean:
	@echo "Removendo arquivos objeto..."
	@rm -f $(LIBFT_PATH)/*.o 

fclean: clean
	@echo "Removendo executáveis e bibliotecas..."
	@rm -f $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
