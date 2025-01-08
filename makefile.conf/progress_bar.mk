# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    progress_bar.mk                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ugwentzi <ugwentzi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 09:43:07 by ugwentzi          #+#    #+#              #
#    Updated: 2025/01/08 11:03:12 by ugwentzi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Helper function to print a progress bar
# Exemple: $(call compile_object, $(INCLUDES), $(SRCS), $(COLOR))

BAR_LENGTH := 42
PADDING    := 32

reset_count:
	$(eval COUNT := 0)

define compile_object
    @$(eval COUNT := $(shell echo $$(( $(COUNT) + 1 ))))
    @$(CC) $(CFLAGS) $(1) -c $< -o $@
    @printf "\r$(3)\bCompiling %s%*s[%-$(BAR_LENGTH)s] %d/%d$(RESET_COLOR)" \
        "$(NAME)" \
        $$(($(PADDING) - $$(echo -n "$(NAME)" | wc -c))) "" \
        $(shell printf '=%.0s' $$(seq 1 $$(echo \
	        $$(( $(BAR_LENGTH) * $(COUNT) / $(words $(2)) ))))) \
        $(COUNT) \
        $(words $(2))
    @true
endef
