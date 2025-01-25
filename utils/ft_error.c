/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 23:52:18 by mac               #+#    #+#             */
/*   Updated: 2025/01/21 01:31:25 by mac              ###   ########.fr       */
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