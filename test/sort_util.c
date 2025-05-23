/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguille <roguille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 02:41:41 by roguille          #+#    #+#             */
/*   Updated: 2025/05/21 02:41:42 by roguille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_stack *head)
{
	int		max;
	t_stack	*tmp;

	max = INT_MIN;
	tmp = head;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}

int	find_bits(int max_nbr)
{
	int	max_bits;

	max_bits = 0;
	while (max_nbr > 0)
	{
		max_nbr >>= 1;
		max_bits++;
	}
	return (max_bits);
}
