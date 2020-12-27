/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:12:33 by youncho           #+#    #+#             */
/*   Updated: 2020/12/27 17:50:26 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define R_ERR -1
# define R_EOF 0
# define R_NL 1

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

typedef struct			s_storage
{
	int					fd;
	char				buff[BUFFER_SIZE + 1];
	struct s_storage	*next;
}						t_storage;

int						get_next_line(int fd, char **line);
int						gnl_init(int fd, char **line, t_storage **head, t_storage **curr);
int						make_line(int fd, char **line, char *buffer);
int						store_line(char **line, char *buffer, int i);
size_t					ft_strlen(const char *str);
int						set_line_size(char **line, size_t len);
t_storage				*get_new_node(int fd);
t_storage				*get_current_node(int fd, t_storage *node);

#endif
