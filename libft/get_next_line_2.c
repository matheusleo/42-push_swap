/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 01:14:23 by mleonard          #+#    #+#             */
/*   Updated: 2022/12/02 01:14:24 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**get_next_line_2(int fd)
{
	static char	*remain[1024];
	char		*current_line;
	char		*temp;
	char		**result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!remain[fd] || ft_strlen(remain[fd]) == 0)
		current_line = NULL;
	else
		current_line = ft_strdup(remain[fd]);
	free(remain[fd]);
	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	remain[fd] = create_line(&current_line, fd, temp);
	if (!remain[fd])
		free(remain[fd]);
	free(temp);
	result = (char **)malloc(sizeof(char *) * 2);
	result[0] = current_line;
	result[1] = remain[fd];
	return (result);
}
