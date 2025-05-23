/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguille <roguille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 02:41:29 by roguille          #+#    #+#             */
/*   Updated: 2025/05/21 02:41:31 by roguille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (!stack_a || !(*stack_a))
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	if (stack_b == NULL)
		*stack_b = tmp;
	else
	{
		tmp->next = *stack_b;
		*stack_b = tmp;
	}
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_putendl_fd("pa", 1);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_putendl_fd("pb", 1);
}
