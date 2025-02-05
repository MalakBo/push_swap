/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:37:13 by mac               #+#    #+#             */
/*   Updated: 2025/02/05 18:29:39 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void update_index(t_list *stack)
{
    int i;
    t_list *temp;

    i = 0;
    temp = stack;

    while(temp)
    {
        temp->index = i;
        i++;
        temp = temp->next;
    }
}
int stack_sorted(t_list *stack)
{
    if(!stack || !stack->next)
        return(1);
    while(stack->next)
    {
        if(stack->number > stack->next->number)
            return(0);
        stack = stack->next;
    }
    return(1);
}
t_list *min(t_list *stack)
{
    t_list *min_node;
    if(!stack)
        return NULL;
    min_node = stack;
    while(stack)
    {
        if(stack->number < min_node->number)
            min_node = stack;
        stack = stack->next;
    }
    return(min_node);
}
t_list *max(t_list *stack)
{
    t_list *max_node;
    if(!stack)
        return (NULL);
    max_node = stack;
    while(stack)
    {
        if(stack->number > max_node->number)
            max_node = stack;
        stack = stack->next;
    }
    return(max_node);
}
void find_target(t_list *a, t_list *b)
{
    int n;
    t_list *temp;

    n = LONG_MAX;
    temp = a;
    while(b)
    {
        while(temp)
        {
            if(temp->number > b->number && n > temp->number)
            {
                b->target = temp;
                n = temp->number;
            }
            temp = temp->next;
        }
        if(n == LONG_MAX)
            b->target = min(a);
        b = b->next;
    }
}