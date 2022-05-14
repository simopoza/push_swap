#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "libft/libft.h"

typedef struct t_list
{
    int data;
    int count;
    struct t_list *next;
} t_list;


void	sa_sb(t_list **head, char *num_of_stack);
void	ss(t_list **stack_a, t_list **stack_b, char *num_of_stack);
void	ra_rb(t_list **head, char *num_of_stack);
void	rr(t_list **stack_a, t_list **stack_b, char *num_of_stack);
void	rra_rrb(t_list **head, char *num_of_stack);
void	rrr(t_list **stack_a, t_list **stack_b, char *num_of_stack);
int		is_empty(t_list *head);
void	add_at_pos(t_list *head, int data, int pos);
int		count_node(t_list *head);
t_list	*create_node(int data);
void    add_at_front(t_list **head, int data);
t_list	*initial_stack(int ac, char *av[]);
int     del_first_node(t_list **head);
void    push_b(t_list **stack_a, t_list **stack_b);
void    push_a(t_list **stack_a, t_list **stack_b);
void    ft_check_sorted(t_list *stack_a);
bool    is_number(char number[]);
void    sort_3_num(t_list *stack_a);
int find_lis(t_list *stack_a);
int main(int ac, char *av[]);

#endif