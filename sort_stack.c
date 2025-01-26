/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:25:34 by mac               #+#    #+#             */
/*   Updated: 2025/01/26 21:44:14 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void update_indices(t_list *stack)
{
    int index = 0;
    t_list *temp = stack;
    
    while (temp)
    {
        temp->index = index;
        temp = temp->next;
        index++;
    }
}
void print_stack(t_list *stack)
{
    t_list *temp = stack;
    while (temp)
    {
        printf("%d ", temp->number);
        temp = temp->next;
    }
    printf("\n");
}

int cost_a(t_list *a,int value)
{
    int i;
    t_list *temp_a;
    t_list *last;
    
    i = 0;
    if(!a)
        return 0;
    last = ft_lstlast(a);
    temp_a = a;
    if(value < a->number || value > last->number)
        return(0);
    while(temp_a->next)
    {
        if(value > temp_a->number && value < temp_a->next->number)
            return(i + 1);
        temp_a = temp_a->next;
        i++;
    }
    return(i + 1);
}
int cost_b(t_list *b,int value)
{
    int i;
    int size;
    t_list *temp_b;
    
    if(!b)
        return 0;
    temp_b = b;
    i = temp_b->index;
    size = ft_lstsize(b);
    while(temp_b)
    {
        if(temp_b->number == value)
        {
            if(i <= size/2)
                return(i);
            else
                return(size - i);
        }
        temp_b = temp_b->next;
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
void move_element_totop(t_list **b, int value)
{
    t_list *temp;
    int size;
    int i;

    if(!(*b))
        return ;
    temp = *b;
    if(!temp)
        return ;
    size = ft_lstsize(*b);
    while (temp && temp->number != value)
        temp = temp->next;
    if (!temp)
        return ;
    i = temp->index;
    if (i <= size / 2)
    {
        while ((*b)->number != value)
        {
            rb(b);
            printf("After rb:\n");
            print_stack(*b);
        }
    }
    else
    {
        while ((*b)->number != value)
        {
            rrb(b);
            printf("After rrb:\n");
            print_stack(*b);
        }
    }
    update_indices(*b);
}

void sort_b(t_list **a, t_list **b)
{
    if(!(*a) || !(*b))
        return ;
    int n;
    while (*b != NULL)
    {
        n = element_topush(*a, *b);
        move_element_totop(b, n);
        pa(a, b);
        printf("After pa:\n");
        print_stack(*a);
        print_stack(*b);
    }
}
void sort_a(t_list **a)
{
    if(!(*a))
        return;
    int size = ft_lstsize(*a);
    t_list *temp = *a;

    if (size > 3)
    {
        int min = (*a)->number;
        int min_index = 0;
        int i = 0;

        // Find the minimum element's index
        while (temp)
        {
            if (temp->number < min)
            {
                min = temp->number;
                min_index = i;
            }
            temp = temp->next;
            i++;
        }

        // Rotate the stack so the minimum element is at the top
        if (min_index <= size / 2)
        {
            while ((*a)->number != min)
                ra(a);
        }
        else
        {
            while ((*a)->number != min)
                rra(a);
        }
    }

    // Sort the remaining 3 elements
    sort_three(a);

    // Update indices after sorting the 3 elements
    update_indices(*a);
}



void sort_stack(t_list **a, t_list **b)
{
    if(!(*a))
        return ;
    int a_length = ft_lstsize(*a);

    // Step 1: Push elements from stack a to b until only 3 elements remain in a
    while (a_length > 3)
    {
        pb(a, b);
        printf("After pb:\n");
        print_stack(*a);
        print_stack(*b);
        a_length--;
    }

    // Step 2: Sort the top 3 elements in stack a
    sort_three(a);

    // Step 3: Move elements back from b to a, sorting as we go
    sort_b(a, b);
    sort_a(a);

    // Update indices after all operations
    update_indices(*a);
    update_indices(*b);
}
