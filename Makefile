# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eraad <eraad@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 14:33:34 by eraad             #+#    #+#              #
#    Updated: 2025/02/27 16:10:37 by eraad            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables
NAME		= push_swap
NAME_BONUS	= checker
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -ggdb3
INCLUDE		= -I./include
INCLUDE_BONUS	= -I./bonus/include_bonus

#Colors
DEF = \033[0m
Y = \033[0;93m
G = \033[0;92m
R = \033[0;91m
ORANGE = \033[38;5;208m
LIGHT_GREEN = \033[38;5;120m
NEON_GREEN = \033[38;5;82m

#Sources
SRCS_DIR		=	sources/
SRC_FILES		=	cost/compute_cost_cases.c cost/compute_cost_reverse_rotate.c cost/compute_cost_rotate.c cost/compute_cost.c \
					error/error_doubles.c \
					initialization/init_initialize.c \
					log/free_log.c log/init_log.c log/log_operations.c log/print_log.c \
					operations/push.c operations/reverse_rotate.c operations/rotate.c operations/swap.c \
					parsing/ft_atoi_long.c parsing/normalise.c \
					sorting/check_log.c sorting/do_op.c sorting/dynamic_insertion_sort.c sorting/dynamic_quick_sort.c sorting/sort_back_a.c sorting/sort_three.c \
					stack/copy_stack.c stack/free_stack.c stack/init_stack.c stack/stack_is_empty.c stack/stack_is_full.c stack/stack_is_sorted.c \
					utils/find_min_max_indexes.c utils/ft_isdigit.c utils/ft_memcpy.c utils/ft_putchar_fd.c utils/ft_putstr_fd.c utils/ft_strcmp.c utils/ft_strdup.c utils/math_log.c \
					main.c \
					push_swap.c

SRCS = $(addprefix $(SRCS_DIR), $(SRC_FILES))

#Bonus
SRCS_DIR_BONUS	=	bonus/sources_bonus/
SRC_FILES_BONUS	=	utils/error_doubles.c utils/free_log.c utils/free_stack.c utils/ft_atoi_long.c utils/ft_putchar_fd.c utils/ft_putstr_fd.c utils/ft_strcmp.c utils/get_next_line_utils.c utils/get_next_line.c utils/init_initialize.c utils/init_log.c utils/init_stack.c utils/log_operations.c utils/normalise.c utils/push.c utils/reverse_rotate.c utils/rotate.c utils/stack_is_empty.c utils/stack_is_full.c utils/stack_is_sorted.c utils/swap.c \
					checker.c \
					main.c

SRCS_BONUS = $(addprefix $(SRCS_DIR_BONUS), $(SRC_FILES_BONUS))

#Objects
OBJS_DIR		=	objects/
OBJS			=	$(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))
OBJS_DIR_BONUS	=	bonus/objects_bonus/
OBJS_BONUS		=	$(patsubst $(SRCS_DIR_BONUS)%.c, $(OBJS_DIR_BONUS)%.o, $(SRCS_BONUS))

#Rules
all: $(NAME)

$(NAME): $(OBJS)
				@echo "_________________________________________________"
				@echo "$(G)\n--- Creating $(NAME)...\n$(DEF)"
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
				@echo "$(NEON_GREEN)     ---------------------------------------$(DEF)"
				@echo "$(NEON_GREEN)     |   $(NAME) compiled succesfully!   |$(DEF)"
				@echo "$(NEON_GREEN)     ---------------------------------------$(DEF)"
				@echo "_________________________________________________\n"


$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
				@mkdir -p $(dir $@)
				@echo "$(Y)- Compiling $<...$(DEF)"
				@$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
				@echo "_________________________________________________"
				@echo "$(G)\n--- Creating $(NAME_BONUS)...\n$(DEF)"
				@$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)
				@echo "$(NEON_GREEN)     ---------------------------------------$(DEF)"
				@echo "$(NEON_GREEN)     |    $(NAME_BONUS) compiled succesfully!    |$(DEF)"
				@echo "$(NEON_GREEN)     ---------------------------------------$(DEF)"
				@echo "_________________________________________________\n"

$(OBJS_DIR_BONUS)%.o: $(SRCS_DIR_BONUS)%.c
				@mkdir -p $(dir $@)
				@echo "$(Y)- Compiling $<...$(DEF)"
				@$(CC) $(CFLAGS) $(INCLUDE_BONUS) -c -o $@ $<

clean:
				@echo "_________________________________________________"
				@echo "$(ORANGE)\n--- Cleaning objects files...\n$(DEF)"
				@rm -rf $(OBJS_DIR)
				@rm -rf $(OBJS_DIR_BONUS)
				@echo "$(R)            * Objects files cleaned!$(DEF)"
				@echo "_________________________________________________\n"


fclean: clean
				@echo "_________________________________________________"
				@echo "$(ORANGE)\n--- Cleaning programs...\n$(DEF)"
				@rm -f $(NAME)
				@rm -f $(NAME_BONUS)
				@echo "$(R)            * Programs Cleaned!$(DEF)"
				@echo "_________________________________________________\n"



re: fclean $(NAME)

re_bonus: fclean $(NAME_BONUS)

.PHONY: all clean fclean re bonus re_bonus