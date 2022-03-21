/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEL_H
# define DEL_H
typedef struct s_hdoc	t_hdoc;
typedef struct s_lex	t_lex;
typedef struct s_parse	t_parse;
typedef struct s_proc	t_proc;
typedef struct s_redir	t_redir;
typedef struct s_exp	t_exp;
typedef struct s_etok	t_etok;
typedef struct s_cwd	t_cwd;
typedef struct s_cd		t_cd;
typedef struct s_exec	t_exec;

void	cd_del(t_cd *cd);
void	cwd_del(t_cwd *cwd);
void	etok_del(t_etok *etoken);
void	exec_del(t_exec *exec);
void	exp_del(t_exp *exp);
void	hdoc_del(t_hdoc *hdoc);
void	lex_del(t_lex *lex);
void	parse_del(t_parse *ctx);
void	proc_del(t_proc *proc);
void	redir_del(t_redir *redir);

#endif
