# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    config.mk                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ugwentzi <ugwentzi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 19:11:07 by ugwentzi          #+#    #+#              #
#    Updated: 2025/05/19 14:06:06 by ugwentzi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Set the rule all by default (for `make` without args)
.DEFAULT_GOAL := all

# Silence the `Entering/Leaving directory` message
MAKEFLAGS += --no-print-directory

# Compilation
CC     = cc
CFLAGS = -Wall -Wextra -Werror

# Comment to remove colors
CFLAGS += -D COLOR_ON

### COMPILATION FLAGS (special rules) ###

# DEBUG Mode (disabled by default)
DEBUG_FLAG :=
ifdef DEBUG
    DEBUG_FLAG = -D DEBUG=1 -g3 #-fsanitize=address,undefined
endif

CFLAGS += $(DEBUG_FLAG)
