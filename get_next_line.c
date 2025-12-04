/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtruckse <jtruckse@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:36:27 by jtruckse          #+#    #+#             */
/*   Updated: 2025/12/04 15:31:50 by jtruckse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	int			charsread;
	char		*newlinechar;
	char		*lineplus = "";
	size_t		length1;
	size_t		length2;
	static char	buffer[BUFFERSIZE + 1];
	char		*buf_ptr;

	buf_ptr = buffer;

	if (BUFFERSIZE <= 0 || fd < 0)
		return (NULL);
	charsread = read(fd, buf_ptr, BUFFERSIZE);
	length2 = ft_strlen(buf_ptr);
	line = malloc(length2 + 1);
	if (!line)
		return (NULL);
	line = ft_memcpy(line, buf_ptr, ft_strlennewlinechar(buf_ptr));
	newlinechar = ft_strchr(line, '\n');
	if (newlinechar == 0)
		lineplus = ft_strjoin(lineplus, line);
	else if (newlinechar > 0)
	{	
		length1 = ft_strlennewlinechar(line);
		lineplus = ft_memcpy(lineplus, line, length1);
	}
	free(line);
	return (lineplus);
}

