# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eraad <eraad@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 14:33:34 by eraad             #+#    #+#              #
#    Updated: 2025/02/21 22:06:53 by eraad            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables
NAME		= push_swap
BONUS_NAME	= checker
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -ggdb3
INCLUDE		= -I./include
BONUS_INCLUDE	= -I./bonus/include

#Colors
DEF = \033[0m
Y = \033[0;93m
G = \033[0;92m
R = \033[0;91m

#Sources
SRCS_DIR	= sources/
SRC_FILES	= $(wildcard $(SRCS_DIR)error/*.c) \
			  $(wildcard $(SRCS_DIR)initialization/*.c) \
			  $(wildcard $(SRCS_DIR)log/*.c) \
			  $(wildcard $(SRCS_DIR)operations/*.c) \
			  $(wildcard $(SRCS_DIR)parsing/*.c) \
			  $(wildcard $(SRCS_DIR)sorting/*.c) \
			  $(wildcard $(SRCS_DIR)utils/*.c) \
			  $(wildcard $(SRCS_DIR)cost/*.c) \
			  $(wildcard $(SRCS_DIR)stack/*.c) \
			  $(wildcard $(SRCS_DIR)/*.c)

#Bonus
BONUS_SRCS_DIR	= bonus/sources/
BONUS_SRC_FILES	= $(wildcard $(BONUS_SRCS_DIR)*.c) \
			  $(wildcard $(BONUS_SRCS_DIR)utils/*.c) \

#Objects
OBJS_DIR	= objects/
OBJS		= $(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRC_FILES))
BONUS_OBJS_DIR	= bonus/objects/
BONUS_OBJS	= $(patsubst $(BONUS_SRCS_DIR)%.c, $(BONUS_OBJS_DIR)%.o, $(BONUS_SRC_FILES))

#Rules
all: $(NAME)

$(NAME): $(OBJS)
				@echo "$(Y)- Creating $(NAME)...$(DEF)"
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
				@echo "$(G)--- push_swap compiled succesfully! ---$(DEF)"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
				@mkdir -p $(dir $@)
				@$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

bonus: all $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
				@echo "$(Y)- Creating $(BONUS_NAME)...$(DEF)"
				@$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)
				@echo "$(G)--- checker compiled succesfully! ---$(DEF)"

$(BONUS_OBJS_DIR)%.o: $(BONUS_SRCS_DIR)%.c
				@mkdir -p $(dir $@)
				@$(CC) $(CFLAGS) $(BONUS_INCLUDE) -c -o $@ $<

clean:
				@echo "$(Y)- Cleaning object files...$(DEF)"
				@rm -rf $(OBJS_DIR)
				@rm -rf $(BONUS_OBJS_DIR)
				@echo "$(R)- Object files cleaned!$(DEF)"

fclean: clean
				@echo "$(Y)- Cleaning all build files...$(DEF)"
				@rm -f $(NAME)
				@rm -f $(BONUS_NAME)
				@echo "$(R) $(NAME) Cleaned! $(DEF)"

re: fclean $(NAME)

.PHONY: all clean fclean re bonus