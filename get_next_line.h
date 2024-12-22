/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:07:33 by btuncer           #+#    #+#             */
/*   Updated: 2024/12/22 18:23:00 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdbool.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

bool	fnot(bool condition);
bool	in(char *str, char c);
ssize_t	len(char *str);
char	*get_next_line(int fd);
void	setstr(char **a, char **b, ssize_t start);
char	*conf_buffer(char **buffer, bool set);

#endif