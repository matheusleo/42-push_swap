/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 01:11:20 by mleonard          #+#    #+#             */
/*   Updated: 2022/12/02 01:14:53 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*compute_line(char *line_raw)
{
	ssize_t	line_len;
	char	*line;
	ssize_t	index;

	if (ft_strchr(line_raw, '\n'))
		line_len = (ft_strchr(line_raw, '\n') + 1) - line_raw + 1;
	else
		line_len = ft_strlen(line_raw) + 1;
	line = (char *)malloc(sizeof(char) * line_len);
	if (!line)
		return (NULL);
	index = 0;
	while (index < line_len - 1)
	{
		line[index] = line_raw[index];
		index++;
	}
	line[index] = '\0';
	return (line);
}

char	*get_remain(char *line_raw)
{
	char	*remain;

	if (line_raw && ft_strchr(line_raw, '\n') + 1)
		remain = ft_strdup(ft_strchr(line_raw, '\n') + 1);
	else
		remain = NULL;
	free(line_raw);
	return (remain);
}

char	*mount_line(char **line_raw)
{
	char	*aux;

	aux = ft_strdup(*line_raw);
	free(*line_raw);
	*line_raw = compute_line(aux);
	return (get_remain(aux));
}

char	*create_line(char **current_line, int fd, char *temp)
{
	char	*aux;
	ssize_t	nb_read;

	if (*current_line && ft_strchr(*current_line, '\n'))
		return (mount_line(current_line));
	nb_read = read(fd, temp, BUFFER_SIZE);
	while (nb_read > 0)
	{
		temp[nb_read] = '\0';
		if (*current_line)
			aux = ft_strdup(*current_line);
		else
			aux = ft_strdup("");
		free(*current_line);
		*current_line = ft_strjoin(aux, temp);
		free(aux);
		if (*current_line && ft_strchr(*current_line, '\n'))
			return (mount_line(current_line));
		nb_read = read(fd, temp, BUFFER_SIZE);
	}
	return (NULL);
}
