/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_lineold.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtruckse <jtruckse@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:36:27 by jtruckse          #+#    #+#             */
/*   Updated: 2025/12/09 18:39:29 by jtruckse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	int			charsread;
	char		*lineplus = "";
	size_t		length1;
	static char	buffer[BUFFERSIZE + 1];
	char		*buf_ptr;

	buf_ptr = buffer;
	length1 = 0;
	if (BUFFERSIZE <= 0 || fd < 0)
		return (NULL);
	charsread = read(fd, buffer, BUFFERSIZE);
		//printf("rest: %s\n", buffer);
	line = malloc(charsread  + 1);
	if (!line)
		return (NULL);
	line = ft_memmove(line, buf_ptr, ft_strlennewlinechar(buf_ptr));
	line[ft_strlennewlinechar(buf_ptr)] = '\0';
	if (ft_strchr(line, '\n') == 0)	
	{
		length1 = ft_strlennewlinechar(line);
		//printf("lineplus: %s\n", lineplus);
		lineplus = ft_strjoin(lineplus, line);
		//printf("lineplus: %s\n", lineplus);
	}
	else 
	{	
		length1 = ft_strlennewlinechar(line);
		lineplus = ft_memmove(lineplus, line, length1);	
	}
	
	// printf("buffer: %s\n", buffer);

	ft_strcpy(ft_strchr(line, '\n') + 1, buffer);
	//printf("rest2: %s\nlength1: %zu\n", buffer, length1);
	free(line);
	return (lineplus);
}

