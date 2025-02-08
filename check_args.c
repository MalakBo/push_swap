/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyi <mbouyi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:39:45 by mbouyi            #+#    #+#             */
/*   Updated: 2025/02/08 18:24:27 by mbouyi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	isnumber(char *num)
{
	int	i;

	i = 0;
	if ((num[i] == '-' || num[i] == '+') && !ft_isdigit(num[i + 1]))
		return (0);
	if (num[i] == '-' || num[i] == '+')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_duplicates(long num, char **argv)
{
	char	**argos_msplitin;

	int (i), (j), (count);
	i = 1;
	count = 0;
	while (argv[i])
	{
		j = 0;
		if (ft_strchr(argv[i], ' '))
		{
			argos_msplitin = ft_split(argv[i], ' ');
			while (argos_msplitin[j])
			{
				if (ft_atoi(argos_msplitin[j]) == num)
					count++;
				j++;
			}
			free_split(argos_msplitin);
		}
		else if (ft_atoi(argv[i]) == num)
			count++;
		i++;
	}
	if (count > 1)
		return (1);
	return (0);
}

static void	check_empty_args(char *str)
{
	if (!str || !str[0])
		ft_error("Error");
}

static void	check_split_result(char **args)
{
	if (!args || !args[0])
	{
		free_split(args);
		ft_error("Error");
	}
}

void	check_args(int argc, char **argv)
{
	long	num;
	char	**args;

	int (i), (j);
	i = 1;
	while (i < argc)
	{
		check_empty_args(argv[i]);
		args = ft_split(argv[i], ' ');
		check_split_result(args);
		j = 0;
		while (args[j])
		{
			num = ft_atoi(args[j]);
			if (!isnumber(args[j]))
				ft_error("Error");
			if (check_duplicates(num, argv))
				ft_error("Error");
			if (num < -2147483648 || num > 2147483647)
				ft_error("Error");
			j++;
		}
		free_split(args);
		i++;
	}
}
