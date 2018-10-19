/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_epur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 11:16:54 by llanga            #+#    #+#             */
/*   Updated: 2018/10/14 11:16:59 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

static int		lsspace(char *str)
{
	int i;

	i = 0;
	while (is_space(str[i]) && str[i])
		i++;
	return (i);
}

static int		rspace(char *str, int end)
{
	while (is_space(str[end]) && str[end])
		end--;
	return (end);
}

char		*ft_epur(char *str)
{
	char	*new;
	int		i;
	int		j;
	int		end;

	j = 0;
	end = ft_strlen(str) - 1;
	if (!str || ft_strlen(str) == 0)
		return (NULL);
	new = ft_strnew(ft_strlen(str));
	i = lsspace(str);
	end = rspace(str, end);
	while (str[i] && i <= end)
	{
		if (is_space(str[i]))
		{
			new[j++] = ' ';
			while (is_space(str[i]) && str[i])
				i++;
		}
		while (!is_space(str[i]) && str[i])
			new[j++] = str[i++];
	}
	new[i] = '\0';
	return (new);
}
