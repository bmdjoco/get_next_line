/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:43:36 by bdjoco            #+#    #+#             */
/*   Updated: 2025/05/21 14:15:23 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	int		l;
	char	*res;

	l = 0;
	if (!src)
		return (NULL);
	while (src[l])
		l++;
	res = (char *) malloc((l + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	ft_strcpy(res, src);
	return (res);
}

static char	*read_to_stash(int fd, char *stash)
{
	char	*buff;
	char	*tmp;
	ssize_t	is_end;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff || !stash)
		return (NULL);
	while (!ft_strchr(stash, '\n'))
	{
		is_end = read(fd, buff, BUFFER_SIZE);
		if (is_end < 1)
			break ;
		buff[is_end] = '\0';
		tmp = ft_strjoin(stash, buff);
		if (!tmp)
			return (free(buff), NULL);
		free(stash);
		stash = tmp;
	}
	free(buff);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*res;
	char		*n_stash;
	size_t		i;

	if (!stash)
		stash = ft_calloc(1, 1);
	stash = read_to_stash(fd, stash);
	if (!stash || stash[0] == '\0')
		return (free(stash), stash = NULL, NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	res = ft_substr(stash, 0, i);
	n_stash = ft_strdup(stash + i);
	if (!res || !n_stash)
		return (free(res), free(n_stash), NULL);
	free(stash);
	stash = n_stash;
	return (res);
}
