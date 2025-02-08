/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:51:56 by mac               #+#    #+#             */
/*   Updated: 2025/02/09 00:14:22 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
