/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rev_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguille <roguille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 02:41:32 by roguille          #+#    #+#             */
/*   Updated: 2025/05/21 02:41:33 by roguille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_stack **stack_head)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!(*stack_head) || !(*stack_head)->next)
		return ;
	last = *stack_head;
	while (last->next)
	{
		tmp = last;
		last = last->next;
	}
	last->next = *stack_head;
	tmp->next = NULL;
	*stack_head = last;
}

void	rra(t_stack **stack_a)
{
	rev_rotate(stack_a);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_stack **stack_b)
{
	rev_rotate(stack_b);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_putendl_fd("rrr", 1);
}
