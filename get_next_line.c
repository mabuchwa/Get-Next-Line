/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 16:14:40 by mabuchwa          #+#    #+#             */
/*   Updated: 2016/02/04 14:48:58 by mabuchwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_line(char *str, char *tmp, char **line)
{
	int				i;
	int				j;

	i = 0;
	j = 1;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == '\n')
		{
			*line = ft_strsub(tmp, 0, (i));
//			printf("ligne = %s\n", *line);
			while (tmp[i + j] != '\0')
			{
				str = ft_strsub(tmp, i, (j + 1));
				j++;
			}
			printf("reste = %s\n", str);
			return (1);
		}
		i++;
	}
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	static char		*str;
	int				ret;
	char			buf[BUFF_SIZE + 1];
	char			*tmp;

	tmp = ft_strnew(1);
	if (fd < 0)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(tmp, buf);
		if (get_line(str, tmp, line) == 1)
		{
			free(tmp);
			tmp = NULL;
			return (1);
		}
	}
	return (0);
}

int		main(int ac, char **av)
{
	int				fd;
	char			**line;

	line = (char**)malloc(sizeof(*line));
	fd = open(av[1], O_RDONLY);
	if (ac == 2)
	{
		while (get_next_line(fd, line) == 1)
		{
			printf("%s\n", *line);
		}
		close(fd);
	}
	return (0);
}
