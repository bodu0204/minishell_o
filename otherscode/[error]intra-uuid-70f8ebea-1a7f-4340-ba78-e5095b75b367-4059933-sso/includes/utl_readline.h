/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xxx                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxx                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: xxxx/xx/xx xx:xx:xx by xxx               #+#    #+#             */
/*   Updated: xxxx/xx/xx xx:xx:xx by xxx              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTL_READLINE_H
# define UTL_READLINE_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

// --- utl_readline.c ---
char	*receive_input(char *prompt);
char	*wrap_readline(char *prompt, int (*hook)(void), int (*sig_hook)(void));
void	set_readline_outstream(FILE *file_stream);
int		redisplay_prompt(void);
int		finish_rl_input(void);

#endif // UTL_READLINE
