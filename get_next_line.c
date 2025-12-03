/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtruckse <jtruckse@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:36:27 by jtruckse          #+#    #+#             */
/*   Updated: 2025/12/03 23:41:42 by jtruckse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	int			charsread;
	char		*newlinechar;
	char		*lineplus;
	size_t		lengh;
	static char	buffer[BUFFERSIZE + 1];
	char		*buf_ptr;

	buf_ptr = buffer;

	if (BUFFERSIZE <= 0 || fd < 0)
		return (NULL);
	charsread = read(fd, buf_ptr, BUFFERSIZE);
	line = ft_memcpy(line, buf_ptr, ft_strlennewlinechar(buf_ptr));
	newlinechar = ft_strchr(line, '\n');
	if (newlinechar == 0)
		lineplus = ft_strjoin(lineplus, line);
	else if (newlinechar > 0)
	{	
		lengh = ft_strlennewlinechar(line);
		lineplus = ft_memcpy(lineplus, line, lengh);
	}
	return (lineplus);
}

