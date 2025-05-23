/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:28:05 by roguille          #+#    #+#             */
/*   Updated: 2024/12/04 11:28:16 by roguille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_iswhitespace(int c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static int	calc(const char *nptr, int i, long *res, int *sign)
{
	while (ft_iswhitespace(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '+' && !(*sign))
			*sign = 1;
		else if (nptr[i] == '-' && !(*sign))
			*sign = -1;
		else
			return (0);
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		*res = *res * 10 + (nptr[i] - '0');
		i++;
	}
	return (1);
}

long	ft_atoi(const char *nptr)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 0;
	if (!calc(nptr, i, &res, &sign))
		return (0);
	if (!sign)
		sign++;
	return (res * sign);
}
