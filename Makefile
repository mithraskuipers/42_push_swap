# ================================ VARIABLES ================================= #

# The name of your executable
NAME	= push_swap

# Compiler and compiling flags
CC	= gcc
#CFLAGS	= -Wall -Werror -Wextra
CFLAGS	= -Wall

# Debug, use with`make DEBUG=1`
ifeq ($(DEBUG),1)
CFLAGS	+= -g3 -fsanitize=address
endif

# Folder name
SRCDIR		= src/
OBJDIR		= bin/
LIBFTDIR	= libft/

SRCS = $(SRCS_PS) $(SRCS_GNL)

SRCS_GNL = 	get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c \

SRCS_PS = main.c 

LIBFTLIB	= $(LIBFTDIR)/libft.a

# String manipulation magic
SRC		:= $(notdir $(SRCS))
OBJ		:= $(SRC:.c=.o)
OBJS	:= $(addprefix $(OBJDIR), $(OBJ))

# Colors
GR	= \033[32;1m
RE	= \033[31;1m
YE	= \033[33;1m
CY	= \033[36;1m
RC	= \033[0m

# Implicit rules
VPATH := $(SRCDIR) $(OBJDIR) $(shell find $(SRCDIR) -type d)

# ================================== RULES =================================== #

all : $(NAME)

# Compiling
$(OBJDIR)%.o : %.c
	@mkdir -p $(OBJDIR)
	@printf "$(GR)+$(RC)"
	@$(CC) $(CFLAGS) -c $< -o $@

# Linking
$(NAME)	: $(LIBFTLIB) $(SRCS)  $(OBJS)
	@printf "\n$(GR)=== Compiled [$(CC) $(CFLAGS)] ===\n--- $(SRC)$(RC)\n"
	@$(CC) $(CFLAGS) $(LIBFTLIB) $(OBJS) -o $(NAME)

$(LIBFTLIB) :
	make -C $(LIBFTDIR)

# Cleaning
clean : # doe ook voor libft
	@printf "$(RE)--- Removing $(OBJDIR)$(RC)\n"
	@rm -rf $(OBJDIR)

fclean : clean # doe ook voor libft
	@printf "$(RE)--- Removing $(NAME)$(RC)\n"
	@rm -f $(NAME)

# Special rule to force to remake everything
re : fclean all # doe ook voor libft

# This runs the program
run : $(NAME)
	@printf "$(CY)>>> Running $(NAME)$(RC)\n"
	./$(NAME)

# This specifies the rules that does not correspond to any filename
.PHONY	= all run clean fclean re