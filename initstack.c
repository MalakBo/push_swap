/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initstack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:41:51 by mbouyi            #+#    #+#             */
/*   Updated: 2025/02/09 00:05:21 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
		{
			return ((char *)(s + i));
		}
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)(s + i));
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	initstack_a(t_list **a, int argc, char **argv)
{
	t_list	*new;
	int		i;
	int		j;
	char	**args;

	*a = NULL;
	i = 1;
	while (i < argc)
	{
		args = ft_split(argv[i], ' ');
		j = 0;
		while (args[j])
		{
			new = ft_lstnew(ft_atoi(args[j]));
			ft_lstadd_back(a, new);
			j++;
		}
		free_split(args);
		i++;
	}
}
