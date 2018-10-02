/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 12:44:09 by llanga            #+#    #+#             */
/*   Updated: 2018/09/01 12:44:11 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void	ft_lstdel(t_list **node, void (*del)(void *, size_t))
{
	t_list *mv;

	mv = *node;
	while (mv)
	{
		(*node) = (*node)->next;
		del(mv->content, mv->content_size);
		ft_memdel((void*)mv);
		mv = (*node);
	}
}