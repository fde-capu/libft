/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 07:20:32 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/09 08:13:00 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# define DEBUG_FLAG		1
# define VERBOSE_FLAG	1

# include "libft.h"

# define DEB_DIV		"\t :: \t"
# define KEY_RELEASED	"Key released"
# define RX				"Resolution X"
# define RY				"Resolution Y"

# define DEBUG		debug
# define VERBOSE	verbose
# define DEB		debug_str
# define VERB		debug_str

int		g_debug;
int		g_verbose;

int		debug_pass(void);
void	debug(char *str, char *val, int ival);
void	debug_str(char *str);

#endif
