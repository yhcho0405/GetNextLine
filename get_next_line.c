/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:12:27 by youncho           #+#    #+#             */
/*   Updated: 2020/12/30 22:55:24 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		make_line(char **line, char *buffer, int i) //sizing된 line에 buffer에서 개행 전까지 문자를 담고 buffer를 trim한다.
{
	int ret;
	int j;

	j = 0;
	ret = 0;
	while (((*line)[i++] = buffer[j]))
		if (buffer[j++] == '\n')
		{
			(*line)[--i] = (char)0;
			ret = 1;
			break ;
		}
	i = 0;
	while (buffer[j])
		buffer[i++] = buffer[j++];
	buffer[i] = (char)0;
	return (ret);
}

int		read_control(int fd, char **line, char *buffer)
{
	int len;
	int ret;
	int i;

	len = 1;
	while (len > 0)
	{
		if (!(set_line_size(line, (i = ft_strlen(*line)))))
			return (R_ERR);
		if ((ret = make_line(line, buffer, i)))
			return (ret);
		len = read(fd, buffer, BUFFER_SIZE);
		buffer[len] = 0;
	}
	return (R_EOF);
}

int		gnl_init(int fd, char **line, t_storage **head, t_storage **curr)
{
	if (BUFFER_SIZE <= 0 || fd < 0 || !line)
		return (FAIL);
	if (!*head && !(*head = get_new_node(fd)))
		return (FAIL);
	if (!(*curr = get_current_node(fd, *head)))
		return (FAIL);
	*line = (char *)0;
	return (SUCCESS);
}

int		get_next_line(int fd, char **line)
{
	static t_storage	*head;
	t_storage			*curr;
	int					ret;

	if (gnl_init(fd, line, &head, &curr) == FAIL) //첫 호출 head노드 정의, 현재 fd노드 curr에 저장
		return (R_ERR);
	if ((ret = read_control(fd, line, curr->buff))) //개행 전까지 파일 읽고 make_line호출
		return (ret);
	last_call_free(fd, &head); //EOF 만나면 해당 fd노드 모두 해제
	(*line)[0] = 0;
	return (R_EOF);
}
/*
(이미 읽은 부분은 해제 되었다고 가정)
1. GNL 첫번째 호출이라면 시작 노드 생성
2. 현재 fd값과 동일한 노드 검색 후 현재 노드로 저장
3. line에 현재 노드의 buffer를 복사
만약 복사 중 개행을 만나면) 복사 중지 + 현재 노드의 buffer에서 읽은 부분 제거후 리턴
만약 복사 중 개행을 만나지 못하면) read로 BUFFER_SIZE만큼 읽고 3번의 과정을 반복(단 line의 원래 있던 값의 뒤에 복사해야 함)
read 중 읽은 buffer의 크기가 1보다 작을 때) EOF라고 판단하고 해당 fd의 노드 모두 해제
*/

#include <stdio.h>
#include <fcntl.h>

int		main(void)
{
	char	*line;
	int		ret;
	int		fd;

	fd = open("test", O_RDONLY);
//	fd = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		//printf("get_next_line : %s\n", line);
		//printf("return value : %d\n\n", ret);
		free(line);
	}
	printf("%s\n", line);
	//printf("get_next_line : %s\n", line);
	//printf("return value : %d\n", ret);
	free(line);
	while (1) {}
	return (0);
}
