/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 21:16:18 by abartell          #+#    #+#             */
/*   Updated: 2022/08/16 19:43:05 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
// fcntl is the library used for the file descriptor commands
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		gnl_strlen(const char *s);
char	*gnl_strjoin(char const *s1, char const *s2);
char	*gnl_substr(char const *s, unsigned int beginn, size_t length);
char	*gnl_strdup(void);
char	*gnl_strchr(char *s, int c);

// static char *read_file(int fd, char *buffer, char *reading)
// static char *returning(char *line)
char	*get_next_line(int fd);

#endif