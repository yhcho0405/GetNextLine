/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:12:27 by youncho           #+#    #+#             */
/*   Updated: 2020/12/08 14:43:15 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int make_line_trim_buf(char *buf, char **line, int ret)
{

	return (ret);
}

int		get_next_line(int fd, char **line);
{
	static char	*buf[OPEN_MAX];
	char		buffer[BUFFER_SIZE + 1];
	size_t		len;

	if (BUFFER_SIZE <= 0 || fd < 0 || !line)
		return (R_ERR);
	while (ft_strchr(buf[fd], "\n") && 0 < (len = read(fd, &buffer, BUFFER_SIZE)))
	{
		buf[fd] = ft_strjoin(buf[fd], buffer);
	}
}
