/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:51:56 by mac               #+#    #+#             */
/*   Updated: 2025/02/07 02:01:41 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack_a(t_list *stack)
{
    t_list *temp = stack;
    while (temp)
    {
        printf("%d ", temp->number);
        temp = temp->next;
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    t_list *a;
    t_list *b;

    if (argc < 2)
        return (1);
    a = NULL;
    b = NULL;
    check_args(argc, argv);
    initstack_a(&a, argc, argv);
    // printf("Initial stack 'a':\n");
    // print_stack_a(a);    
    sort_stack(&a, &b);
    // printf("Sorted stack 'a':\n");
    // print_stack_a(a);
    ft_freestack(&a);
    ft_freestack(&b);
    return 0;
}
