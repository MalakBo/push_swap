/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:25:34 by mac               #+#    #+#             */
/*   Updated: 2025/02/07 02:03:30 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *min_move(t_list *stack)
{
    t_list *min_node;
    if(!stack)
        return NULL;
    min_node = stack;
    while(stack)
    {
        if(stack->moves < min_node->moves)
            min_node = stack;
        stack = stack->next;
    }
    return(min_node);
}
void sort_a(t_list **a)
{
    t_list *mini;
    int n;

    mini = min(*a);
    if(mini ->on_middle)
        n = mini->index;
    else
        n = ft_lstsize(*a) - mini->index;
    while(n)
    {
        if(mini->on_middle)
            ra(a);
        else
            rra(a);
        n--;
    }
}
void sort_stack(t_list **a,t_list **b)
{
    int mid;
    
    mid = (max(*a)->number + min(*a)->number) / 2;
    if(ft_lstsize(*a) <= 3)
        sort_three(a);
    else
    {
    while(ft_lstsize(*a) > 3)
    {
        pb(a,b);
        if((*b)-> number >= mid)
            rb(b);
    }
    sort_three(a);
    while(*b)
    {
        update(a,b);
        put_on_top(a,b);
        pa(a,b);
    }
    update(a,b);
    sort_a(a);
    }
}
