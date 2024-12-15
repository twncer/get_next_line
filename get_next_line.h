/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:07:33 by btuncer           #+#    #+#             */
/*   Updated: 2024/12/15 00:38:24 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <stdbool.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000000
#endif
bool	fnot(bool condition);
bool	in(char *str, char c);
int		len(char *str);
char	*get_next_line(int fd);
#endif