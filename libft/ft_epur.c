#include "libft.h"

static int			is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

char		*ft_epur(char *str)
{
	char	*new;
	int		i;
	int		j;
	int		end;

	i = 0;
	j = 0;
	end = ft_strlen(str) - 1;
	new = ft_strnew(ft_strlen(str));
	while (is_space(str[i]) && str[i])
		i++;
	while (is_space(str[end]) && str[end])
		end--;
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