/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:53:49 by mac               #+#    #+#             */
/*   Updated: 2025/01/30 01:58:04 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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