/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 01:24:03 by mac               #+#    #+#             */
/*   Updated: 2025/02/07 01:49:31 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void target_on_top(t_list **a,t_list *target)
{
    int n;
    
    if(target->on_middle)
        n = target->index;
    else
        n = ft_lstsize(*a) - target->index;
    while(n)
    {
        if(target->on_middle)
            ra(a);
        else
            rra(a);
        n--;
    }
}
void node_on_top(t_list **a,t_list **b)
{
    t_list *node;
    int n;

    node = min_move(*b);
    if(node->on_middle)
        n = node->index;
    else
        n = ft_lstsize(*b) - node->index;
    while(n)
    {
        if(node->on_middle)
            rb(b);
        else
            rrb(b);
        n--;
    }
    target_on_top(a,node->target);
}
void middle_on_top(t_list **a,t_list **b,t_list *cheapest,int n)
{
    while(cheapest != (*b) && (cheapest->target) != (*a))
    {
        rr(a,b);
        n--;
    }
    while(cheapest != (*b) && n)
    {
        rb(b);
        n--;
    }
    while((cheapest->target) != (*a) && n)
    {
        ra(a);
        n--;
    }
}
void nmiddle_on_top(t_list **a,t_list **b,t_list *cheapest,int n)
{
    while(cheapest != (*b) && (cheapest->target) != (*a))
    {
        rrr(a,b);
        n--;
    }
    while(cheapest != (*b) && n)
    {
        rrb(b);
        n--;
    }
    while((cheapest->target) != (*a) && n)
    {
        rra(a);
        n--;
    }
}
void put_on_top(t_list **a,t_list **b)
{
    t_list *cheapest;
    int n;
    
    cheapest = min_move(*b);
    if(cheapest->on_middle && cheapest->target->on_middle)
    {
        n = cheapest->index + cheapest->target->index;
        middle_on_top(a,b,cheapest,n);
    }
    else if(!(cheapest->on_middle) && !(cheapest->target->on_middle))
    {
        n = ft_lstsize(*b) - cheapest->index + ft_lstsize(*a) - cheapest->target->index;
        nmiddle_on_top(a,b,cheapest,n);
    }
    else
        node_on_top(a,b);
}