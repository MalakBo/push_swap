/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 01:00:23 by mac               #+#    #+#             */
/*   Updated: 2025/01/24 02:12:31 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int rotate(t_list **stack)
{
    t_list *temp;
    t_list *last;

    if(ft_lstsize(stack) < 2)
        return(-1);
    temp = *stack;
    *stack = (*stack)->next;
    last = ft_lstlast(temp);
    last->next = temp;
    temp->next = NULL;
    return (0);
}
int ra(t_list **a)
{
    if(rotate(a) == -1)
        return(-1);
    ft_putendl_fd("ra",1);
    return(0);
}
int rb(t_list **b)
{
    if(rotate(b) == -1)
        return(-1);
    ft_putendl_fd("rb",1);
}
int rr(t_list **a,t_list **b)
{
    if(rotate(a) == -1 || rotate(b) == -1)
        return(-1);
    ft_putendl_fd("rr",1);
}