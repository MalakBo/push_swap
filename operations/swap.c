/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:10:59 by mac               #+#    #+#             */
/*   Updated: 2025/01/24 00:57:01 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int swap(t_list **stack)
{
    t_list *head;
    t_list *next2;
    if (ft_lstsize(*stack) < 2)
        return (-1);
        head = *stack;
        next2 = head->next;
        head->next = next2->next;
        next2->next = head;
        *stack = next2;
        return (0);
}
int sa(t_list **a)
{
    if(swap(a) == -1)
        return(-1);
    ft_putendl_fd("sa",1);
    return(0);
}
int sb(t_list **b)
{
    if(swap(b) == -1)
        return(-1);
    ft_putendl_fd("sb",1);
    return(0);
}
int ss(t_list **a, t_list **b)
{
    if(swap(a) == -1 || swap(b) == -1)
        return(-1);
    ft_putendl_fd("ss",1);
    return(0);
}