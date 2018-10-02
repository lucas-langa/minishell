/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 17:19:40 by llanga            #+#    #+#             */
/*   Updated: 2018/09/25 13:03:18 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		reader(const int fd, char **line)
{
	char	*buf;
	int		ret;
	char	*temp;

	ret = 0;
	buf = ft_strnew(BUFF_SIZE);
	if ((read(fd, buf, 0) < 0))
		return (-1);
	if (!(*line))
		(*line) = ft_strnew(0);
	temp = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE) > 0))
	{
		temp = ft_strjoin((*line), buf);
		free((*line));
		(*line) = temp;
		if (ft_strchr(buf, '\n'))
			break ;
		ft_strclr(buf);
	}
	free(buf);
	return (ret);
}

int		sort_line(char **res, char **line, int ret, const int fd)
{
	char *temp;

	temp = NULL;
	if (res[fd])
	{
		(*line) = res[fd];
		res[fd] = ft_strchr((*line), '\n');
	}
	if (!res[fd])
		ret = reader(fd, line);
	if ((res[fd] = ft_strchr((*line), '\n')))
	{
		res[fd] = ft_strdup(res[fd] + 1);
		ft_strclr(ft_strchr((*line), '\n'));
		temp = ft_strdup((*line));
		free((*line));
		(*line) = temp;
	}
	return (ret);
}

int		get_next_line(const int fd, char **line)
{
	static char *res[255];
	int			ret;
	char		*temp;

	temp = NULL;
	ret = 1;
	if (fd < 0 || !line || (read(fd, temp, 0) < 0) || (BUFF_SIZE < 1))
		return (-1);
	(*line) = NULL;
	ret = sort_line(res, line, ret, fd);
	if (ret > 0 || ft_strlen((*line)))
		return (1);
	return (ret);
}