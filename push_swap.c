/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:51:56 by mac               #+#    #+#             */
/*   Updated: 2025/01/23 17:58:33 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc,char *argv[])
{
    t_list *a;
    // t_list *b;
    
    if(argc < 2)
        return (1);
    a = NULL;
    // b = NULL;
    check_args(argc,argv);
    initstack_a(&a,argc,argv);
    t_list *temp = a;
    while (temp)
    {
        printf("%d\n", temp->number);
        temp = temp->next;
    }
}