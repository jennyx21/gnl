/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jennyx21 <jennyx21@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:36:27 by jtruckse          #+#    #+#             */
/*   Updated: 2025/12/04 23:43:14 by jennyx21         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	int			charsread;
	char		*lineplus = "";
	size_t		length1;
	char 		*res = "";

	static char	buffer[BUFFERSIZE + 1];
	char		*buf_ptr;

	buf_ptr = buffer;

	if (BUFFERSIZE <= 0 || fd < 0)
		return (NULL);
	if (strlen(res))
		printf("rest: %s", res);
	charsread = read(fd, buf_ptr, BUFFERSIZE);
	line = malloc(charsread  + 1);
	if (!line)
		return (NULL);
	line = ft_memcpy(line, buf_ptr, ft_strlennewlinechar(buf_ptr));
	
	if (ft_strchr(line, '\n') == 0)
		
		lineplus = ft_strjoin(lineplus, line);
	else if (ft_strchr(line, '\n') != 0)
	{	
		length1 = ft_strlennewlinechar(line);
		lineplus = ft_memcpy(lineplus, line, length1);
	}
	else 
		return(0);
	res = ft_strtrim(length1, line);
	free(line);
	return (lineplus);
}

