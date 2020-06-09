/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 07:20:32 by fde-capu          #+#    #+#             */
/*   Updated: 2020/06/09 12:07:09 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# define DEBUG_FLAG		1
# define VERBOSE_FLAG	1

# include "libft.h"

# define DEB_DIV			"\t :: \t"
# define MSG_KEY_RELEASED	"Key released"
# define MSG_RX				"Resolution X"
# define MSG_RY				"Resolution Y"

# define DEBUG		debug
# define DEBSTR		debug_str
# define DEBINT		debug_int
# define VERBSTR	debug_str
# define VERBINT	debug_int
# define VERBOSE	verbose
# define DEB		debug_str_only
# define VERB		debug_str_only

int		g_debug;
int		g_verbose;

int		debug_pass(void);
void	debug(char *str, char *val, int *ival);
void	debug_body(char *str, char *val, int ival);
void	debug_int(char *str, int ival);
void	debug_str(char *str, char *val);
void	debug_str_only(char *str);

#endif
