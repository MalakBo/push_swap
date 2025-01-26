/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:39:45 by mac               #+#    #+#             */
/*   Updated: 2025/01/26 21:26:53 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int isnumber(char *num)
{
    int i;

    i = 0;
    if(num[i] == '-' || num[i] == '+')
        i++;
    if(!ft_isdigit(num[i]))
        return(0);
    while(num[i])
    {
        if(!ft_isdigit(num[i]))
            return(0);
        i++;
    }
    return(1);
}
static int check_duplicates(long num,char **argv)
{
    int (i),(j),(count);
    char **argos_msplitin;
    
    i = 1;
    j = 0;
    count = 0;
    while(argv[i])
    {
        if(ft_strchr(argv[i],' '))
        {
        argos_msplitin = ft_split(argv[i],' ');
        while(argos_msplitin[j])
        {
            if(ft_atoi(argos_msplitin[j]) == num)
                count++;
            j++;
        }
        ft_free(argos_msplitin);
        }
        else if(ft_atoi(argv[i]) == num)
            count++;
        i++;
    }
    if(count > 1)
        return(1);
    return(0);
            
}
void check_args(int argc, char **argv)
{
    int     (i),(j);
    long    num;
    char    **args;

    i = 1;
    while (i < argc)
    {
        args = ft_split(argv[i], ' '); 
        j = 0;
        while (args[j])
        {
            num = ft_atoi(args[j]);
            if (!isnumber(args[j]))
                ft_error("Error");
            if (check_duplicates(num, argv)) 
                ft_error("Error");
            if (num < INT_MIN || num > INT_MAX)
                ft_error("Error");
            j++;
        }
        ft_free(args);
        i++;
    }
}
