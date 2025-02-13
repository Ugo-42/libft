# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    progress_bar.mk                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ugwentzi <ugwentzi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 09:43:07 by ugwentzi          #+#    #+#              #
#    Updated: 2025/02/13 10:27:05 by ugwentzi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include makefile.conf/config.mk

# Helper function to create an exectuable with given objects and libs
# Exemple: $(call build_binary, $(NAME), $(OBJS), $(LIBS), $(COLOR))

define build_binary
	@$(eval COUNT := 0)
	@$(CC) $(CFLAGS) $(2) $(3) -o $(1)
	@printf "\n$(strip $(4))"
	@printf "$$ $(strip $(1)) created successfully!$(RESET_COLOR)\n"
endef

# Helper function to create an archive with given objects
# Exemple: $(call build_archive, $(NAME), $(OBJS), $(COLOR))

define build_archive
	@$(eval COUNT := 0)
	@ar -rcs $(1) $(2)
	@printf "\n$(strip $(3))"
	@printf "$$ $(strip $(1)) created successfully!$(RESET_COLOR)\n"
endef
