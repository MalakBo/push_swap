/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:25:34 by mac               #+#    #+#             */
/*   Updated: 2025/02/05 18:04:09 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort(t_list **a,t_list **b)
{
    int mid;
    
    mid = (max(*a)->number + min(*a)->number) / 2;
    while(ft_lstsize(*a) > 3)
    {
        pb(a,b);
        if((*b)-> number >= mid)
            rb(b);
    }
    sort_three(a);
    while(*b)
    {
        
    }
}