/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 02:13:54 by mac               #+#    #+#             */
/*   Updated: 2025/01/24 02:34:07 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int reverse_rotate(t_list **stack)
{
    t_list *temp;
    t_list *last;
    
    if (ft_lstsize(*stack) < 2)
        return (-1);
    last = ft_lstlast(*stack);
    temp = last->prev;
    temp->next = NULL;
    last->next = *stack;
    last->prev = NULL;
    *stack = last;
    return(0);
}
int rra(t_list **a)
{
    if(reverse_rotate(a) == -1)
        return(-1);
    ft_putendl_fd("rra",1);
    return(0);
}
int rrb(t_list **b)
{
    if(reverse_rotate(b) == -1)
        return(-1);
    ft_putendl_fd("rrb",1);
    return(0);
}
int rrb(t_list **a,t_list **b)
{
    if(reverse_rotate(a) == -1 ||reverse_rotate(b) == -1)
        return(-1);
    ft_putendl_fd("rrr",1);
    return(0);
}