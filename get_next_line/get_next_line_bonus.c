/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:54:21 by abartell          #+#    #+#             */
/*   Updated: 2022/08/16 13:40:10 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

//is being called as long as the while loop doesnt reach the end of file (eof)
//if read doesnt work return NULL
//returns 0 at end of line
//if there is nothing to read break
//if it hits \n then it breaks the reading function
//returning the read line 
//using break to leave the loops
//fd file descriptor is integer that uniquely indentifies
//an open file of the process

static char	*read_file(int fd, char *buffer, char *reading)
{
	int		res;
	char	*temp;

	res = 1;
	while (res != 0)
	{
		res = read(fd, buffer, BUFFER_SIZE);
		if (res == -1)
			return (0);
		else if (res == 0)
			break ;
		buffer[res] = '\0';
		if (!reading)
			reading = gnl_strdup();
		temp = reading;
		reading = gnl_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (gnl_strchr(buffer, '\n'))
			break ;
	}
	return (reading);
}

//returning is being used when it hits an \n in the reading file function
// or its reaching the end of file
//copies the line until it hits another \n
//the remaining text of the file after the line is saved via
//the gnl_substr function
//is returning the line

static char	*returning(char *line)
{
	size_t	length;
	char	*reading;

	length = 0;
	while (line[length] != '\n' && line[length] != '\0')
		length++;
	if (line[length] == '\0')
		return (0);
	reading = gnl_substr(line, length + 1, gnl_strlen(line)-length);
	if (*reading == '\0')
	{
		free(reading);
		reading = NULL;
	}
	line [length + 1] = '\0';
	return (reading);
}

// checks if file descriptor is there and if it isnt a negative
// or equal 0 buffer size
//allocates size for buffer + 1 for NULL terminator
//reads from file, input of one line
//returns just one line from this string
//if there was more than one like it frees the
//allocated space in line for the next line
char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*reading[MAX_FD];

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0)
	{
		return (0);
	}
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	line = read_file(fd, buffer, reading[fd]);
	free(buffer);
	buffer = NULL;
	if (!line)
	{
		return (NULL);
	}
	reading[fd] = returning(line);
	return (line);
}
