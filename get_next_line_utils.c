/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtruckse <jtruckse@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:36:09 by jtruckse          #+#    #+#             */
/*   Updated: 2026/01/10 17:23:53 by jtruckse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_len_to_char(const char *s, char c)
{
	size_t	i;

	i = 0;
	if(!s)
		return(0);
	while (s[i] && s[i] != c)
		i++;
	if(s[i] == '\n' && c == '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;
	int		i;

	if(!s1 && !s2)
		return(0);
	if(!s1)
		return(ft_strdup(s2));
	if(!s2)
	 return(ft_strdup(s1));
	len1 = ft_len_to_char(s1, '\0');
	len2 = ft_len_to_char(s2, '\0');
	str = malloc((len1 + len2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[i++])
		str[i] = s1[i];
	i = -1;
	while (s2[i++])
		str[len1 + i] = s2[i];
	str[i] = '\0';
	return (str);
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*result;

	i = -1;
	if (!s)
		return (NULL);
	if (start > ft_len_to_char(s, '\0'))
		return (result = ft_strdup(""));
	if (len > ft_len_to_char(s, '\0') - start)
		len = ft_len_to_char(s, '\0') - start;
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	while (++i < len)
		result[i] = s[start + i];
	result[i] = '\0';
	return (result);
}

char	*ft_strdup(const char *s)
{
	char	*restult;
	size_t len;
	size_t i;

	len = ft_len_to_char(s, '\0');
	restult = malloc(len + 1);
	if (!restult)
		return (NULL);
	i = 0;
	while (i < len)
	{
		restult[i] = s[i];
		i++;
	}
	restult[i] = '\0';
	return (restult);
}

