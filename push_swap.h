/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyi <mbouyi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:27:08 by mac               #+#    #+#             */
/*   Updated: 2025/02/08 18:00:26 by mbouyi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define BUFFER_SIZE 1024

# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct list
{
	int			number;
	int			index;
	int			moves;
	int			on_middle;

	struct list	*next;
	struct list	*target;
}				t_list;

// Utility Functions
void			ft_error(char *err);
long			ft_atoi(char *s);
int				ft_isdigit(int c);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *s);
char			*ft_strchr(char *s, int c);
int				ft_strcmp(char *s1, char *s2);
void			ft_free(char **str);
void			free_split(char **a);
void			ft_putendl_fd(char *s, int fd);

// Linked List Operations
t_list			*ft_lstnew(int content);
void			ft_lstadd_back(t_list **lst, t_list *new);
t_list			*ft_lstlast(t_list *lst);
int				ft_lstsize(t_list *lst);
void			update_index(t_list *stack);

// Stack Operations
void			print_stack(t_list *stack);
int				stack_sorted(t_list *stack);
t_list			*max(t_list *stack);
t_list			*min(t_list *stack);
t_list			*min_move(t_list *stack);
void			initstack_a(t_list **a, int argc, char **argv);
void			ft_freestack(t_list **stack);
void			check_args(int argc, char **argv);

// Sorting Functions
void			sort_three(t_list **stack);
void			sort_stack(t_list **a, t_list **b);
void			sort(t_list **a, t_list **b);

// Stack Manipulation
void			update(t_list **a, t_list **b);
void			put_on_top(t_list **a, t_list **b);

// Operations
int				pa(t_list **a, t_list **b);
int				pb(t_list **a, t_list **b);
int				ra(t_list **a);
int				rb(t_list **b);
int				rr(t_list **a, t_list **b);
int				rra(t_list **a);
int				rrb(t_list **b);
int				rrr(t_list **a, t_list **b);
int				sa(t_list **a);
int				sb(t_list **b);
int				ss(t_list **a, t_list **b);

// Operations Execution & Input Parsing
void			execute_operation(char *operation, t_list **a, t_list **b);
int				is_operation(char *operation);
void			read_operations(t_list **a, t_list **b);

// String Manipulation
char			**ft_split(char const *s, char c);

#endif