/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 16:14:40 by mabuchwa          #+#    #+#             */
/*   Updated: 2016/02/05 10:39:32 by tcharrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_last_line(char *rest, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	while (rest[i] != '\0' && rest[i] != '\n')
		i++;
	if (rest[i] == '\n')
	{
		*line = ft_strsub(rest, 0, (i));
		tmp = rest;
		rest = ft_strsub(rest, (i + 1), (ft_strlen(rest + 1) - (i - 1)));
		free(tmp);
		return (rest);
	}
	if (rest[i] == '\0' && i > 0)
	{
		tmp = rest;
		rest = ft_strnew(1);
		*line = tmp;
	}
	return (rest);
}

char	*get_line(char *rest, char **line)
{
	int				i;
	char			*tmp;

	i = 0;
	while (rest[i] != '\0')
	{
		if (rest[i] == '\n')
		{
			*line = ft_strsub(rest, 0, (i));
			tmp = rest;
			rest = ft_strsub(rest, (i + 1), (ft_strlen(rest + 1) - (i - 1)));
			free(tmp);
			return (rest);
		}
		i++;
	}
	return (rest);
}

char	*no_name(char *rest)
{
	free(rest);
	rest = NULL;
	return (rest);
}

int		get_next_line(int const fd, char **line)
{
	static char		*rest;
	int				ret;
	char			buf[BUFF_SIZE + 1];

	if (rest == NULL)
		rest = ft_strnew(1);
	if (line == NULL)
		return (-1);
	*line = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (ret < 0)
			return (-1);
		rest = ft_strjoin(rest, buf);
		rest = get_line(rest, line);
		if (*line != NULL)
			return (1);
	}
	rest = get_last_line(rest, line);
	if (*line != NULL)
		return (1);
	rest = no_name(rest);
	return (0);
}
