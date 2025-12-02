/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jennyx21 <jennyx21@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:36:34 by jtruckse          #+#    #+#             */
/*   Updated: 2025/12/02 23:48:03 by jennyx21         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETNEXTLINE_H
# define GETNEXTLINE_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

#define BUFFERSIZE 42

char	*get_next_line(int fd);

size_t	ft_strlen(const char *s);

#endif