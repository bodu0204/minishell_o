/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stddef.h>
# include <signal.h>

typedef struct s_hash	t_hash;
typedef struct s_msh
{
	size_t					line_number;
	t_hash					*env;
	t_hash					*sp_var;
	t_hash					*sh_var;
	t_hash					*cache;
	volatile sig_atomic_t	signum;
}	t_msh;

#endif
