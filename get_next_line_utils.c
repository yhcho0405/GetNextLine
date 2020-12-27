/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:12:30 by youncho           #+#    #+#             */
/*   Updated: 2020/12/27 23:09:12 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *str)
{
	size_t len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int			set_line_size(char **line, size_t len)
{
	char	*tmp;
	size_t	i;

	i = -1;
	if (!(tmp = malloc(BUFFER_SIZE + len + 1)))
		return (0);
	while (++i < len)
		tmp[i] = (*line)[i];
	tmp[i] = 0;
	free(*line);
	*line = tmp;
	return (1);
}

t_storage	*get_new_node(int fd)
{
	t_storage *ret;

	if (!(ret = malloc(sizeof(t_storage))))
		return (0);
	ret->fd = fd;
	ret->next = (t_storage *)0;
	ret->buff[0] = 0;
	return (ret);
}

t_storage	*get_current_node(int fd, t_storage *node)
{
	while (node->fd != fd)
	{
		if (!node->next)
			return (node->next = get_new_node(fd));
		node = node->next;
	}
	return (node);
}

void		last_call_free(int fd, t_storage **head)
{
	t_storage	*prev;
	t_storage	*curr;

	prev = *head;
	if (prev->fd == fd)
	{
		curr = prev->next;
		free(prev);
		*head = curr;
		return ;
	}
	while (prev->next->fd != fd)
		prev = prev->next;
	curr = get_current_node(fd, *head);
	prev->next = curr->next;
	free(curr);
}
