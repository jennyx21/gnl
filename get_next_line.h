/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtruckse <jtruckse@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:36:34 by jtruckse          #+#    #+#             */
/*   Updated: 2025/12/02 16:32:13 by jtruckse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETNEXTLINE_H
# define GETNEXTLINE_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

#define BUFFERSIZE 42

char	*get_next_line(int fd);_

#endif