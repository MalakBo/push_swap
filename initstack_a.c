/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initstack_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:32:28 by mac               #+#    #+#             */
/*   Updated: 2025/01/23 17:54:54 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void initstack_a(t_list **a,int argc,char **argv)
{
    t_list *new;
    int i;
    int j;
    char **args;
    
    i = 1;
    while(i < argc)
    {
        args = ft_split(argv[i],' ');
        j = 0;
        while(args[j])
        {
            new = ft_lstnew(ft_atoi(args[j]));
            ft_lstadd_back(a,new);
            j++;
        }
        ft_free(args);
        i++;
    }
}
