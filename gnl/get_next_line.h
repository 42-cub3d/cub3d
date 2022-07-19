/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:44:59 by wchae             #+#    #+#             */
/*   Updated: 2022/02/24 20:05:17 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 48
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

# define SUCCESS 1
# define END_OF_FILE 0
# define ERROR -1

int			get_next_line(int fd, char **line);
size_t		gnl_strlen(const char *str);
char		*gnl_strndup(const char *s, size_t n);
char		*gnl_strjoin(char const *s1, char const *s2);
char		*gnl_strchr(const char *str, int c);

#endif