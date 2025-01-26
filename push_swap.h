/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:27:08 by mac               #+#    #+#             */
/*   Updated: 2025/01/26 20:43:31 by mac              ###   ########.fr       */
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
void print_stack(t_list *stack);
void update_indices(t_list *stack);
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
int pa(t_list **a,t_list **b);
int pb(t_list **a,t_list **b);
int rra(t_list **a);
int rrb(t_list **b);
int rrr(t_list **a,t_list **b);
int ra(t_list **a);
int rb(t_list **b);
int rr(t_list **a,t_list **b);
int sa(t_list **a);
int sb(t_list **b);
int ss(t_list **a,t_list **b);
void sort_three(t_list **stack);
void sort_stack(t_list **a,t_list **b);
void sort_a(t_list **a);
void sort_b(t_list **a,t_list **b);
void move_element_totop(t_list **b,int value);
int element_topush(t_list *a,t_list *b);
int cost_b(t_list *b,int value);
int cost_a(t_list *a,int value);
#endif