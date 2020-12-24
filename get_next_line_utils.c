/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:12:30 by youncho           #+#    #+#             */
/*   Updated: 2020/12/24 10:12:31 by youncho          ###   ########.fr       */
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

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (*s == 0)
			return ((char *)0);
		s++;
	}
	return ((char *)s);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	cnt;

	cnt = 0;
	while (*(dest + cnt) && cnt < size)
		cnt++;
	while (*src && cnt + 1 < size)
	{
		*(dest + cnt) = *src;
		src++;
		cnt++;
	}
	if (cnt < size)
		*(dest + cnt) = 0;
	while (*src)
	{
		src++;
		cnt++;
	}
	return (cnt);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int i;

	if (!dest || !src)
		return (0);
	i = 0;
	while (src[i] && size != 0 && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (size != 0)
		dest[i] = 0;
	while (src[i])
		i++;
	return (i);
}

char	*ft_strjoin_free(char const *s1, char const *s2)
{
	char	*ret;
	size_t	len;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(ret = malloc(len)))
		return (0);
	ft_strlcpy(ret, s1, len);
	ft_strlcat(ret, s2, len);
	free(s1);
	return (ret);
}
