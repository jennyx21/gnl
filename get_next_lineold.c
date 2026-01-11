/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_lineold.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtruckse <jtruckse@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:36:27 by jtruckse          #+#    #+#             */
/*   Updated: 2026/01/11 15:55:30 by jtruckse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

int handle_rest_in_buff(char *buffer, char **line);
int read_line(int fd, char *buffer, char **line);
void move_buf_to_nl(char *buffer, size_t len);


char *get_next_line(int fd)
{
    static char buffer[BUFFERSIZE + 1];
    char        *line;
    int         result;
    
    if (BUFFERSIZE <= 0 || fd < 0)
        return (NULL);
    line = NULL;
    if (buffer[0] != '\0')
    {
        if (handle_rest_in_buff(buffer, &line) == 1)
            return (line);
    }
    while (1)
    {
        result = read_line(fd, buffer, &line);
        if (result == 1)
            return (line);
		if (result == 0)
        {
            if (line && line[0] != '\0')
                return (line);
            return (NULL);
        }
    }
}

int read_line(int fd, char *buffer, char **line)
{
    ssize_t charsread;
    size_t  len_nl;
    char    *temp;
    char    *temp2;

    charsread = read(fd, buffer, BUFFERSIZE);
    if (charsread <= 0)
        return (0);
    buffer[charsread] = '\0';
    if (!ft_strchr(buffer, '\n'))
    {
        temp = ft_strjoin(*line, buffer);
        free(*line);
        *line = temp;
        buffer[0] = '\0';
        return (2);
    }
    len_nl = ft_len_to_char(buffer, '\n');
    temp = ft_substr(buffer, 0, len_nl + 1);
    temp2 = ft_strjoin(*line, temp);
    free(*line);
    free(temp);
    *line = temp2;
    move_buf_to_nl(buffer, len_nl);
    return (1);
}

void move_buf_to_nl(char *buffer, size_t len)
{
    size_t i;

    i = 0;
    while (buffer[len + i]) 
    {
        buffer[i] = buffer[len + i];
        i++;
    }
    buffer[i] = '\0';
}

int handle_rest_in_buff(char *buffer, char **line)
{
    size_t i;

    if (!ft_strchr(buffer, '\n'))
    {
        *line = ft_strdup(buffer);
        buffer[0] = '\0';
        return (0);
    }
    i = ft_len_to_char(buffer, '\n');
    *line = ft_substr(buffer, 0, i + 1);
    if (!*line)
        return (0);
    move_buf_to_nl(buffer, i);
    return (1);
}
