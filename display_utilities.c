#include "minishell.h"

void        disp(char *str)
{
	if (str)
		ft_putendl(str);
}

t_list      *mk_envcpy(char **env)
{
	int i;
	t_list *head;
	t_list *node;

	i = 0;
	head = NULL;
	node = NULL;
	while (env[i] != NULL)
	{
		node = ft_lstnew(env[i]);
		ft_lstadd(&head, node);
		i++;
	}
	return (head);
}

void    ft_strarrayiter(char **arr, void(*dsp)(char *str))
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
