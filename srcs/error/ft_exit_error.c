/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrieffel <lrieffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:30:58 by ugwentzi          #+#    #+#             */
/*   Updated: 2024/12/20 14:26:52 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "libft_print.h"
#include "color.h"

void	ft_exit_error(int exit_code, char *error_msg, bool is_allocated_msg)
{
	ft_fprintf(2, BOLD TOP_LOW_LINE RED "Error\n"
				RESET_COLOR "%s\n", error_msg);
	if (is_allocated_msg)
		free(error_msg);
	exit(exit_code);
}
