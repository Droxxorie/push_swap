# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eraad <eraad@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 14:33:34 by eraad             #+#    #+#              #
#    Updated: 2025/02/21 13:52:23 by eraad            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

NAME		= push_swap
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDE		= -I./include

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
			  $(SRCS_DIR)main.c

#Objects
OBJS_DIR	= objects/
OBJS		= $(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRC_FILES))

#Rules
$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJS)
				@echo "$(Y)- Creating $(NAME)...$(DEF)"
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
				@echo "$(G)--- push_swap compiled succesfully! ---$(DEF)"

clean:
				@echo "$(Y)- Cleaning object files...$(DEF)"
				@rm -rf $(OBJS_DIR)
				@echo "$(R)- Object files cleaned!$(DEF)"

fclean: clean
				@echo "$(Y)- Cleaning all build files...$(DEF)"
				@rm -f $(NAME)
				@echo "$(R) $(NAME) Cleaned! $(DEF)"

re: fclean $(NAME)

.PHONY: all clean fclean re