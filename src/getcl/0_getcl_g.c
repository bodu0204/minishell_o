/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_getcl_g.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 10:05:01 by blyu              #+#    #+#             */
/*   Updated: 2022/09/17 10:12:48 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "getcl.h"

extern t_g	g_;

char	*getcl(void)
{
	char			*cl;
	char			*r;
	struct termios	s;

	tcgetattr(STDIN_FILENO, &s);
	s.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &s);
	g_.status = READING;
	cl = readline(PROMPT);
	if (!cl)
	{
		g_.status = EXEING;
		return (NULL);
	}
	r = gcl_std(cl, 0);
	free(cl);
	g_.status = EXEING;
	s.c_lflag |= ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &s);
	return (r);
}
