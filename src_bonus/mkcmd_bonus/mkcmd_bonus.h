/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mkcmd_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:23:29 by blyu              #+#    #+#             */
/*   Updated: 2022/09/17 10:50:25 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MKCMD_BONUS_H
# define MKCMD_BONUS_H
# include "../minishell_bonus.h"

char	**cmdlist(t_cmd *c, char *cl, char **ncl, size_t ll);
char	*tk_std(char *cl, size_t B);
char	*tk_dq(char *cl, size_t B);
char	*tk_sq(char *cl, size_t B);
char	*tk_ques(char *cl, size_t B, char *(*po)(char *, size_t));
size_t	tk_bralen(char *cl);
char	*extractenv(char *cl);
#endif
