/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:51:56 by mac               #+#    #+#             */
/*   Updated: 2025/01/26 18:10:55 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc,char *argv[])
{
    t_list *a;
    t_list *b;
    
    if(argc < 2)
        return (1);
    a = NULL;
    b = NULL;
    check_args(argc,argv);
    initstack_a(&a,argc,argv);
    printf("Initial stack 'a':\n");
    t_list *temp = a;
    while (temp)
    {
        printf("%d\n", temp->number);
        temp = temp->next;
    }
    if(stack_sorted(a))
        printf("Stack is already sorted <3\n");
    sort_stack(&a,&b);
    printf("Sorted stack 'a':\n");
    temp = a;
    while (temp)
    {
        printf("%d\n", temp->number);
        temp = temp->next;
    }

}