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
SRC_PATH	:= ./src
CFLAGS		:= -Wall -Wextra -Werror -g
OBJECTS_PATH = ./obj
HEADERS     := -I $(LIBFT_PATH)

SRC_PUSH_SWAP = $(SRC_PATH)/push_swap.c $(SRC_PATH)/utils.c $(SRC_PATH)/moves.c

OBJS := $(addprefix $(OBJECTS_PATH)/, $(notdir $(SRC_PUSH_SWAP:.c=.o)))

all: $(LIBFT) $(NAME) 

$(LIBFT):
	@make -C libft --no-print-directory

$(OBJECTS_PATH):
	@mkdir -p $(OBJECTS_PATH)

$(OBJECTS_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJECTS_PATH)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS) $(LIBFT)
	@echo "Linking $@"
	@$(CC) $(CFLAGS) -o $@ $(OBJS) -L$(LIBFT_PATH) -lft

clean:
	@echo "Removendo arquivos objeto..."
	@rm -f $(LIBFT_PATH)/*.o 
	@rm -f $(OBJECTS_PATH)/*.o
	@rm -rf $(OBJECTS_PATH)

fclean: clean
	@echo "Removendo executáveis e bibliotecas..."
	@rm -f $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
