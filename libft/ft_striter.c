/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 11:48:34 by llanga            #+#    #+#             */
/*   Updated: 2018/06/15 14:25:11 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	int i;
	int s_len;

	if (s && f)
	{
		i = 0;
		s_len = ft_strlen(s);
		while (i < (s_len))
		{
			f(&s[i]);
			i++;
		}
	}
}
