/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-oliv <kde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 10:26:51 by kde-oliv          #+#    #+#             */
/*   Updated: 2021/06/18 17:33:03 by kde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	save_line(char **c_line, char **line)
{
	size_t	len;
	char	*rest;

	len = 0;
	while ((*c_line)[len] != '\n' && (*c_line)[len] != '\0')
		len++;
	if ((*c_line)[len] == '\0')
	{
		*line = ft_strdup(*c_line);
		if (*c_line != NULL)
		{
			free(*c_line);
			*c_line = NULL;
		}
		return (0);
	}
	*line = ft_cp_blockstr(*c_line, len);
	rest = ft_strdup((*c_line) + len + 1);
	free(*c_line);
	*c_line = rest;
	return (1);
}

static int	output(char **c_line, char **line, ssize_t b_read)
{
	if (b_read == -1)
		return (-1);
	else if (b_read == 0 && *c_line == NULL)
	{
		*line = ft_strdup("");
		return (0);
	}
	return (save_line(c_line, line));
}

int	get_next_line(int fd, char **line)
{
	ssize_t		b_read;
	char		*buff;
	static char	*c_line;
	char		*swp;

	buff = malloc(sizeof(char *) * BUFFER_SIZE + 1);
	b_read = read(fd, buff, BUFFER_SIZE);
	while (b_read > 0)
	{
		buff[b_read] = '\0';
		if (c_line == NULL)
			c_line = ft_strdup(buff);
		else
		{
			swp = ft_strjoin(c_line, buff);
			free(c_line);
			c_line = swp;
		}
		if (ft_strchr(c_line, '\n'))
			break ;
		b_read = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	return (output(&c_line, line, b_read));
}
