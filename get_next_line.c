/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtruckse <jtruckse@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:29:40 by jtruckse          #+#    #+#             */
/*   Updated: 2026/01/11 21:03:33 by jtruckse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>

int		handle_rest_in_buff(char *buffer, char **line);
int		read_line(int fd, char *buffer, char **line);
void	move_buf_to_nl(char *buffer, size_t len);

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			result;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	line = NULL;
	if (buffer[0] != '\0')
	{
		if (handle_rest_in_buff(buffer, &line) == 1)
			return (line);
	}
	while (1)
	{
		result = read_line(fd, buffer, &line);
		if (result == 1)
			return (line);
		if (result == 0)
		{
			if (line && line[0] != '\0')
				return (line);
			free (line);
			return (NULL);
		}
	}
}

int	read_line(int fd, char *buffer, char **line)
{
	int		charsread;
	size_t	len_nl;
	char	*temp;
	char	*temp2;

	charsread = read(fd, buffer, BUFFER_SIZE);
	if (charsread <= 0)
		return (0);
	buffer[charsread] = '\0';
	if (!ft_strchr(buffer, '\n'))
	{
		temp = gnl_strjoin(*line, buffer);
		free(*line);
		*line = temp;
		buffer[0] = '\0';
		return (2);
	}
	len_nl = ft_len_to_char(buffer, '\n');
	temp = ft_substr(buffer, 0, len_nl);
	temp2 = gnl_strjoin(*line, temp);
	free(temp);
	free(*line);
	*line = temp2;
	move_buf_to_nl(buffer, len_nl);
	return (1);
}

void	move_buf_to_nl(char *buffer, size_t len)
{
	size_t	i;

	i = 0;
	while (buffer[i  + len])
	{
		buffer[i] = buffer[len + i];
		i++;
	}
	buffer[i] = '\0';
}

int	handle_rest_in_buff(char *buffer, char **line)
{
	int	i;

	i = 0;
	*line = malloc(ft_len_to_char(buffer, '\n') + 1);
	while (buffer[i] && buffer[i] != '\n')
	{
		(*line)[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		(*line)[i] = buffer[i];
		(*line)[i + 1] = '\0';
		move_buf_to_nl(buffer, i + 1);
		return (1);
	}
	(*line)[i] = '\0';
	buffer[0] = '\0';
	return (0);
}
