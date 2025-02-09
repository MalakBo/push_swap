/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyi <mbouyi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:52:27 by mbouyi            #+#    #+#             */
/*   Updated: 2025/02/09 14:54:11 by mbouyi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stack)
{
	t_list	*max_node;

	if (!stack || !(*stack) || !(*stack)->next || stack_sorted(*stack))
		return ;
	max_node = max(*stack);
	if (max_node == (*stack))
		ra(stack);
	else if (max_node == (*stack)->next)
		rra(stack);
	if ((*stack)->number > (*stack)->next->number)
		sa(stack);
}

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
