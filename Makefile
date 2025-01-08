# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ugwentzi <ugwentzi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 12:30:00 by ugwentzi          #+#    #+#              #
#    Updated: 2025/01/08 12:32:50 by ugwentzi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include makefile.conf/progress_bar.mk
include makefile.conf/color.mk

#=- Config -=#
NAME   = libft.a
CC     = cc
CFLAGS = -Wall -Wextra -Werror

#=- Directories -=#
SRCS_DIR = srcs
OBJS_DIR = objs

#=- Sources -=#
INCLUDES = -Iincludes

SRCS = allocation/ft_calloc.c \
       allocation/ft_free_2d_array.c \
       allocation/ft_realloc.c \
       conversion/ft_addrtoa.c \
       conversion/ft_atoi.c \
       conversion/ft_ctoa.c \
       conversion/ft_itoa.c \
       conversion/ft_tolower.c \
       conversion/ft_toupper.c \
       conversion/ft_utoa.c \
       conversion/ft_xtoa.c \
       count/ft_count_words.c \
       count/ft_count_words_quoted.c \
       count/ft_strlen.c \
       error/ft_exit_error.c \
       is/ft_isalnum.c \
       is/ft_isalpha.c \
       is/ft_isascii.c \
       is/ft_isdigit.c \
       is/ft_isprint.c \
       is/ft_isquote.c \
       is/ft_isspace.c \
       list/ft_lstadd_back.c \
       list/ft_lstadd_front.c \
       list/ft_lstclear.c \
       list/ft_lstdelone.c \
       list/ft_lstiter.c \
       list/ft_lstlast.c \
       list/ft_lstmap.c \
       list/ft_lstnew.c \
       list/ft_lstsize.c \
       maths/ft_max_strnb.c \
       maths/ft_min_strnb.c \
       maths/ft_cmp_strnb.c \
       memory/ft_bzero.c \
       memory/ft_memchr.c \
       memory/ft_memcmp.c \
       memory/ft_memcpy.c \
       memory/ft_memmove.c \
       memory/ft_memset.c \
       memory/ft_swap_address.c \
       memory/ft_swap_content.c \
       other/ft_segfault.c \
       print/ft_fprintf.c \
       print/ft_print_address_fd.c \
       print/ft_print_hex_fd.c \
       print/ft_printf.c \
       print/ft_putchar_fd.c \
       print/ft_putnbr_fd.c \
       print/ft_putstr_fd.c \
       print/ft_putstrn_fd.c \
       print/ft_putunbr_fd.c \
       read/get_next_line.c \
       skip/ft_skip_chars.c \
       skip/ft_skip_not_chars.c \
       skip/ft_skip_quoted.c \
       skip/ft_skip_spaces.c \
       skip/ft_skip_word.c \
       sorting/ft_is_sorted.c \
       sorting/ft_qsort.c \
       string/ft_split.c \
       string/ft_split_quoted.c \
       string/ft_str_ultimate_join.c \
       string/ft_strchr.c \
       string/ft_strcmp.c \
       string/ft_strcpy.c \
       string/ft_strdup.c \
       string/ft_stringf.c \
       string/ft_strjoin.c \
       string/ft_strncmp.c \
       string/ft_strncpy.c \
       string/ft_strnstr.c \
       string/ft_strrchr.c

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

#=- Rules -=#
all: $(NAME)

# Archive Creation
$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	@echo
	@printf "$(BOLD)$(GREEN)$$ $(NAME) created successfully!$(RESET_COLOR)\n"

# Objects Creation
$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@find $(SRCS_DIR) -type d | sed 's/^$(SRCS_DIR)/$(OBJS_DIR)/' | xargs mkdir -p

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(call compile_object, $(INCLUDES), $(SRCS), $(BOLD)$(YELLOW))

# Clean Rules
clean:
	@rm -rf $(OBJS_DIR)
	@printf "$(RED)$$ $(NAME): Removed objects$(RESET_COLOR)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "$(RED)$$ $(NAME): Removed $(NAME)$(RESET_COLOR)\n"

re: fclean all

.PHONY: all clean fclean re
