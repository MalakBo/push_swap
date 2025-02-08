/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyi <mbouyi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 23:52:18 by mbouyi            #+#    #+#             */
/*   Updated: 2025/02/07 22:58:00 by mbouyi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void ft_putendl_fd(char *s,int fd)
{
    ft_putstr_fd(s,fd);
    write(fd,"\n",1);
}

void ft_error(char *err)
{
    ft_putendl_fd(err,1);
    exit(0);
}

void ft_free(char **str)
{
	int i;
	
	i = 0;
	while(str[i])
		i++;
	while(i >= 0)
	{
		free(str[i]);
		i--;
	}
}

void ft_freestack(t_list **stack)
{
    t_list *temp;

    while (*stack)
    {
        temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    }
}