/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:37:13 by mac               #+#    #+#             */
/*   Updated: 2025/02/07 01:58:26 by mac              ###   ########.fr       */
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

    while(b)
    {
        n = INT_MAX;
        temp = a;
        while(temp)
        {
            if(temp->number > b->number && n > temp->number)
            {
                b->target = temp;
                n = temp->number;
            }
            temp = temp->next;
        }
        if(n == INT_MAX)
            b->target = min(a);
        b = b->next;
    }
}
void middle(t_list *a,t_list *b)
{
    int size_a;
    int size_b;

    size_a = ft_lstsize(a);
    size_b = ft_lstsize(b);
    while(a)
    {
        if(a->index <= size_a / 2)
            a->on_middle = 1;
        else
            a->on_middle = 0;
        a = a->next;
    }
    while(b)
    {
        if(b->index <= size_b / 2)
            b->on_middle = 1;
        else
            b->on_middle = 0;
        b = b->next;
    }
}
void moves(t_list *a,t_list *b)
{
    int size_a;
    int size_b;

    size_a = ft_lstsize(a);
    size_b = ft_lstsize(b);
    while(b)
    {
        if(b->on_middle && b->target->on_middle)
            b->moves = b->index + b->target->index;
        else if(!(b->on_middle) && b->target->on_middle)
            b->moves = (size_b - b->index) + b->target->index;
        else if(b->on_middle && !(b->target->on_middle))
            b->moves = b->index + (size_a - b->target->index);
        else if(!(b->on_middle) && !(b->target->on_middle))
            b->moves = (size_b - b->index) + (size_a - b->target->index);
        b = b->next;
    }
}
void update(t_list **a,t_list **b)
{
    update_index(*a);
    update_index(*b);
    find_target(*a,*b);
    middle(*a,*b);
    moves(*a,*b);
}