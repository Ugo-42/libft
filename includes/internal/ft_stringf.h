/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugwentzi <ugwentzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 00:23:27 by ugwentzi          #+#    #+#             */
/*   Updated: 2025/04/16 00:27:09 by ugwentzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRINGF_H
# define FT_STRINGF_H

/*┌──────────────┐
  │ ft_stringf.c │
  └──────────────┘*/

# include <stdint.h>

void	stringf_append_ptr(t_flexistr *fs, uintptr_t addr);
void	stringf_append_str(t_flexistr *fs, char *s);

#endif
