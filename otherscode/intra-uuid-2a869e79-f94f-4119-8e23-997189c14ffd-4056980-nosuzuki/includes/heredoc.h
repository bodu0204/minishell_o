/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H
# include <stddef.h>
# include "error.h"
typedef struct s_redir	t_redir;
typedef struct s_clist	t_clist;
typedef t_clist			t_etoks;
typedef t_clist			t_procs;
typedef struct s_hdoc
{
	t_del	del;
	char	*input;
	t_clist	*lines;
	t_procs	*procs;
	t_etoks	*tokens;
}	t_hdoc;

bool	hdoc_input_lines(t_hdoc *hdoc, char *delim);
bool	heredoc(t_procs *procs);
char	*hdoc_join_lines(t_hdoc *hdoc, t_clist *lines);
size_t	hdoc_count(t_procs *procs);
void	hdoc_format_delimiter(t_hdoc *hdoc, t_redir *redir);
void	hdoc_puterr(char *delim);

#endif
