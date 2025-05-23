/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:29:11 by roguille          #+#    #+#             */
/*   Updated: 2024/12/04 11:29:13 by roguille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_c(char to_check, char c)
{
	if (to_check == c)
		return (1);
	else
		return (0);
}

static int	ft_wordlen(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && !is_c(s[i], c))
		i++;
	return (i);
}

static int	word_count(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && is_c(s[i], c))
			i++;
		if (s[i])
			count++;
		while (s[i] && !is_c(s[i], c))
			i++;
	}
	return (count);
}

static char	*ft_worddup(const char *s, char c)
{
	int		len;
	char	*result;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_wordlen(s, c);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	while (i < len)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**tab;

	i = 0;
	if (!check_str(s))
		error_handler(0);
	tab = (char **) malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!tab)
		return (NULL);
	while (*s)
	{
		while (*s && is_c(*s, c))
			s++;
		if (*s)
		{
			tab[i] = ft_worddup(s, c);
			i++;
		}
		while (*s && !is_c(*s, c))
			s++;
	}
	tab[i] = 0;
	return (tab);
}
