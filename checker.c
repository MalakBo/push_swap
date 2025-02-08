/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:55:25 by mbouyi            #+#    #+#             */
/*   Updated: 2025/02/09 00:16:46 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_operation(char *operation)
{
	if (ft_strcmp(operation, "sa\n") == 0 || ft_strcmp(operation, "sb\n") == 0
		|| ft_strcmp(operation, "ss\n") == 0 || ft_strcmp(operation,
			"pa\n") == 0 || ft_strcmp(operation, "pb\n") == 0
		|| ft_strcmp(operation, "ra\n") == 0 || ft_strcmp(operation,
			"rb\n") == 0 || ft_strcmp(operation, "rr\n") == 0
		|| ft_strcmp(operation, "rra\n") == 0 || ft_strcmp(operation,
			"rrb\n") == 0 || ft_strcmp(operation, "rrr\n") == 0)
		return (1);
	return (0);
}

void	execute_operation(char *operation, t_list **a, t_list **b)
{
	if (ft_strcmp(operation, "sa\n") == 0)
		sa(a);
	else if (ft_strcmp(operation, "sb\n") == 0)
		sb(b);
	else if (ft_strcmp(operation, "ss\n") == 0)
		ss(a, b);
	else if (ft_strcmp(operation, "pa\n") == 0)
		pa(a, b);
	else if (ft_strcmp(operation, "pb\n") == 0)
		pb(a, b);
	else if (ft_strcmp(operation, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(operation, "rb\n") == 0)
		rb(b);
	else if (ft_strcmp(operation, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(operation, "rra\n") == 0)
		rra(a);
	else if (ft_strcmp(operation, "rrb\n") == 0)
		rrb(b);
	else if (ft_strcmp(operation, "rrr\n") == 0)
		rrr(a, b);
}

void	read_operations(t_list **a, t_list **b)
{
	char	buff[BUFFER_SIZE + 1];
	int		n;

    n = 0;
	while ((n = read(0, buff, BUFFER_SIZE)) > 0)
	{
		buff[n] = '\0';
		if (!is_operation(buff))
		{
			ft_error("Error\n");
			return ;
		}
		execute_operation(buff, a, b);
	}
}

void	print_stack(t_list *stack)
{
	printf("Stack: ");
	while (stack)
	{
		printf("(%d, idx:%d, moves:%d) -> ", stack->number, stack->index,
			stack->moves);
		stack = stack->next;
	}
	printf("NULL\n");
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	check_args(argc, argv);
	initstack_a(&a, argc, argv);
    if (!a)
    {
        ft_error("Error\n");
        return (1);
    }
	b = NULL;
	read_operations(&a, &b);
	if (stack_sorted(a) && !b)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	print_stack(a);
	ft_freestack(&a);
	return (0);
}
