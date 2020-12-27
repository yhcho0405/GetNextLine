/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:12:33 by youncho           #+#    #+#             */
/*   Updated: 2020/12/27 15:56:18 by youncho          ###   ########.fr       */
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

#endif
