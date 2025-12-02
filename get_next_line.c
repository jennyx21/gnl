/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jennyx21 <jennyx21@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:36:27 by jtruckse          #+#    #+#             */
/*   Updated: 2025/12/03 00:00:08 by jennyx21         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{ 
	char		*line;
	int 		readchar;
	static char	buffer[BUFFERSIZE + 1];

	while(!buffer)
	read(fd, buffer, BUFFERSIZE);
	while (buffer && buffer =='\n')
	
	
	ft_strlen(line)
	



	printf("%li", sizeof(BUFFERSIZE));
	return (0);
}

