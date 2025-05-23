/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguille <roguille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 02:41:34 by roguille          #+#    #+#             */
/*   Updated: 2025/05/21 02:41:35 by roguille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack_head)
{
	t_stack	*tmp;

	if (!(*stack_head) || !(*stack_head)->next)
		return ;
	tmp = *stack_head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *stack_head;
	*stack_head = (*stack_head)->next;
	tmp->next->next = NULL;
}

void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_putendl_fd("ra", 1);
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putendl_fd("rb", 1);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putendl_fd("rr", 1);
}
