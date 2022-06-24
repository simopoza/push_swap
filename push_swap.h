/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 20:51:35 by mannahri          #+#    #+#             */
/*   Updated: 2022/05/31 01:01:45 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct t_move
{
	int	*tmp;
	int	best;
	int	moves;
	int	pos_a;
	int	pos_b;
}	t_move;

typedef struct t_help
{
	int				data;
	struct t_help	*next;
}	t_help;

typedef struct t_list
{
	int				data;
	int				index;
	t_help			*arr;
	struct t_list	*next;
}	t_list;

int		ft_atoi(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isdigit(int c);
void	ft_putstr_fd(char *s, int fd);
int		ft_strchr1(char *str);
void	ft_check_sorted_bonus(t_list *stack_a, t_list *stack_b);
char	*get_next_line(int fd);
char	*ft_substr1(char *s, int start, int len);
char	*ft_strjoin1(char *s1, char *s2);
int		ft_strlen1(char *str);
void	ft_ss_bonus(t_list **stack_a, t_list **stack_b, char *num_of_stack);
void	ft_sa_sb_bonus(t_list **head, char *num_of_stack);
void	ft_rr_bonus(t_list **stack_a, t_list **stack_b, char *num_of_stack);
void	ft_ra_rb_bonus(t_list **head, char *num_of_stack);
void	ft_rrr_bonus(t_list **stack_a, t_list **stack_b, char *num_of_stack);
void	ft_rra_rrb_bonus(t_list **head, char *num_of_stack);
void	ft_push_b_bonus(t_list **stack_a, t_list **stack_b);
void	ft_push_a_bonus(t_list **stack_a, t_list **stack_b);
void	apply_on_top(int tmp_a, int tmp_b, t_list **stack_a, t_list **stack_b);
void	apply_on_bot(int tmp_a, int tmp_b, t_list **stack_a, t_list **stack_b);
void	apply_on_same_sign(int *tmp, t_list **stack_a, t_list **stack_b);
void	apply_on_different_sign(int *tmp, t_list **stack_a, t_list **stack_b);
int		*initial_tmp(int pos_a);
int		*best_moves(t_list **stack_a, t_list **stack_b);
void	apply_on_zero(int *tmp, t_list **stack_a, t_list **stack_b);
int		moves_in_b(int pos_b, t_list *stack_b);
void	free_list(t_help *list);
t_help	*copy_list(t_help *head);
t_help	*ft_find_max_arr(t_list *stack_a);
void	sort_5_num(t_list **stack_a, t_list **stack_b);
void	sort_4_num(t_list **stack_a, t_list **stack_b);
void	sort_2_num(t_list **stack_a);
int		moves_in_a(int data, t_list *stack_a);
void	sa_sb(t_list **head, char *num_of_stack);
void	ss(t_list **stack_a, t_list **stack_b, char *num_of_stack);
void	ra_rb(t_list **head, char *num_of_stack);
void	rr(t_list **stack_a, t_list **stack_b, char *num_of_stack);
void	rra_rrb(t_list **head, char *num_of_stack);
void	rrr(t_list **stack_a, t_list **stack_b, char *num_of_stack);
void	push_b(t_list **stack_a, t_list **stack_b);
void	push_a(t_list **stack_a, t_list **stack_b);
t_list	*ft_lstlastt(t_list *lst);
t_help	*ft_lstlast(t_help *lst);
void	ft_lstadd_back(t_help **lst, t_help *new);
t_help	*add_at_end1(t_help *head, int data);
t_list	*add_at_end(t_list *head, int data);
int		is_empty(t_list *head);
void	add_at_pos(t_list *head, int data, int pos);
int		count_node(t_list *head);
int		count_node1(t_help *head);
t_help	*create_node1(int data);
t_list	*create_node(int data);
void	add_at_front(t_list **head, int data);
t_list	*initial_stack(int ac, char *av[]);
int		del_first_node(t_list **head);
void	ft_check_sorted(t_list *stack_a);
bool	is_number(char number[]);
void	sort_3_num(t_list **stack_a);
t_help	*find_lis(t_list *stack_a);
t_help	*ft_strduppp(t_help *list);
void	split_stacks(t_list **stack_a, t_list **stack_b, t_help *arr);
t_help	*ft_join_arr(t_help *list, int data);
int		*convert_arr1(t_help *stack_a);
void	send_min_to_top(t_list **stack_a);
void	index_stack(t_list *stack);
int		max_in_stack(t_list *stack);
int		min_in_stack(t_list *stack);
int		position(t_list **stack, int data);
void	empty_the_stack(t_list **stack_a, t_list **stack_b);
int		find_in_a(t_list *stack_a, int data);
void	empty_stack(t_list **stack_a, t_list **stack_b);
int		*convert_arr(t_list *stack_a);
void	big_sort(t_list **stack_a, t_list **stack_b);
int		main(int ac, char *av[]);

#endif