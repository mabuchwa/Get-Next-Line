/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 16:14:40 by mabuchwa          #+#    #+#             */
/*   Updated: 2016/02/03 11:47:27 by mabuchwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int const fd, char **line)
{
	int				ret;
	int				i;
	char			buf[BUFF_SIZE + 1];
	char			*tmp;

	tmp = ft_strnew(1);
	i = 0;
	if (fd < 0)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(tmp, buf);
		*line = tmp;
		return (1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	int			fd;
	char		**line;

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
	else
		write(1, "error\n", 6);
	return(0);
}
