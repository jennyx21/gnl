/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtruckse <jtruckse@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 20:54:00 by jtruckse          #+#    #+#             */
/*   Updated: 2025/12/09 22:08:09 by jtruckse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_test.h"

static char *l_until_nl(char *line)
{
	size_t		length1 = 0 ;
	char		*lineplus = "";

	printf("line: %s\n", line);
	if (ft_strchr(line, '\n') == 0)
	{
		lineplus = ft_strjoin(lineplus, line);
		// printf("lineplus: %s\n", lineplus);
	}
	else 
	{	
		length1 = ft_strlennewlinechar(line);
		line = ft_strtrim(length1, line);
		lineplus = ft_strjoin(lineplus,line);
	}
	return(lineplus);
}
// static char *read_more(int fd, char buffer ,int charsread)
// {
// 	while ()
// }


char *get_next_line(int fd)
{
	char		*line;
	char		*lineplus;
	int			charsread;
	static char	buffer[BUFFERSIZE + 1];
	char		*buf_ptr;

	buf_ptr = buffer;

	if (BUFFERSIZE <= 0 || fd < 0)
		return (NULL);
	charsread = read(fd, buf_ptr, BUFFERSIZE);
	if(charsread <= 0)
		return(NULL);
	line = malloc(charsread  + 1);
	if (!line)
		return (NULL);
	buffer[charsread] = '\0';
	line = ft_memcpy(line, buf_ptr, ft_strlennewlinechar(buf_ptr));
	while(strchr(line,'\n') != 0)
	{
		lineplus = l_until_nl(line);
		// line = read_more(fd, buffer, charsread);
	}
	free(line);
	return (line);
}
