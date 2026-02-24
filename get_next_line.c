/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 17:36:57 by ethebaul          #+#    #+#             */
/*   Updated: 2026/02/24 17:57:35 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*line;
	struct stat	size;
	int			i;

	if (get_size(fd, &size))
		return (NULL);
	if (!line)
		line = read_file(size.st_size, fd);
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			line[i] = '\0';
			line = &line[i + 1];
			return (&line[-i - 1]);
		}
		++i;
		if (line[i] == '\0')
		{
			line = &line[i];
			return (&line[-i]);
		}
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	int		fd;
// 	char	*str;

// 	fd = open("text", O_RDONLY);
// 	str = get_next_line(fd);
// 	while (str)
// 	{
// 		write(1, str, strlen(str));
// 		write(1, "\n", 1);
// 		str = get_next_line(fd);
// 	}
// 	close(fd);
// 	return (0);
// }
