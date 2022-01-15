/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcardiga <lcardiga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:21:10 by lcardiga          #+#    #+#             */
/*   Updated: 2021/11/29 18:33:20 by lcardiga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	str1;
	size_t	str2;
	size_t	i;
	char	*memory;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	str1 = ft_strlen(s1);
	str2 = ft_strlen(s2);
	memory = (char *)malloc(sizeof(*memory) * (str1 + str2 + 1));
	if (!memory)
		return (NULL);
	while (*s1 != '\0')
		memory[i++] = *s1++;
	while (*s2 != '\0')
		memory[i++] = *s2++;
	memory[i] = '\0';
	return (memory);
}

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		i;

	i = 0;

	copy = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!copy)
		return (NULL);
	while (*s1)
		copy[i++] = *s1++;
	copy[i] = '\0';
	return (copy);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*substr;

	i = 0;
	if (!s)
		return ((char *)0);
	while (s[i])
		i++;
	if (start > i)
		len = 0;
	if (len > i - start)
		len = i - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (substr);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
