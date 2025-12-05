/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtruckse <jtruckse@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:29:40 by jtruckse          #+#    #+#             */
/*   Updated: 2025/12/05 17:59:27 by jtruckse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	line = ft_memmove(line, buffer,)
	

}


