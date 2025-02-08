/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyi <mbouyi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:52:27 by mbouyi            #+#    #+#             */
/*   Updated: 2025/02/08 18:34:20 by mbouyi           ###   ########.fr       */
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
