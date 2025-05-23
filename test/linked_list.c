/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguille <roguille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 02:41:25 by roguille          #+#    #+#             */
/*   Updated: 2025/05/21 02:41:27 by roguille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_elems(t_stack *head)
{
	int	i;

	i = 0;
	while (head != NULL)
	{
		head = head->next;
		i++;
	}
	return (i);
}

t_stack	*new_node(int new_value)
{
	t_stack	*res;

	res = ft_calloc(1, sizeof(t_stack));
	if (!res)
		return (NULL);
	res->value = new_value;
	res->index = 0;
	res->next = NULL;
	return (res);
}

void	insert_at_tail(t_stack **head, int value)
{
	t_stack	*tmp;
	t_stack	*current;

	if (*head == NULL)
	{
		*head = new_node(value);
		return ;
	}
	current = *head;
	while (current->next != NULL)
		current = current->next;
	tmp = new_node(value);
	current->next = tmp;
}
