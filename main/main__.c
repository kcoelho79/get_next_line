/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-oliv <kde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:00:20 by kde-oliv          #+#    #+#             */
/*   Updated: 2021/06/21 15:52:46 by kde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	line = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		get_next_line(fd, &line);
		printf("O1:%s\n", line);
		free(line);
		get_next_line(fd, &line);
		printf("O2:%s\n", line);
		free(line);
	//	get_next_line(fd, &line);
	//	printf("O3:%s\n", line);
		close(fd);
	}
	else
		fd = open("test_1", O_RDONLY);
		get_next_line(fd, &line);
		printf("O1:%s\n", line);
	//	free(line);
		get_next_line(fd, &line);
		printf("O2:%s\n", line);
	//	free(line);
		get_next_line(fd, &line);
		printf("O3:%s\n", line);
		get_next_line(fd, &line);

		close(fd);
}
