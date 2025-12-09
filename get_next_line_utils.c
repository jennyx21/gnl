/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtruckse <jtruckse@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:36:09 by jtruckse          #+#    #+#             */
/*   Updated: 2025/12/09 19:44:52 by jtruckse         ###   ########.fr       */
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

size_t	ft_strlennewlinechar(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
	{
		i++;
	}
	return (i);
}


char	*ft_strcpy(char *dest, const char *src)
{
	size_t			i;
	const char		*ptrsrc;
	unsigned char	*ptrdest;

	i = 0;
	ptrsrc = src;
	ptrdest = (unsigned char *)dest;
	
		while (src[i] != '\0' && src[i-1] != '\n')
		{
			ptrdest[i] = ptrsrc[i];
			i++;
		}
		dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	return (0);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;
	int		i;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = malloc((len1 + len2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[i - len1])
	{
		str[i] = s2[i - len1];
		i++;
	}
	str[i] = '\0';
	printf("strjoin s1 input = %s\n", s1);
	printf("strjoin s2 input = %s\n", s2);
	fflush(stdout);
	return (str);
}


void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptrsrc;
	unsigned char	*ptrdest;
	size_t			i;

	ptrsrc = (unsigned char *)src;
	ptrdest = (unsigned char *)dest;
	i = 0;
	if (!dest && !src)
		return (dest);
	while (i < n)
	{
		if (ptrsrc < ptrdest)
		{
			n--;
			ptrdest[n] = ptrsrc[n];
		}
		else
		{


			printf("bevore strchr\n");
			fflush(stdout);
			ptrdest[i] = ptrsrc[i];
			i++;
		}
	}
	return (dest);
}


