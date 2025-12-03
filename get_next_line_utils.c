/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtruckse <jtruckse@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:36:09 by jtruckse          #+#    #+#             */
/*   Updated: 2025/12/03 19:05:33 by jtruckse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*restult;

	restult = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!restult)
		return (NULL);
	ft_strlcpy(restult, s, (ft_strlen(s) + 1));
	return (restult);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t			i;
	size_t			src_len;
	const char		*ptrsrc;
	unsigned char	*ptrdest;

	i = 0;
	src_len = 0;
	ptrsrc = src;
	ptrdest = (unsigned char *)dest;
	while (ptrsrc[src_len] != '\0')
		src_len++;
	if (size > 0)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			ptrdest[i] = ptrsrc[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_len);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
