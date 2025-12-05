/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtruckse <jtruckse@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:36:27 by jtruckse          #+#    #+#             */
/*   Updated: 2025/12/05 16:51:04 by jtruckse         ###   ########.fr       */
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
	charsread = read(fd, buf_ptr, BUFFERSIZE);
		printf("rest: %s\n", buffer);
	line = malloc(charsread  + 1);
	if (!line)
		return (NULL);
	line = ft_memcpy(line, buf_ptr, ft_strlennewlinechar(buf_ptr));
	if (ft_strchr(line, '\n') == 0)	{length1 = ft_strlennewlinechar(line);
		lineplus = ft_strjoin(lineplus, line);
		printf("lineplus: %s\n", lineplus);}
		
	else if (ft_strchr(line, '\n') != 0)
	{	
		length1 = ft_strlennewlinechar(line);
		lineplus = ft_memcpy(lineplus, line, length1);	
	}
	else 
		return(0);
	
	ft_memmove(buffer, buffer + length1, 100);
	
	printf("rest2: %s\nlength1: %zu\n", buffer, length1);
	free(line);
	return (lineplus);
}

