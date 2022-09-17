/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getcl_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 10:05:01 by blyu              #+#    #+#             */
/*   Updated: 2022/09/17 10:50:33 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETCL_BONUS_H
# define GETCL_BONUS_H
# include "../minishell_bonus.h"

char	*gcl_std(char	*cl, size_t	B);
char	*gcl_dq(char	*cl, size_t	B);
char	*gcl_sq(char	*cl, size_t	B);
char	*gcl_nc(char	*cl, size_t	B);
#endif