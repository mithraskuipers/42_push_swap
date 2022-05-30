# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mikuiper <mikuiper@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/04/15 21:13:40 by mikuiper      #+#    #+#                  #
#    Updated: 2022/05/30 23:19:47 by mikuiper      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CC			= gcc
#CFLAGS		= -Wall -Wextra -Werror
#CFLAGS		= -g3 -fsanitize=address
#CFLAGS		= -g

INCS	=	-I./inc

SRC_DIR		= ./src/

SRCS		=	$(SRC_DIR)main.c \
				$(SRC_DIR)parse_input.c \
				$(SRC_DIR)check_input.c \
				$(SRC_DIR)sort_stack.c \
				$(SRC_DIR)stack_tools.c \
				$(SRC_DIR)cmd_rotate.c \
				$(SRC_DIR)cmd_rrotate.c \
				$(SRC_DIR)cmd_swap.c \
				$(SRC_DIR)cmd_push.c \
				$(SRC_DIR)sort_2.c \
				$(SRC_DIR)sort_3.c \
				$(SRC_DIR)sort_4.c \
				$(SRC_DIR)sort_5.c \
				$(SRC_DIR)sort_6.c \
				$(SRC_DIR)sort_radix.c \
				$(SRC_DIR)index_stack.c \
				$(SRC_DIR)tmp.c

OBJS		= $(SRCS:.c=.o)

FT_DIR	=	./libft/
FT_MAKE	=	$(MAKE) -C $(FT_DIR)
FT_LIB		= -L$(FT_DIR) -lft

GREEN = \033[92m
NOCOLOR = \033[0;38m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\n$(GREEN)[push_swap] - Compiling $(NAME)..$(NOCOLOR)"
	@$(FT_MAKE)
	@$(CC) $(CFLAGS) $(INCS) -o $(NAME) $(OBJS) $(FT_LIB)

.c.o:
	@$(CC) $(CFLAGS) $(INCS) -c -o $@ $<

clean:
	$(FT_MAKE) clean
	@echo "$(GREEN)[push_swap] - Running clean..$(NOCOLOR)"
	@echo "$(GREEN)[push_swap] - Removing object files..$(NOCOLOR)"
	@$(RM) $(OBJS)
	@echo "$(GREEN)[push_swap] - Finished running clean!$(NOCOLOR)"

fclean:
	@$(FT_MAKE) fclean
	@echo "$(GREEN)[push_swap] - Running fclean..$(NOCOLOR)"
	@echo "$(GREEN)[push_swap] - Removing object files..$(NOCOLOR)"
	@echo "$(GREEN)[push_swap] - Finished running fclean!$(NOCOLOR)"
	@$(RM) $(OBJS)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re