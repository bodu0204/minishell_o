/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envcl.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 10:05:01 by blyu              #+#    #+#             */
/*   Updated: 2022/09/17 10:12:22 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVCL_H
# define ENVCL_H
# include "../minishell.h"

char	*ecl_std(char *cl, size_t B);
char	*ecl_dq(char *cl, size_t B);
char	*ecl_sq(char *cl, size_t B);
char	*ecl_sp(char *cl, size_t B);
char	*ecl_env_std(char *cl, size_t B);
char	*ecl_env_dq(char *cl, size_t B);
char	*ecl_bra(char	*cl, size_t	B);
char	*extractenv(char *cl);

#endif