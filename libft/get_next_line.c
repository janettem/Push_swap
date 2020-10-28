/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:38:11 by jmetelin          #+#    #+#             */
/*   Updated: 2019/11/20 14:30:33 by jmetelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	cpy_leftovers(char *buff, int start)
{
	int		index;

	index = 0;
	while (buff[start])
		buff[index++] = buff[start++];
	buff[index] = '\0';
}

static int	cpy_line(char *line, char *buff)
{
	int		index;

	index = 0;
	while (*line)
		line++;
	while (buff[index])
	{
		if (buff[index] == '\n')
		{
			*line = '\0';
			if (buff[++index] != '\0')
				cpy_leftovers(buff, index);
			else
				ft_strclr(buff);
			return (1);
		}
		*line++ = buff[index++];
	}
	*line = '\0';
	ft_strclr(buff);
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	buff[MAX_FD][BUFF_SIZE + 1];
	int			ret;

	if (!line)
		return (-1);
	*line = ft_strnew(80);
	if (!*line || fd < 0 || fd > MAX_FD || BUFF_SIZE < 1)
	{
		ft_strdel(line);
		return (-1);
	}
	if (cpy_line(*line, buff[fd]))
		return (1);
	while ((ret = read(fd, buff[fd], BUFF_SIZE)) > 0)
	{
		buff[fd][ret] = '\0';
		if (cpy_line(*line, buff[fd]))
			return (1);
	}
	if (**line != '\0')
		return (1);
	ft_strdel(line);
	return (ret);
}
