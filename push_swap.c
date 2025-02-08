/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyi <mbouyi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:51:56 by mac               #+#    #+#             */
/*   Updated: 2025/02/08 18:30:50 by mbouyi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*min_move(t_list *stack)
{
	t_list	*min_node;

	if (!stack)
		return (NULL);
	min_node = stack;
	while (stack)
	{
		if (stack->moves < min_node->moves)
			min_node = stack;
		stack = stack->next;
	}
	return (min_node);
}

void	sort_a(t_list **a)
{
	t_list	*mini;
	int		n;

	mini = min(*a);
	if (mini->on_middle)
		n = mini->index;
	else
		n = ft_lstsize(*a) - mini->index;
	while (n)
	{
		if (mini->on_middle)
			ra(a);
		else
			rra(a);
		n--;
	}
}

void	sort_stack(t_list **a, t_list **b)
{
	int	mid;

	mid = (max(*a)->number + min(*a)->number) / 2;
	if (ft_lstsize(*a) <= 3)
		sort_three(a);
	else
	{
		while (ft_lstsize(*a) > 3)
		{
			pb(a, b);
			if ((*b)->number >= mid)
				rb(b);
		}
		sort_three(a);
		while (*b)
		{
			update(a, b);
			put_on_top(a, b);
			pa(a, b);
		}
		update(a, b);
		sort_a(a);
	}
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	if (argc < 2)
		return (1);
	a = NULL;
	b = NULL;
	check_args(argc, argv);
	initstack_a(&a, argc, argv);
	if (stack_sorted(a))
		printf("Stack is already sorted <3\n");
	sort_stack(&a, &b);
	ft_freestack(&a);
	ft_freestack(&b);
	return (0);
}
