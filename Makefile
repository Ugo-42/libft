NAME		=	libft.a

INCLUDES	=	includes

SRCS_DIR	=	srcs
SRCS		=	$(SRCS_DIR)/ft_allocation_functions.c \
				$(SRCS_DIR)/ft_conversions.c \
				$(SRCS_DIR)/ft_count_functions.c \
				$(SRCS_DIR)/ft_fprintf.c \
				$(SRCS_DIR)/ft_is_functions.c \
				$(SRCS_DIR)/ft_list_functions1.c \
				$(SRCS_DIR)/ft_list_functions2.c \
				$(SRCS_DIR)/ft_mem_functions.c \
				$(SRCS_DIR)/ft_other_functions.c \
				$(SRCS_DIR)/ft_print_numbers.c \
				$(SRCS_DIR)/ft_print_text.c \
				$(SRCS_DIR)/ft_printf.c \
				$(SRCS_DIR)/ft_split_join.c \
				$(SRCS_DIR)/ft_string_copy_functions.c \
				$(SRCS_DIR)/ft_string_functions.c

OBJS_DIR	=	objs
OBJS		=	$(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

all: $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	rm -fr $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
