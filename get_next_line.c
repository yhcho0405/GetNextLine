/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:12:27 by youncho           #+#    #+#             */
/*   Updated: 2020/12/24 10:42:17 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void store_buffer(t_buffer *storage, char *buff)
{

	storage->buf = ft_strjoin_free(storage->buf, buff);
}

int		get_next_line(int fd, char **line)
{
	static t_buffer	*storage[OPEN_MAX];
	char			buff[BUFFER_SIZE + 1];
	char			*prev = NULL;
	char			*ret;

	if (BUFFER_SIZE <= 0 || fd < 0 || !line)
		return (R_ERR);
	prev = storage[fd]->pre;
	while (read(fd, buff, BUFFER_SIZE) && !ft_strchr(buff, '\n'))
		storage[fd]->buf = ft_strjoin_free(storage[fd]->buf, buff);
	if (!buff[0])
		return (R_EOF);
	if (!prev)
		prev = storage[fd]->buf;
	ret =
	storage[fd]->pre = ft_strchr(storage[fd]->buf, '\n');
}
