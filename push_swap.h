/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:27:08 by mac               #+#    #+#             */
/*   Updated: 2025/02/07 18:39:31 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#define BUFFER_SIZE 4

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


typedef struct list
{
    int number;
    int index;
    int moves;
    int on_middle;
    
    struct list *next;
    struct list *target;
} t_list;



void print_stack(t_list *stack);
void check_args(int argc, char **argv);
char	**ft_split(char const *s, char c);
long ft_atoi(char *s);
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
int stack_sorted(t_list *stack);
void sort_three(t_list **stack);
void sort_stack(t_list **a, t_list **b);
t_list *max(t_list *stack);
t_list *min(t_list *stack);
void ft_freestack(t_list **stack);
void	free_split(char **a);
t_list *min_move(t_list *stack);
void sort(t_list **a, t_list **b);
void update(t_list **a,t_list **b);
void put_on_top(t_list **a,t_list **b);
int ft_strcmp(char *s1,char *s2);
void execute_operation(char *operation,t_list **a,t_list **b);
int is_operation(char *operation);
//operations
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
#endif