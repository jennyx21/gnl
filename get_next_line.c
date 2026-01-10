/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtruckse <jtruckse@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:29:40 by jtruckse          #+#    #+#             */
/*   Updated: 2026/01/10 18:34:34 by jtruckse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char buffer[BUFFERSIZE + 1];
	char		*line;
	int			result;
	
	if(BUFFERSIZE <= 0 || fd < 0)
		return(0);
	line = NULL;
	if(buffer[0] != '\0')
		line = handle_rest_in_buff(buffer, &line);
	while(1){
	result = read_line(fd, buffer, &line);
	if(result == 0)
		return (0);
	if(result == 1)
		return(line );}
	return(0);
}

int read_line(int fd, char *buffer, char **line)
{
	size_t charsread;
	size_t len_nl;

	charsread = read(fd, buffer, BUFFERSIZE);
	if (charsread <= 0)
		return(0);
	buffer[charsread] = '\0';
	*line = malloc(charsread + 1);
	if (!*line)
		return(0);
	if (!ft_strchr(buffer, '\n'))
	{
		line = ft_strjoin(*line, buffer);
		buffer[0] = '\0'
		return(2);
	}
	else
	{
		len_nl = ft_len_to_char(buffer, "\n");
		line = ft_strjoin(line, ft_substr(buffer, 0, len_nl + 1));
		buffer = move_buf_to_nl(buffer, ft_len_to_char(buffer, '\0'));
		return (1);
	}
	return(0);
}

char move_buf_to_nl(char *buffer, size_t len)
{
	int i;

	i = 0;
	while(buffer[i + len] && i <= len)
	{
		buffer[i] = buffer[len + 1]
		i++;
	}
	buffer[i] = '\0'
}
