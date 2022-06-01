# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mikuiper <mikuiper@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/04/15 21:13:40 by mikuiper      #+#    #+#                  #
#    Updated: 2022/06/01 13:40:56 by mikuiper      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
CFLAGS_DBG	= -g3 -fsanitize=address

INCS	=	-I./inc

SRC_DIR		= ./src/
CMD_DIR		= ./src/commands/
SORT_DIR	= ./src/sorters/
PARSE_DIR	= ./src/parser/
TOOL_DIR	= ./src/tools/

SRCS		=	$(SRC_DIR)main.c \
				$(PARSE_DIR)parse_input.c \
				$(PARSE_DIR)check_input.c \
				$(SORT_DIR)sort_stack.c \
				$(TOOL_DIR)node_tools.c \
				$(CMD_DIR)cmd_rotate.c \
				$(CMD_DIR)cmd_rrotate.c \
				$(CMD_DIR)cmd_swap.c \
				$(CMD_DIR)cmd_push.c \
				$(SORT_DIR)sort_2.c \
				$(SORT_DIR)sort_3.c \
				$(SORT_DIR)sort_4.c \
				$(SORT_DIR)sort_5.c \
				$(SORT_DIR)sort_6.c \
				$(SORT_DIR)sort_radix.c \
				$(SORT_DIR)index_stack.c \
				$(TOOL_DIR)pop_node.c \
				$(TOOL_DIR)get_node.c \
				$(TOOL_DIR)add_node.c \
				$(TOOL_DIR)clean_stack.c

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

dbg: fclean all
	@echo "\n$(GREEN)[push_swap] - Compiling $(NAME)..$(NOCOLOR)"
	@$(FT_MAKE)
	@$(CC) $(CFLAGS_DBG) $(INCS) -o $(NAME) $(OBJS) $(FT_LIB)

.c.o:
	@$(CC) $(CFLAGS) $(INCS) -c -o $@ $<

clean:
	@$(FT_MAKE) clean
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