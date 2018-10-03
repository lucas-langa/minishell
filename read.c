#include "minishell.h"

void 	cd_fun(char ***envcpy, char *path)
{
	int i;
	char *temp;

	temp = NULL;
	i = 0;
	while ((*envcpy)[i])
	{
		if (!ft_strcmp((*envcpy)[i], "PWD"))
			{break ;}
		i++;
	}
	temp = ft_strdup((*envcpy)[i]);
	ft_strdel((&*envcpy)[i]);
	(*envcpy)[i] = ft_strdup(path);
	i = 0;
	while ((*envcpy)[i])
	{
		if (!ft_strcmp((*envcpy)[i], "OLDPWD"))
			{break ;}
			i++;
	}
	ft_strdel((&*envcpy)[i]);
	(*envcpy)[i] = ft_strdup(temp);
	ft_strdel(&temp);
}

int 	main(int ac,  char **av, char **env)
{
	char **args;
	char **envcp;

	ac--;
	(void)av;
	envcp = NULL;
	args = NULL;
	envcp = cpy_2darr(env);
 	while (42)
	{
		ft_putstr("$> ");
		args = get_args();
		exec_builtin(args, &envcp);
		mk_2D_arr_clean(&args);
	}
	mk_2D_arr_clean(&envcp);
	return (0);
}
