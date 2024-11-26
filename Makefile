NAME		=	libft.a

INCLUDES	=	includes

SRCS_DIR	=	srcs
SRCS		=	$(SRCS_DIR)/allocation/ft_calloc.c \
				$(SRCS_DIR)/allocation/ft_realloc.c \
				$(SRCS_DIR)/allocation/ft_strdup.c \
				$(SRCS_DIR)/conversion/ft_atoi.c \
				$(SRCS_DIR)/conversion/ft_itoa.c \
				$(SRCS_DIR)/conversion/ft_tolower.c \
				$(SRCS_DIR)/conversion/ft_toupper.c \
				$(SRCS_DIR)/count/ft_count_words.c \
				$(SRCS_DIR)/count/ft_strlen.c \
				$(SRCS_DIR)/is/ft_isalnum.c \
				$(SRCS_DIR)/is/ft_isalpha.c \
				$(SRCS_DIR)/is/ft_isascii.c \
				$(SRCS_DIR)/is/ft_isdigit.c \
				$(SRCS_DIR)/is/ft_isprint.c \
				$(SRCS_DIR)/list/ft_lstadd_back.c \
				$(SRCS_DIR)/list/ft_lstadd_front.c \
				$(SRCS_DIR)/list/ft_lstclear.c \
				$(SRCS_DIR)/list/ft_lstdelone.c \
				$(SRCS_DIR)/list/ft_lstiter.c \
				$(SRCS_DIR)/list/ft_lstlast.c \
				$(SRCS_DIR)/list/ft_lstmap.c \
				$(SRCS_DIR)/list/ft_lstnew.c \
				$(SRCS_DIR)/list/ft_lstsize.c \
				$(SRCS_DIR)/memory/ft_bzero.c \
				$(SRCS_DIR)/memory/ft_memchr.c \
				$(SRCS_DIR)/memory/ft_memcmp.c \
				$(SRCS_DIR)/memory/ft_memcpy.c \
				$(SRCS_DIR)/memory/ft_memmove.c \
				$(SRCS_DIR)/memory/ft_memset.c \
				$(SRCS_DIR)/other/ft_segfault.c \
				$(SRCS_DIR)/print/ft_fprintf.c \
				$(SRCS_DIR)/print/ft_printf.c \
				$(SRCS_DIR)/print/ft_print_address_fd.c \
				$(SRCS_DIR)/print/ft_print_hex_fd.c \
				$(SRCS_DIR)/print/ft_putchar_fd.c \
				$(SRCS_DIR)/print/ft_putnbr_fd.c \
				$(SRCS_DIR)/print/ft_putstr_fd.c \
				$(SRCS_DIR)/print/ft_putstrn_fd.c \
				$(SRCS_DIR)/print/ft_putunbr_fd.c \
				$(SRCS_DIR)/string/ft_split_join.c \
				$(SRCS_DIR)/string/ft_string1.c \
				$(SRCS_DIR)/string/ft_string2.c

OBJS_DIR	=	objs
OBJS		=	$(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

all: $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)
	find $(SRCS_DIR) -type d | sed 's/^$(SRCS_DIR)/$(OBJS_DIR)/' | xargs mkdir -p

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
