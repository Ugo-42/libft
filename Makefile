NAME		=	libft.a

INCLUDES	=	includes

SRCS_DIR	=	srcs
SRCS		=	$(SRCS_DIR)/ft_allocation.c \
				$(SRCS_DIR)/ft_conversion.c \
				$(SRCS_DIR)/ft_count.c \
				$(SRCS_DIR)/ft_fprintf.c \
				$(SRCS_DIR)/ft_is.c \
				$(SRCS_DIR)/ft_list1.c \
				$(SRCS_DIR)/ft_list2.c \
				$(SRCS_DIR)/ft_memory1.c \
				$(SRCS_DIR)/ft_memory2.c \
				$(SRCS_DIR)/ft_other.c \
				$(SRCS_DIR)/ft_printf.c \
				$(SRCS_DIR)/ft_print_numbers.c \
				$(SRCS_DIR)/ft_print_text.c \
				$(SRCS_DIR)/ft_split_join.c \
				$(SRCS_DIR)/ft_string1.c \
				$(SRCS_DIR)/ft_string2.c

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
