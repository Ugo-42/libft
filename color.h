/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <ugwentzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:51:56 by ugwentzi          #+#    #+#             */
/*   Updated: 2024/12/20 12:23:04 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

/* Text Styles */
# define RESET_COLOR	"\033[0m"
# define BOLD			"\033[1m"
# define DIM			"\033[2m"
# define ITALIC			"\033[3m"
# define UNDERLINE		"\033[4m"
# define BLINK			"\033[5m"
# define REVERSE		"\033[7m"
# define HIDDEN			"\033[8m"
# define STRIKE			"\033[9m"
# define D_UNDERLINE	"\033[21m"
# define TOP_LINE		"\033[53m"
# define TOPLOW_LINE	"\033[4;53m"

/* Text Basic Colors */
# define BLACK			"\033[30m"
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define BLUE			"\033[34m"
# define MAGENTA		"\033[35m"
# define CYAN			"\033[36m"
# define WHITE			"\033[37m"

/* Text High Intensity Colors */
# define I_BLACK		"\033[90m"
# define I_RED			"\033[91m"
# define I_GREEN		"\033[92m"
# define I_YELLOW		"\033[93m"
# define I_BLUE			"\033[94m"
# define I_MAGENTA		"\033[95m"
# define I_CYAN			"\033[96m"
# define I_WHITE		"\033[97m"

/* Background Colors */
# define B_BLACK		"\033[40m"
# define B_RED			"\033[41m"
# define B_GREEN		"\033[42m"
# define B_YELLOW		"\033[43m"
# define B_BLUE			"\033[44m"
# define B_MAGENTA		"\033[45m"
# define B_CYAN			"\033[46m"
# define B_WHITE		"\033[47m"

/* Background High Intensity Colors */
# define BI_BLACK		"\033[100m"
# define BI_RED			"\033[101m"
# define BI_GREEN		"\033[102m"
# define BI_YELLOW		"\033[103m"
# define BI_BLUE		"\033[104m"
# define BI_MAGENTA		"\033[105m"
# define BI_CYAN		"\033[106m"
# define BI_WHITE		"\033[107m"

/* RGB Colors */
# define RGB(r, g, b)	"\033[38;2;"#r";"#g";"#b"m"
# define B_RGB(r, g, b)	"\033[48;2;"#r";"#g";"#b"m"

/* Hex Colors */
# define XRGB(hex) \
   	RGB(((hex) >> 16) & 0xFF, ((hex) >> 8) & 0xFF, (hex) & 0xFF)
# define B_XRGB(hex) \
	B_RGB(((hex) >> 16) & 0xFF, ((hex) >> 8) & 0xFF, (hex) & 0xFF)

#endif
