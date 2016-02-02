/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 16:14:40 by mabuchwa          #+#    #+#             */
/*   Updated: 2016/02/02 12:23:55 by mabuchwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int const fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE];
	static char		*str;

	str = ft_strnew(1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		
	}

}

int		main(int ac, char **av)
{
	int const	fd;
	char		**line;

	fd = open(av[1], O_RDONLY);
	if (ac == 2)
	{
		*line = av[1];
		while (get_next_line(fd, line) == 1)
		{
			printf("%s\n", *line);
		}
		close(av[1]);
	}
	else
		write(1, "error\n", 6);
	return(0);
}
