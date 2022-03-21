/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize..c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42    </var/mail/user42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:10:12 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 16:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"
#include "ft_string.h"
#include "error.h"

void	exp_create_tokens_from_str(t_exp *ctx, char *str, t_clist *tokens)
{
	exp_tokenize_quote(ctx, str, tokens);
	exp_tokenize_var(ctx, tokens);
	exp_expand_var(ctx, tokens);
	if (ctx->need_to_split)
		exp_split_by_space(ctx, tokens);
}

void	exp_tokenize_hdoc(t_exp *ctx, char *hdoc, t_clist *tokens)
{
	exp_tokenize_dquote(ctx, hdoc, tokens);
	exp_tokenize_var(ctx, tokens);
	if (ft_strchr(hdoc, '\"') || ft_strchr(hdoc, '\''))
		return ;
	exp_expand_var(ctx, tokens);
}

void	exp_tokenize_dquote(t_exp *ctx, char *str, t_clist *tokens)
{
	t_clist		*new;

	tokens = tokens->next;
	new = or_exit(ft_clstnew_add_back(tokens, NULL), ctx);
	new->data = exp_create_token(ctx, E_DQUOTE, ft_strlen(str), str);
}
