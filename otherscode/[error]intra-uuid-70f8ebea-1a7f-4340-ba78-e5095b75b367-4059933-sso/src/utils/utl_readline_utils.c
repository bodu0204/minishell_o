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

#include "utl_readline.h"

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft.h"
#include "shell_info.h"

void	set_readline_outstream(FILE *file_stream)
{
	rl_outstream = file_stream;
}

int	redisplay_prompt(void)
{
	rl_on_new_line();
	ft_putchar_fd('\n', STDERR_FILENO);
	rl_replace_line("", 0);
	rl_redisplay();
	set_exit_status(get_sig() + 128);
	return (0);
}

int	finish_rl_input(void)
{
	if (get_sig())
	{
		ft_putchar_fd('\n', STDERR_FILENO);
		rl_done = true;
		rl_event_hook = NULL;
	}
	return (1);
}

char	*wrap_readline(char *prompt, int (*hook)(void), int (*sig_hook)(void))
{
	char	*line;

	rl_done = false;
	if (is_interactive())
	{
		rl_event_hook = (*hook);
		rl_signal_event_hook = (*sig_hook);
		line = readline(prompt);
	}
	else
		line = readline("");
	return (line);
}

char	*receive_input(char *prompt)
{
	char	*line;

	while (true)
	{
		line = wrap_readline(prompt, NULL, redisplay_prompt);
		if (!line)
			return (NULL);
		if (*line)
		{
			add_history(line);
			return (line);
		}
		ft_free_ptr((void **)&line);
	}
}
