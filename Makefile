# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgomes-l <bgomes-l@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/07 19:01:04 by bgomes-l          #+#    #+#              #
#    Updated: 2024/06/21 17:01:34 by bgomes-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := push_swap
BONUS_NAME  := checker
LIBFT       := libft/libft.a
LIBFT_PATH  := ./libft
SRC_PATH    := ./src
BONUS_PATH  := ./src_bonus
CFLAGS      := -Wall -Wextra -Werror -g
OBJECTS_PATH := ./obj
HEADERS     := -I $(LIBFT_PATH) -I ./include

SRC_PUSH_SWAP = $(SRC_PATH)/sort.c $(SRC_PATH)/moves.c \
                $(SRC_PATH)/moves_II.c $(SRC_PATH)/list_utils.c $(SRC_PATH)/stack_utils.c \
                $(SRC_PATH)/sort_II.c $(SRC_PATH)/stack_utils_II.c $(SRC_PATH)/check_args.c

SRC_PUSH_SWAP_MAIN = $(SRC_PATH)/push_swap.c
SRC_CHECKER = $(BONUS_PATH)/checker.c $(BONUS_PATH)/moves_bonus.c $(BONUS_PATH)/moves_II_bonus.c

PUSH_SWAP_OBJS := $(addprefix $(OBJECTS_PATH)/, $(notdir $(SRC_PUSH_SWAP:.c=.o)))
PUSH_SWAP_MAIN_OBJ := $(addprefix $(OBJECTS_PATH)/, $(notdir $(SRC_PUSH_SWAP_MAIN:.c=.o)))
CHECKER_OBJS := $(addprefix $(OBJECTS_PATH)/, $(notdir $(SRC_CHECKER:.c=.o))) $(PUSH_SWAP_OBJS)

all: $(LIBFT) $(NAME)

bonus: $(LIBFT) $(BONUS_NAME)

$(LIBFT):
	@make -C libft --no-print-directory

$(OBJECTS_PATH):
	@mkdir -p $(OBJECTS_PATH)

$(OBJECTS_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJECTS_PATH)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(OBJECTS_PATH)/%.o: $(BONUS_PATH)/%.c | $(OBJECTS_PATH)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(PUSH_SWAP_OBJS) $(PUSH_SWAP_MAIN_OBJ) $(LIBFT)
	@echo "Linking $@"
	@$(CC) $(CFLAGS) -o $@ $(PUSH_SWAP_OBJS) $(PUSH_SWAP_MAIN_OBJ) -L$(LIBFT_PATH) -lft

$(BONUS_NAME): $(CHECKER_OBJS) $(LIBFT)
	@echo "Linking $@"
	@$(CC) $(CFLAGS) -o $@ $(CHECKER_OBJS) -L$(LIBFT_PATH) -lft

clean:
	@echo "Removing object files..."
	@rm -f $(LIBFT_PATH)/*.o 
	@rm -f $(OBJECTS_PATH)/*.o
	@rm -rf $(OBJECTS_PATH)

fclean: clean
	@echo "Removing executables and libraries..."
	@rm -f $(NAME) $(BONUS_NAME) $(LIBFT)

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re bonus
