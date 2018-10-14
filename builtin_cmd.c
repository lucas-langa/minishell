/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 08:05:31 by llanga            #+#    #+#             */
/*   Updated: 2018/10/14 08:05:35 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		exec_builtin(char **av, char ***envcpy)
{
	if (!av)
		return (42);
	if (av[0][0] == '/')
		fork_this(NULL, av, *envcpy);
	else if (!ft_strcmp("echo", av[0]))
		echo_str(av, *envcpy);
	else if (!ft_strcmp("/bin/pwd", av[0]))
		ft_putendl(1 + ft_strstr((*envcpy)[get_env(*envcpy, "PWD")], "="));
	else if (!ft_strcmp(av[0], "unsetenv") && av[1])
		rm_2d_arr_str(envcpy, av[1]);
	else if (!ft_strcmp(av[0], "setenv") && av[1])
		add_2d_arr_str(envcpy, av);
	else if (!ft_strcmp(av[0], "env"))
		ft_strarrayiter(*envcpy, &disp);
	else if (!ft_strcmp("exit", av[0]))
		return (0);
	else if (!ft_strcmp(av[0], "cd"))
		cd_fun(envcpy, av[1]);
	else
		exec_sh_fun(av, envcpy);
	return (42);
}
