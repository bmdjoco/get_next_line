/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:43:18 by bdjoco            #+#    #+#             */
/*   Updated: 2025/05/19 14:01:11 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	unsigned char	*res;

	res = malloc(count * size);
	if (!res)
		return (NULL);
	i = 0;
	while (i < size * count)
	{
		res[i] = 0;
		i++;
	}
	return (res);
}

char	*ft_strchr(char *str, int to_find)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char) to_find)
			return ((char *) &str[i]);
		i++;
	}
	if (str[i] == (char) to_find)
		return ((char *) &str[i]);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		l;
	int		i;
	char	*res;

	l = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = (char *) malloc(sizeof(char) * l);
	if (res == NULL)
		return (NULL);
	l = 0;
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		res[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	res[ft_strlen(s1) + i] = '\0';
	return (res);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	res = (char *) malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

size_t	ft_strlen(char *str)
{
	size_t	l;

	l = 0;
	while (str[l])
		l++;
	return (l);
}
