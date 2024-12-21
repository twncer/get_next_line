/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:07:31 by btuncer           #+#    #+#             */
/*   Updated: 2024/12/22 02:09:40 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

bool	fnot(bool condition)
{
	return (!condition);
}

bool	in(char *str, char c)
{
	unsigned int	counter;

	counter = 0;
	while (str[counter])
	{
		if (str[counter] == c)
			return (true);
		counter++;
	}
	return (false);
}

ssize_t	len(char *str)
{
	ssize_t	counter;

	counter = 0;
	while (*str)
	{
		counter = counter + 1;
		str++;
	}
	return (counter);
}

void	setstr(char **a, char **b, ssize_t start)
{
	ssize_t	counter;

	counter = 0;
	while (counter < len(*b))
	{
		(*a)[counter + start] = (*b)[counter];
		counter++;
	}
}
