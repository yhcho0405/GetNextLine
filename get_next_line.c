/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:12:27 by youncho           #+#    #+#             */
/*   Updated: 2020/12/24 09:50:05 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void store_buffer(t_buffer storage, char *buff)
{

}

int		get_next_line(int fd, char **line)
{
	static t_buffer	storage[OPEN_MAX];
	char			buff[BUFFER_SIZE + 1];

	if (BUFFER_SIZE <= 0 || fd < 0 || !line)
		return (R_ERR);
	while (read(fd, buff, BUFFER_SIZE) && !ft_strchr(buff, '\n'))
	{
		store_buffer(storage[fd], buff);
	}
}
