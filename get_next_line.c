/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtruckse <jtruckse@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:29:40 by jtruckse          #+#    #+#             */
/*   Updated: 2025/12/09 20:48:23 by jtruckse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// static char *check_fulline(char *line, char *buffer)
// {
// 	char		*fullline = "";
// 	char 		*temp;

// 	line = buffer
// 	if(ft_strchr(line, '\n') == 0)
// 	{
	
// 		temp = ft_strjoin(fullline, line);
		
// 		printf("fullline: %s\n", fullline);

// 		printf("line: %s\n", line);
// 		fflush(stdout);
// 	}
// 	else 
// 	{		
// 		fullline = memmove(fullline, line, ft_strlennewlinechar(line));
// 	}
// 	return(fullline);
// }

char	*get_next_line(int fd)
{
	static char buffer[BUFFERSIZE + 1];
	int			charsread;
	char		*line;
	
	charsread = 0;
	if(BUFFERSIZE <= 0 || fd < 0)
	return(0);
	charsread = read(fd, buffer, BUFFERSIZE);
	line = malloc(charsread + 1);
	if (!line)
	return(NULL);
	if(ft_strchr(buffer, '\n'))
		line = ft_strjoin(line, buffer);
	else
		line 
	return(line);
}

