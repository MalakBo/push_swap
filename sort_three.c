/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:52:27 by mac               #+#    #+#             */
/*   Updated: 2025/02/07 16:55:24 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void sort_three(t_list **stack)
{
    if(!stack || !(*stack) || !(*stack)->next)
        return;
    t_list *max_node;
    max_node = max(*stack);
    if (max_node == (*stack))
        ra(stack);
    else if(max_node == (*stack)->next)
        rra(stack);
    if((*stack)->number > (*stack)->next->number)
        sa(stack);
}