/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyi <mbouyi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 00:29:53 by mbouyi            #+#    #+#             */
/*   Updated: 2025/02/09 14:53:58 by mbouyi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_list **to, t_list **from)
{
	t_list	*tmp;

	if (*from == NULL)
		return (-1);
	tmp = *from;
	*from = (*from)->next;
	tmp->next = *to;
	*to = tmp;
	return (0);
}

int	pa(t_list **a, t_list **b)
{
	if (push(a, b) == -1)
		return (-1);
	ft_putendl_fd("pa", 1);
	return (0);
}

int	pb(t_list **a, t_list **b)
{
	if (!(*a))
		return (0);
	if (push(b, a) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
	return (0);
}
