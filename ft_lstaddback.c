/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyi <mbouyi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:58:58 by mbouyi            #+#    #+#             */
/*   Updated: 2025/02/07 22:58:51 by mbouyi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *ft_lstlast(t_list *lst)
{
    if(!lst)
        return(NULL);
    while(lst->next)
        lst = lst->next;
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
    if(!lst)
        return 0;
    int i;
    
    i = 0;
    while(lst)
    {
        i++;
        lst = lst->next;
    }
    return(i);
}

t_list *ft_lstnew(int content)
{
    t_list *new;
    new = malloc(sizeof(t_list));
    if(!new)
        return(NULL);
    new->number = content;
    new->next = NULL;
    return(new);
}

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