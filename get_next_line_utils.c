/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:00:21 by ggalon            #+#    #+#             */
/*   Updated: 2023/11/25 19:00:21 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

long	ft_findnline(const char *s)
{
	size_t	i;
	size_t	len;

	if (!s)
		return (-1);
	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (-1);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*alloc;
	size_t	i;

	i = 0;
	if (nmemb > __SIZE_MAX__ / size)
		return (NULL);
	alloc = malloc(nmemb * size);
	if (!alloc)
		return (NULL);
	while (i < nmemb * size)
	{
		((char *)alloc)[i] = 0;
		i++;
	}
	return (alloc);
}

char	*ft_strndup(char *src, size_t start, size_t end)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc((end - start + 1) * sizeof(char));
	if (!dest || !src)
		return (NULL);
	while (src[start] && start < end)
	{
		dest[i] = src[start];
		i++;
		start++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*strjoin;
	size_t		i;
	size_t		e;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	strjoin = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!strjoin)
		return (NULL);
	while (s1[i])
	{
		strjoin[i] = s1[i];
		i++;
	}
	e = i;
	i = 0;
	while (s2[i])
	{
		strjoin[e + i] = s2[i];
		i++;
	}
	return (strjoin[e + i] = 0, strjoin);
}
