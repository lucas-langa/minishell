/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 08:06:00 by llanga            #+#    #+#             */
/*   Updated: 2020/01/31 11:29:53 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int g_xx = 1;

static void		xsig_handler(int x)
{
	ft_putnbr(x);
	(void)x;
	ft_putchar('\n');
	ft_putstr("\033[31m$>\033[0m");
	g_xx = 0;
	return ;
}

int				main(int ac, char **av, char **env)
{
	char	**args;
	char	**envcp;
	int		run;

	run = 42;
	(void)ac;
	(void)av;
	envcp = NULL;
	args = NULL;
	envcp = cpy_2darr(env);
	signal(SIGINT, &xsig_handler);
	ft_putstr("Welcome to mini's hell, I can do most shell things pretty well ^^.type exit to leave, Enjoy!\n");
	while (run)
	{
		ft_putstr("$> ");
		args = get_args();
		run = exec_builtin(args, &envcp);
		mk_2d_arr_clean(&args);
	}
	mk_2d_arr_clean(&envcp);
	return (0);
}
