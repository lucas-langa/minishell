#include "minishell.h"

void 	echo_str(char *av, char **env)
{
	int i;
	char *temp;

	temp = NULL;
	if (!av)
	{
		ft_putchar('\n');
		return ;
	}
	if (av[0] == '$')
	{
		if ((i = get_env(env, 1 + ft_strstr(av, "$"))) != -1)
			ft_putendl(1 + ft_strstr(env[i], "="));
		return ;
	}
	if (av[0] == '\"' && av[ft_strlen(av) - 1] == '\"')
	{
		temp = ft_strsub(av, 1, ft_strlen(av) - 2);
		ft_putendl(temp);
		ft_strdel(&temp);
	}
	else
		ft_putendl(av);
	return ;
}

void 	exec_builtin(char **av, char ***envcpy)
{
	if (!av)
		return ;
	else if (!ft_strcmp("exit", av[0]))
		exit(0);
	else if (!ft_strcmp("echo", av[0]))
		echo_str(av[1], *envcpy);
	else if (!ft_strcmp("/bin/pwd", av[0]))
		ft_putendl(1 + ft_strstr((*envcpy)[get_env(*envcpy, "PWD")],"=" ));
	else if (!ft_strcmp(av[0], "unsetenv") && av[1])
		rm_2d_arr_str(envcpy, av[1]);
	else if (!ft_strcmp(av[0], "setenv") && av[1])
		add_2d_arr_str(envcpy, av);
	else if (!ft_strcmp(av[0], "env"))
		ft_strarrayiter(*envcpy, &disp);
	else
		exec_sh_fun(av, envcpy);
	return ;
}
