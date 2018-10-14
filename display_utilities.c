/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 08:05:41 by llanga            #+#    #+#             */
/*   Updated: 2018/10/14 08:05:45 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	disp(char *str)
{
	if (str)
		ft_putendl(str);
}

void	ft_strarrayiter(char **arr, void (*dsp)(char *str))
{
	int i;

	i = 0;
	if (arr[i])
	{
		while (arr[i])
		{
			dsp(arr[i]);
			i++;
		}
	}
	return ;
}

int		ft_indexof(char *str, char c)
{
	if (str && c && (ft_strchr(str, c)))
		return (ft_strchr(str, c) - &str[0]);
	return (-1);
}
