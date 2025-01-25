/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:27:08 by mac               #+#    #+#             */
/*   Updated: 2025/01/25 14:52:00 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include<unistd.h>
#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct list
{
    int number;
    int index;
    struct list *next;
    struct list *prev;
} t_list;

void check_args(int argc, char **argv);
char	**ft_split(char const *s, char c);
int ft_atoi(char *s);
int ft_isdigit(int c);
void ft_error(char *err);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
void ft_free(char **str);
char	*ft_strchr(char *s, int c);
t_list *ft_lstnew(int content);
void ft_lstadd_back(t_list **lst,t_list *new);
t_list *ft_lstlast(t_list *lst);
void initstack_a(t_list **a,int argc,char **argv);
int ft_lstsize(t_list *lst);
void ft_putendl_fd(char *s,int fd);
t_list *min(t_list *stack);
t_list *max(t_list *stack);
bool stack_sorted(t_list *stack);
#endif