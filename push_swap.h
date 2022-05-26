#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "libft/libft.h"

typedef struct t_move
{
    int best;
    int moves;
    int pos_a;
    int pos_b;
} t_move;

typedef struct s_list
{
    int data;
    struct s_list *next;
} s_list;

typedef struct t_list
{
    int data;
    int index;
    int count[2];
    s_list *arr;
    struct t_list *next;
} t_list;

// void    apply_moves(t_list **stack_a, t_list **stack_b);
int moves_in_a(int data, t_list *stack_a);
void last_sort(t_list **stack_a, t_list **stack_b);
void    apply_moves(t_list **stack_a, t_list **stack_b, int *count);
void    fill_count(t_list **stack_a, t_list **stack_b);
void    sa_sb(t_list **head, char *num_of_stack);
void	ss(t_list **stack_a, t_list **stack_b, char *num_of_stack);
void	ra_rb(t_list **head, char *num_of_stack);
void	rr(t_list **stack_a, t_list **stack_b, char *num_of_stack);
void	rra_rrb(t_list **head, char *num_of_stack);
void	rrr(t_list **stack_a, t_list **stack_b, char *num_of_stack);
t_list  *ft_lstlastt(t_list *lst);
s_list *ft_lstlast(s_list *lst);
void    ft_lstadd_back(s_list **lst, s_list *new);
s_list  *add_at_end1(s_list *head, int data);
t_list  *add_at_end(t_list *head, int data);
int     is_empty(t_list *head);
void	add_at_pos(t_list *head, int data, int pos);
int		count_node(t_list *head);
int     count_node1(s_list *head);
s_list  *create_node1(int data);
t_list	*create_node(int data);
void    add_at_front(t_list **head, int data);
t_list	*initial_stack(int ac, char *av[]);
int     del_first_node(t_list **head);
void    push_b(t_list **stack_a, t_list **stack_b);
void    push_a(t_list **stack_a, t_list **stack_b);
void    ft_check_sorted(t_list *stack_a);
bool    is_number(char number[]);
void    sort_3_num(t_list **stack_a);
s_list  *find_lis(t_list *stack_a);
s_list  *ft_strduppp(s_list *list);
void    split_stacks(t_list **stack_a, t_list **stack_b, s_list *arr);
s_list  *ft_join_arr(s_list *list, int data);
int     *convert_arr1(s_list *stack_a);
void    send_min_to_top(t_list **stack_a);
void    index_stack(t_list *stack);
int     max_in_stack(t_list *stack);
int     min_in_stack(t_list *stack);
int     position(t_list **stack, int data);
void    empty_the_stack(t_list **stack_a, t_list **stack_b);
int		find_in_a(t_list *stack_a, int data);
void    empty_stack(t_list **stack_a, t_list **stack_b);
int     *convert_arr(t_list *stack_a);
void big_sort(t_list **stack_a, t_list **stack_b);
int main(int ac, char *av[]);

#endif