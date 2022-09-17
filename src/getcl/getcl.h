/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getcl.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 10:05:01 by blyu              #+#    #+#             */
/*   Updated: 2022/09/17 10:13:01 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETCL_H
# define GETCL_H
# include "../minishell.h"

char	*gcl_std(char	*cl, size_t	B);
char	*gcl_dq(char	*cl, size_t	B);
char	*gcl_sq(char	*cl, size_t	B);
char	*gcl_nc(char	*cl, size_t	B);
#endif