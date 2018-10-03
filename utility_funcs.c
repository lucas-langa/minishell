#include "minishell.h"

char 	*run_exe(char **env, char *exe)
{
	char **path;
	int i;
	char *temp;
	char *x;

	x = NULL;
	temp = NULL;
	path = NULL;
	if ((i = get_env(env, "PATH")) == -1)
		return (NULL);
	path = ft_strsplit(env[i], ':');
	i = 0;
	while (path[i])
	{
		x = ft_strjoin(path[i], "/");
		temp = ft_strjoin(x, exe);
		if (!access(temp, F_OK))
			break ;
		ft_strdel(&x);
		ft_strdel(&temp);
		i++;
	}
	x ? ft_strdel(&x) : 0;
	mk_2D_arr_clean(&path);
	return (temp);
}

void 	fork_this(char *exe, char **av, char **envcpy)
{
	pid_t x;
	int status;

	x = fork();
	if (x > 0)
		waitpid(x, &status, 0 | WUNTRACED);
	else if (!x)
	{	if (execve(exe, av, envcpy) == -1)
		{
			ft_putstr_fd(RED, 2);
			ft_putstr_fd(av[0], 2);
			ft_putendl_fd(" No such file or directory", 2);
			ft_putstr_fd(DEF, 2);
		}
	}
	else
	{
		ft_putendl_fd(RED, 2);
		ft_putendl_fd("fork failed", 2);
		ft_putendl_fd(BLACK, 2);
	}
	return ;
}

void 	exec_sh_fun(char **av, char ***envcpy)
{
	char *xecute;

	xecute = NULL;
	if (!ft_strcmp("ls", av[0]))
	{
		xecute = run_exe(*envcpy, av[0]);
		fork_this(xecute, av, *envcpy);
	}
	else if (!ft_strcmp("emacs", av[0]))
	{
		xecute = run_exe(*envcpy, av[0]);
		fork_this(xecute, av, *envcpy);
	}
	else if (!ft_strcmp("PWD", av[0]))
	{
		xecute = run_exe(*envcpy, av[0]);
		fork_this(xecute, av, *envcpy);
	}
	else
	{
		ft_putstr_fd(RED, 2);
		ft_putendl_fd("no such command",2);
		ft_putstr_fd(DEF, 2);
	}
	xecute ? ft_strdel(&xecute) : 0;
	// return ;	
}

char  	**get_args(void)
{
	char *line;
	char **args;
	char *temp;
	char *new;

	temp  = NULL;
	args = NULL;
	line = NULL;
	if (get_next_line(0, &line) == 1)
		temp = line ? ft_strdup(line) : NULL;
	line ? ft_strdel(&line) : 0;
	if (temp != NULL)
	{
		new = ft_epur(temp);
		ft_strdel(&temp);
		temp = ft_strdup(new);
		ft_strdel(&new);
		args = ft_strsplit(temp, ' ');
		ft_strdel(&temp);
	}
	return (args);
}