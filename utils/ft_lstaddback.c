/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:58:58 by mac               #+#    #+#             */
/*   Updated: 2025/01/24 00:16:46 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
t_list *ft_lstlast(t_list *lst)
{
    if(!lst)
        return(NULL);
    while(lst->next != NULL)
    {
        lst = lst->next;
    }
    return(lst);
}
void ft_lstadd_back(t_list **lst,t_list *new)
{
    t_list *last;
    if(!lst || !new)
        return ;
    if(*lst == NULL)
    {
        *lst = new;
        return ;
    }
    last = ft_lstlast(*lst);
    last->next = new;
}
int ft_lstsize(t_list *lst)
{
    int i;
    
    i = 0;
    while(!lst != NULL)
    {
        lst = lst->next;
        i++;
    }
    return(i);
}