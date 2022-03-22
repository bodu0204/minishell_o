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

#ifndef INPUT_H
# define INPUT_H

# include <stdio.h>
# include "libft.h"

# define HEREDOC_PROMPT		"heredoc> "
# define HEREDOC_MAX		16

// --- input.c ---
bool	analyze_input(char *command, t_dlst *token_dlst, t_dlst *cmd_dlst);

// --- lexer.c ---
bool	lexer(const char *command, t_dlst *token_dlst);

// --- parser.c ---
bool	parser(t_dlst *token_dlst, t_dlst *cmd_dlst);
bool	is_valid_syntax(t_dlst *token_dlst);

// --- expansion.c ---
bool	expansion(t_dlst *cmd_dlst);

// --- etc. ---
bool	load_heredoc(t_dlst *cmd_dlst);
bool	is_upper_limit_heardoc(t_dlst *cmd_dlst);

#endif // INPUT_H
