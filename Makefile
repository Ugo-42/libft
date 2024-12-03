NAME		=	libft.a

INCLUDES	=	includes

SRCS_DIR	=	srcs
SRCS		=	$(SRCS_DIR)/allocation/ft_calloc.c \
			 	$(SRCS_DIR)/allocation/ft_realloc.c \
			 	$(SRCS_DIR)/allocation/ft_free_2d_array.c \
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
			 	$(SRCS_DIR)/print/ft_print_address_fd.c \
			 	$(SRCS_DIR)/print/ft_print_hex_fd.c \
			 	$(SRCS_DIR)/print/ft_printf.c \
			 	$(SRCS_DIR)/print/ft_putchar_fd.c \
			 	$(SRCS_DIR)/print/ft_putnbr_fd.c \
			 	$(SRCS_DIR)/print/ft_putstr_fd.c \
			 	$(SRCS_DIR)/print/ft_putstrn_fd.c \
			 	$(SRCS_DIR)/print/ft_putunbr_fd.c \
			 	$(SRCS_DIR)/read/get_next_line.c \
			 	$(SRCS_DIR)/string/ft_split.c \
			 	$(SRCS_DIR)/string/ft_str_ultimate_join.c \
			 	$(SRCS_DIR)/string/ft_strchr.c \
			 	$(SRCS_DIR)/string/ft_strcpy.c \
			 	$(SRCS_DIR)/string/ft_strdup.c \
			 	$(SRCS_DIR)/string/ft_strjoin.c \
			 	$(SRCS_DIR)/string/ft_strncmp.c \
			 	$(SRCS_DIR)/string/ft_strncpy.c \
			 	$(SRCS_DIR)/string/ft_strnstr.c \
			 	$(SRCS_DIR)/string/ft_strrchr.c

OBJS_DIR	=	objs
OBJS		=	$(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

# Progress Ba	
TOTAL		=	$(words $(SRCS))
COUNT		=	0
BAR_LENGTH	=	42
PADDING		=	25

# Define
YELLOW		=	\033[1;33m
GREEN		=	\033[1;32m
RED			=	\033[1;31m
RESET_COLOR	=	\033[0m

all: $(NAME)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@find $(SRCS_DIR) -type d | sed 's/^$(SRCS_DIR)/$(OBJS_DIR)/' | xargs mkdir -p

# Compile the source files
# Print a progression bar evolving according to each currently compiled file
# Credits: ugwentzi@student.42mulhouse.fr
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(eval COUNT := $(shell echo $$(( $(COUNT) + 1 ))))
	@$(CC) $(CFLAGS) $(addprefix -I, $(INCLUDES)) -c $< -o $@
	@printf "\r${YELLOW}Compiling %s%*s[%-$(BAR_LENGTH)s] %d/%d${RESET_COLOR}" \
		"$(NAME)" $$(($(PADDING) - $$(echo -n "$(NAME)" | wc -c))) "" \
		$(shell printf '=%.0s' $$(seq 1 $$(echo "$$(( $(BAR_LENGTH) * $(COUNT) / $(TOTAL) ))"))) \
		$(COUNT) $(TOTAL)
	@true

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	@echo
	@printf "${GREEN}$$ $(NAME) created successfully!${RESET_COLOR}\n"

clean:
	@rm -rf $(OBJS_DIR)
	@printf "${RED}$$ $(NAME): removing $(OBJS_DIR)${RESET_COLOR}\n"

fclean: clean
	@rm -f $(NAME)
	@printf "${RED}$$ $(NAME): removing $(NAME)${RESET_COLOR}\n"

re: fclean all

.PHONY: all clean fclean re
