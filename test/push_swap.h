/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguille <roguille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 05:42:58 by roguille          #+#    #+#             */
/*   Updated: 2025/05/21 05:43:06 by roguille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "stdlib.h"
# include "stdio.h"
# include "unistd.h"
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
int		ft_isdigit(int c);
long	ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
void	free_strs(char **strs);
void	swap(t_stack **stack_head);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	rotate(t_stack **stack_head);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rev_rotate(t_stack **stack_head);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
t_stack	*new_node(int new_value);
void	check_args(int argc, char **argv);
int		count_arg(char **array);
void	free_stack(t_stack **head);
int		is_sorted(t_stack **head);
int		find_max(t_stack *head);
int		find_bits(int max_nbr);
void	set_index(t_stack *head, int link_size);
t_stack	*init_list(int argc, char **argv);
void	sort_stack(t_stack **stack_a, t_stack **stack_b);
int		count_elems(t_stack *head);
void	insert_at_tail(t_stack **head, int value);
void	error_handler(char **strs);
int		check_str(const char *str);

#endif
