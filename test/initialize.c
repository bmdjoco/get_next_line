/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguille <roguille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 02:41:14 by roguille          #+#    #+#             */
/*   Updated: 2025/05/21 02:41:21 by roguille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_stack *head, int link_size)
{
	t_stack	*biggest;
	t_stack	*tmp;

	while (link_size-- > 0)
	{
		biggest = NULL;
		tmp = head;
		while (tmp)
		{
			if (!tmp->index && (biggest == NULL
					|| tmp->value > biggest->value))
				biggest = tmp;
			tmp = tmp->next;
		}
		if (biggest)
			biggest->index = link_size;
	}
}

t_stack	*init_list(int argc, char **argv)
{
	t_stack	*stack_a;
	char	**tmp;
	int		i;

	stack_a = NULL;
	i = 0;
	if (argc == 2)
		tmp = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		tmp = argv;
	}
	while (tmp[i])
	{
		insert_at_tail(&stack_a, ft_atoi(tmp[i]));
		i++;
	}
	if (argc == 2)
		free_strs(tmp);
	return (stack_a);
}
