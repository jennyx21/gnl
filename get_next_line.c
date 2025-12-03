/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtruckse <jtruckse@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:36:27 by jtruckse          #+#    #+#             */
/*   Updated: 2025/12/03 19:53:56 by jtruckse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	int			charsread;
	static char	buffer[BUFFERSIZE + 1];

	if (BUFFERSIZE <= 0 || fd < 0)
		return (NULL);
	charsread = read(fd, buffer, BUFFERSIZE);
	line = ft_strdup(buffer);
	if (line == 0)
		get_next_line(fd);
	




	printf("%li", sizeof(BUFFERSIZE));
	return (0);
}

