# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ugwentzi <ugwentzi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 12:30:00 by ugwentzi          #+#    #+#              #
#    Updated: 2025/01/09 11:49:00 by ugwentzi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include makefile.conf/progress_bar.mk
include makefile.conf/config.mk
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

SRCS = allocation/ft_calloc.c               memory/ft_memcpy.c \
       allocation/ft_free_2d_array.c        memory/ft_memmove.c \
       allocation/ft_realloc.c              memory/ft_memset.c \
       conversion/ft_addrtoa.c              memory/ft_swap_address.c \
       conversion/ft_atoi.c                 memory/ft_swap_content.c \
       conversion/ft_ctoa.c                 other/ft_segfault.c \
       conversion/ft_itoa.c                 print/ft_fprintf.c \
       conversion/ft_tolower.c              print/ft_print_address_fd.c \
       conversion/ft_toupper.c              print/ft_print_hex_fd.c \
       conversion/ft_utoa.c                 print/ft_printf.c \
       conversion/ft_xtoa.c                 print/ft_putchar_fd.c \
       count/ft_count_words.c               print/ft_putnbr_fd.c \
       count/ft_count_words_quoted.c        print/ft_putstr_fd.c \
       count/ft_strlen.c                    print/ft_putstrn_fd.c \
       error/ft_exit_error.c                print/ft_putunbr_fd.c \
       is/ft_isalnum.c                      read/get_next_line.c \
       is/ft_isalpha.c                      skip/ft_skip_chars.c \
       is/ft_isascii.c                      skip/ft_skip_not_chars.c \
       is/ft_isdigit.c                      skip/ft_skip_quoted.c \
       is/ft_isprint.c                      skip/ft_skip_spaces.c \
       is/ft_isquote.c                      skip/ft_skip_word.c \
       is/ft_isspace.c                      sorting/ft_is_sorted.c \
       list/ft_lstadd_back.c                sorting/ft_qsort.c \
       list/ft_lstadd_front.c               string/ft_split.c \
       list/ft_lstclear.c                   string/ft_split_quoted.c \
       list/ft_lstdelone.c                  string/ft_str_ultimate_join.c \
       list/ft_lstiter.c                    string/ft_strchr.c \
       list/ft_lstlast.c                    string/ft_strcmp.c \
       list/ft_lstmap.c                     string/ft_strcpy.c \
       list/ft_lstnew.c                     string/ft_strdup.c \
       list/ft_lstsize.c                    string/ft_stringf.c \
       maths/ft_max_strnb.c                 string/ft_strjoin.c \
       maths/ft_min_strnb.c                 string/ft_strncmp.c \
       maths/ft_cmp_strnb.c                 string/ft_strncpy.c \
       memory/ft_bzero.c                    string/ft_strnstr.c \
       memory/ft_memchr.c                   string/ft_strrchr.c \
       memory/ft_memcmp.c

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

#=- RULES -=#
all: $(NAME)

#=- Archive Creation -=#
$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	@printf "\n$(BOLD)$(GREEN)$$ $(NAME) created successfully!$(RESET_COLOR)\n"

#=- Objects dirs and subdirs Creation -=#
$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@find $(SRCS_DIR) -type d | sed 's/^$(SRCS_DIR)/$(OBJS_DIR)/' | xargs mkdir -p

#=- Objects Compilation -=#
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(call compile_object, $(INCLUDES), $(SRCS), $(BOLD)$(YELLOW))

#=- Clean Rules -=#
clean:
	@rm -rf $(OBJS_DIR)
	@printf "$(RED)$$ $(NAME): Removed objects$(RESET_COLOR)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "$(RED)$$ $(NAME): Removed $(NAME)$(RESET_COLOR)\n"

re: fclean all

.PHONY: all clean fclean re
