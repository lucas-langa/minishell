/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 11:18:29 by llanga            #+#    #+#             */
/*   Updated: 2018/09/01 11:18:30 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(char *content)
{
	t_list *node;

	node = NULL;
	if (!(node = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		node->content = NULL;
		node->next = NULL;
		return (node);
	}
	else
	{
		node->content = ft_strdup(content);
		node->next = NULL;
		return (node);
	}
}