/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtruckse <jtruckse@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:29:40 by jtruckse          #+#    #+#             */
/*   Updated: 2026/01/10 17:27:23 by jtruckse         ###   ########.fr       */
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

	while(1){
	result = read_line(fd, buffer, &line);
	if(result == 0)
		return (0);
	if(result == 1)
		return(line );}
	return(0);
}

char *read_line(int fd, char *buffer, char *line)
{
	size_t charsread;
	size_t len_nl;

	charsread = read(fd, buffer, BUFFERSIZE);
	if (charsread <= 0)
		return(NULL);
	buffer[charsread] = '\0';
	line = malloc(charsread + 1);
	if (!line)
		return(0);
	if (!ft_strchr(buffer, '\n'))
	{
		line = ft_strjoin(line, buffer);
		return(2);
	}
	else
	{
		line = ft_strjoin(line, ft_substr(buffer, 0,-ft_len_to_char(buffer, "\0")));
		return (1);
	}
	return(0);
}

