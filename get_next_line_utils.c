/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 17:36:55 by ethebaul          #+#    #+#             */
/*   Updated: 2026/02/24 17:55:40 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_size(int fd, struct stat *stat)
{
	volatile t_sz	result;

	result = (t_sz)get_size;
	while (*(t_sz *)result != 0xc3050f58056a)
		result++;
	result = ((t_get_size)result)(fd, stat);
	return (result);
}

void	*read_file(t_sz size, int fd)
{
	volatile t_sz	start;
	volatile t_sz	end;

	start = (t_sz)read_file;
	while (*(t_sz *)start != 0xc3050f5a4158d1ff)
		start++;
	end = (t_sz)read_file;
	while (*(t_sz *)end != 0xc350096a026a58)
		end++;
	start = ((t_read_file)start)(0, size + sizeof(size_t), 0x3, end, fd, 0);
	return ((void *)start);
}
