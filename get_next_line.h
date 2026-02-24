/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 17:31:36 by ethebaul          #+#    #+#             */
/*   Updated: 2026/02/24 17:56:37 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>

typedef size_t	t_sz;
typedef t_sz	(*t_read_file)(t_sz, t_sz, t_sz, t_sz, t_sz, t_sz);
typedef int		(*t_get_size)(int, struct stat *);

int		get_size(int fd, struct stat *stat);
void	*read_file(size_t size, int fd);
char	*get_next_line(int fd);

#endif