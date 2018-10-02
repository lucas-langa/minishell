/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 16:44:25 by llanga            #+#    #+#             */
/*   Updated: 2018/09/02 16:44:27 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list 		*multiply(t_list *node)
{
	node->content = "1*1";
	node->content_size = node->content_size;
	return (node);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *head;
	t_list *ptr;

	ptr = NULL;
	head = NULL;
	while (lst)
	{
		if (head == NULL)
			head = f(lst);
		else
		{
			ptr = f(lst);
			// ft_lstadd(&head, ptr);
			ft_lstadd(&ptr, head);
			// ptr = ptr->next;
		}
		lst = lst->next;
	}
	return (head);
}

#include <stdio.h>
int 	main(int argc, char const *argv[])
{
	t_list *node = ft_lstnew("weeb",4);
	t_list *node1 = ft_lstnew("open",4);
	ft_lstadd(&node, node1);
	t_list *node2 = ft_lstnew("aa",2);
	ft_lstadd(&node1, node2);
	t_list *node3 = ft_lstnew("poo",3);
	ft_lstadd(&node2, node3);
	t_list *x = node3;
	int i = 0;
	while (x)
	{
		printf("%d content: %s, content_size : %zu\n",i,x->content,x->content_size);
		x = x->next;
	}
	t_list *new = ft_lstmap(node3, &multiply);
	i = 0;
	while (new)
	{
		printf("%d content: %s, content_size : %zu\n",i,new->content,new->content_size);
		new = new->next;
	}
	return 0;
}