/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:07:28 by btuncer           #+#    #+#             */
/*   Updated: 2024/12/15 10:27:15 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*trim_buffer(char **buffer, ssize_t trim_size)
{
	char	*res;
	ssize_t	counter;

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

char	*get_till_nl(char **buffer, ssize_t read_size)
{
	char	*res;
	ssize_t	counter;
	ssize_t	counter2;

	if (read_size == 0 && *buffer)
		return (*buffer);
	counter = 0;
	while (fnot((*buffer)[counter] == '\n'))
		counter++;
	res = malloc(counter + 2);
	if (!res)
		return (NULL);
	counter2 = 0;
	while (counter + 1 > counter2)
	{
		res[counter2] = (*buffer)[counter2];
		counter2++;
	}
	res[counter2] = '\0';
	trim_buffer(buffer, counter + 1);
	return (res);
}

char	*append_to_buffer(char **buffer, char **append)
{
	char			*new_buffer;
	unsigned int	counter;

	counter = 0;
	new_buffer = malloc(len(*buffer) + len(*append) + 1);
	if (fnot(new_buffer))
		return (NULL);
	while ((*buffer)[counter])
	{
		new_buffer[counter] = (*buffer)[counter];
		counter++;
	}
	while ((*append)[counter - len(*buffer)])
	{
		new_buffer[counter] = (*append)[counter - len(*buffer)];
		counter++;
	}
	new_buffer[counter] = '\0';
	free(*buffer);
	free(*append);
	(*buffer) = new_buffer;
	return ("OK");
}

char	*get_next_line(int fd)
{
	static char		*fd_content = NULL;
	static ssize_t	read_size = -1;
	char			*buffer;

	if (read_size == 0 || fd < 0)
		return (NULL);
	if (fd_content == NULL)
	{
		fd_content = malloc(1);
		fd_content[0] = '\0';
	}
	while (fnot(in(fd_content, '\n') || read_size == 0))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (fnot(buffer))
			return (NULL);
		read_size = read(fd, buffer, BUFFER_SIZE);
		buffer[read_size] = '\0';
		if (fnot(append_to_buffer(&fd_content, &buffer)))
			return (NULL);
	}
	return (get_till_nl(&fd_content, read_size));
}
