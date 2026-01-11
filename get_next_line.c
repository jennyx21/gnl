/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtruckse <jtruckse@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:29:40 by jtruckse          #+#    #+#             */
/*   Updated: 2026/01/11 16:05:34 by jtruckse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int handle_rest_in_buff(char *buffer, char **line);
int read_line(int fd, char *buffer, char **line);
void move_buf_to_nl(char *buffer, size_t len);

char	*get_next_line(int fd)
{
	static char buffer[BUFFERSIZE + 1];
	char		*line;
	int			result;
	
	if(BUFFERSIZE <= 0 || fd < 0)
		return(0);
	line = NULL;
	if(buffer[0] != '\0')
	{
		if(handle_rest_in_buff(buffer, &line) == 1)
		return(line);
	}
	while(1)
	{
		result = read_line(fd, buffer, &line);
		if(result == 1)
			return(line);
		if(result == 0)
		{
			if(line && line[0] != '\0')
				return(line);
			return (NULL);
		}
	}
}

int read_line(int fd, char *buffer, char **line)
{
	size_t charsread;
	size_t len_nl;
	char *temp;

	charsread = read(fd, buffer, BUFFERSIZE);
	if (charsread <= 0)
		return(0);
	buffer[charsread] = '\0';
	if (!ft_strchr(buffer, '\n'))
	{
		temp = ft_strjoin(*line, buffer);
		free(*line);
		*line = temp;
		buffer[0] = '\0';
		return(2);
	}
	len_nl = ft_len_to_char(buffer, '\n');
	temp = ft_substr(buffer, 0, len_nl + 1);
	*line = ft_strjoin(*line, temp);
	free(temp);
	move_buf_to_nl(buffer, ft_len_to_char(buffer, '\n'));
	return (1);
}

void move_buf_to_nl(char *buffer, size_t len)
{
	size_t i;

	i = 0;
	while(buffer[i + 1 + len])
	{
		buffer[i] = buffer[len + i + 1];
		i++;
	}
	buffer[i] = '\0';
}

int handle_rest_in_buff(char *buffer, char **line)
{
	int i;

	i = 0;
	*line = malloc(ft_len_to_char(buffer, '\n') + 1);
	while(buffer[i] && buffer[i] != '\n')
	{
		*(line)[i] = buffer[i];
		i++;
	}
	if(buffer[i] == '\n')
	{
		*line[i] = '\0';
		move_buf_to_nl(buffer, i);
		return(1);
	}
	return(0);
}
