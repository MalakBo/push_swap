/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:25:34 by mac               #+#    #+#             */
/*   Updated: 2025/01/30 01:39:32 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int cost_a(t_list *a, int value) {
    int i;
    t_list *temp_a;
    int size;

    i = 0;
    temp_a = a;
    size = ft_lstsize(a);
    if (value < a->number || value > ft_lstlast(a)->number)
        return 0;

    while (temp_a && temp_a->number != value) {
        temp_a = temp_a->next;
        i++;
    }
    if (i < size / 2)
        return i;
    else
        return size - i;
}

int cost_b(t_list *b, int value) {
    int i;
    t_list *temp_b;
    int size;

    i = 0;
    temp_b = b;
    size = ft_lstsize(b);
    while (temp_b) {
        if (temp_b->number == value) {
            if (i <= size / 2)
                return i;
            else
                return size - i;
        }
        temp_b = temp_b->next;
        i++;
    }
    return -1;
}

int element_topush(t_list *a,t_list *b)
{
    t_list *temp;
    
    int (mincost),(value),(costa),(costb),(cost),(best_value);
    if(!b)
        return 0;
    temp = b;
    mincost = INT_MAX;
    while(temp)
    {
        value = temp->number;
        costa = cost_a(a,value);
        costb = cost_b(b,value);
        cost = costa + costb;
        if(cost < mincost)
        {
            mincost = cost;
            best_value = value;
        }
        temp = temp->next;
    }
    return (best_value);
}

void move_element_totop(t_list **b, int value) {
    t_list *temp;
    int size;
    int i;
    
    temp = *b;
    i = 0;
    size = ft_lstsize(*b);
    while (temp && temp->number != value) {
        temp = temp->next;
        i++;
    }

    if (temp) 
    {
        if (i <= size / 2)
            while ((*b)->number != value)
                rb(b);
        else
            while ((*b)->number != value)
                rrb(b);
    }
}

void sort_b(t_list **a, t_list **b)
{
    if(!(*a))
        return ;
    int n;
    while (*b != NULL)
    {
        n = element_topush(*a, *b);
        move_element_totop(b, n);
        pa(a, b);
    }
}

void sort_a(t_list **a) {
    t_list *temp;
    int tmp;

    if (!(*a) || !(*a)->next)
        return;

    temp = *a;
    while (temp->next) 
    {
        if (temp->number > temp->next->number) 
        {
            tmp = temp->number;
            temp->number = temp->next->number;
            temp->next->number = tmp;
            temp = *a;
        } 
        else
            temp = temp->next;
    }
}

void sort_stack(t_list **a, t_list **b) {
    int a_length;

    a_length = ft_lstsize(*a);
    while (a_length > 3) 
    {
        pb(a, b);
        a_length--;
    }

    sort_three(a);
    sort_b(a, b);
    sort_a(a); 
}
