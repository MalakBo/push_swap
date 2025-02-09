/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyi <mbouyi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 02:13:54 by mbouyi            #+#    #+#             */
/*   Updated: 2025/02/09 14:54:02 by mbouyi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate(t_list **stack)
{
	t_list	*head;
	t_list	*last;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	last = ft_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	last->next = *stack;
	*stack = last;
	return (0);
}

int	rra(t_list **a)
{
	if (reverse_rotate(a) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	rrb(t_list **b)
{
	if (reverse_rotate(b) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	rrr(t_list **a, t_list **b)
{
	if ((ft_lstsize(*a) < 2) || (ft_lstsize(*b) < 2))
		return (-1);
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putendl_fd("rrr", 1);
	return (0);
}
