/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:12:30 by youncho           #+#    #+#             */
/*   Updated: 2020/12/27 16:19:56 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int		set_line_size(char **line, size_t len)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!(tmp = malloc(len + BUFFER_SIZE + 1)))
		return (0);
	while (i < len)
		tmp[i] = (*line)[i++];
	tmp[i] = 0;
	free(*line);
	*line = tmp;
	return (1);
}
