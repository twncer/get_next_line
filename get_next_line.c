/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:55:22 by btuncer           #+#    #+#             */
/*   Updated: 2024/12/22 02:24:04 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*trim_buffer(char **buffer, ssize_t trim_size)
{
	char	*res;
	ssize_t	counter;

	if ((*buffer)[0] == '\0')
		return (NULL);
	res = malloc(len(*buffer) - trim_size + 1);
	if (fnot(res))
		return (NULL);
	counter = 0;
	while ((*buffer)[counter + trim_size])
	{
		res[counter] = (*buffer)[counter + trim_size];
		counter++;
	}
	res[counter] = '\0';
	free(*buffer);
	(*buffer) = res;
	return ("OK");
}

char	*gnl_eof(char **buffer)
{
	char	*res;

	if (fnot(*buffer))
		return (NULL);
	if ((*buffer)[0] == '\0')
		return (free(*buffer), NULL);
	res = malloc(len(*buffer) + 1);
	if (res == NULL)
		return (NULL);
	setstr(&res, buffer, 0);
	res[len(*buffer)] = '\0';
	free(*buffer);
	return (res);
}

char	*get_till_nl(char **buffer, bool eof)
{
	char	*res;
	ssize_t	counter;
	ssize_t	counter2;

	if ((*buffer) == NULL || (*buffer)[0] == '\0')
		return (free(*buffer), NULL);
	if (eof)
		return (gnl_eof(buffer));
	counter = 0;
	while (fnot((*buffer)[counter] == '\n') && (*buffer)[counter])
		counter++;
	res = malloc(counter + 2);
	if (res == NULL)
		return (NULL);
	counter2 = 0;
	while (counter2 < counter + 1)
	{
		res[counter2] = (*buffer)[counter2];
		counter2++;
	}
	if (trim_buffer(buffer, counter + 1) == NULL)
		return (NULL);
	res[counter2] = '\0';
	return (res);
}

char	*append_to_buffer(char **buffer, char **append)
{
	char	*temp;

	temp = malloc(len(*buffer) + len(*append) + 1);
	if (temp == NULL)
		return (NULL);
	setstr(&temp, buffer, 0);
	setstr(&temp, append, len(*buffer));
	temp[len(*buffer) + len(*append)] = '\0';
	free(*buffer);
	free(*append);
	(*buffer) = temp;
	return (*buffer);
}

char	*get_next_line(int fd)
{
	static char		*fd_content;
	static ssize_t	read_size = 1;
	char			*temp_buffer;

	if (read_size <= 0 || BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (fnot(fd_content))
	{
		fd_content = malloc(1);
		fd_content[0] = '\0';
	}
	while (fnot(in(fd_content, '\n')) && read_size > 0)
	{
		temp_buffer = malloc(BUFFER_SIZE + 1);
		if (temp_buffer == NULL)
			return (NULL);
		read_size = read(fd, temp_buffer, BUFFER_SIZE);
		if (read_size == -1)
			return (free(fd_content), free(temp_buffer), NULL);
		temp_buffer[read_size] = '\0';
		if (append_to_buffer(&fd_content, &temp_buffer) == NULL)
			return (free(temp_buffer), NULL);
	}
	return (get_till_nl(&fd_content, (read_size == 0)));
}
