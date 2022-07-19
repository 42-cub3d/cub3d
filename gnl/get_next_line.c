/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:47:27 by wchae             #+#    #+#             */
/*   Updated: 2022/03/03 21:37:18 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_one_line(char *ptr, char**mem, char**ret)
{
	char		*tmp;

	if (ptr)
	{
		*ret = gnl_strndup(*mem, ptr - *mem);
		tmp = gnl_strndup(ptr + 1, gnl_strlen(ptr + 1));
		if (!*ret || !tmp)
			return (ERROR);
		free (*mem);
		*mem = tmp;
		return (SUCCESS);
	}
	else
	{
		if (*mem && **mem == '\0')
		{
			*ret = NULL;
			free (*mem);
		}
		else
			*ret = *mem;
		*mem = NULL;
		return (END_OF_FILE);
	}
}

static int	read_fd(int fd, char **buf, char **ret, char **mem)
{
	char	*ptr;
	char	*tmp;
	ssize_t	read_byte;

	while (1)
	{
		ptr = gnl_strchr(*mem, '\n');
		if (ptr)
			break ;
		read_byte = read(fd, *buf, BUFFER_SIZE);
		if (read_byte == -1)
			return (ERROR);
		if (read_byte == 0)
			break ;
		(*buf)[read_byte] = '\0';
		tmp = gnl_strjoin(*mem, *buf);
		if (!tmp)
			return (ERROR);
		free(*mem);
		*mem = tmp;
	}
	return (get_one_line(ptr, mem, ret));
}

int	get_next_line(int fd, char **ret)
{
	char		*buf;
	static char	*mem[OPEN_MAX + 1];
	int			status;

	if (fd < 0 || OPEN_MAX < fd || BUFFER_SIZE <= 0)
		return (ERROR);
	if (!mem[fd])
		mem[fd] = gnl_strndup("", 0);
	buf = malloc((size_t)BUFFER_SIZE + 1);
	if (!mem[fd] || !buf)
		return (ERROR);
	*ret = NULL;
	status = read_fd(fd, &buf, ret, &mem[fd]);
	free(buf);
	if (status == ERROR || status == END_OF_FILE)
	{
		free(mem[fd]);
		mem[fd] = NULL;
	}
	return (status);
}
