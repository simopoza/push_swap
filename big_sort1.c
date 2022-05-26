/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 18:16:28 by mannahri          #+#    #+#             */
/*   Updated: 2022/05/18 10:46:08 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    find_min(t_list **stack_a)
{
    t_list  *tmp;
    int     min;
    int index;
    int i;

    i = 0;
    tmp = *stack_a;
    min  = (*stack_a)->data;
    while (tmp)
    {
        if (min >= tmp->data)
        {
                min = tmp->data;
                index = i;
        }
        tmp = tmp->next;
        i++;
    }
    return (index);
}

void    send_min_to_top(t_list **stack_a)
{
    t_list  *tmp;
    int     len;

    int index = find_min(stack_a);
    if (index == 0)
        return ;
    tmp = *stack_a;
    len = count_node(tmp);
    while (index != 0)
    {
        if (index <= (len / 2))
            ra_rb(stack_a, "ra\n");
        else if (index > (len / 2))
            rra_rrb(stack_a, "rra\n");
        index = find_min(stack_a);
    }
}

int is_it_here(s_list *arr, int data)
{
    s_list *tmp;

    tmp = arr;
    while (tmp)
    {
        if (tmp->data == data)
            return (1);
        tmp = tmp->next;
    }
    return (0);
}

int *convert_arr(t_list *stack_a)
{
    int i;
    int *arr;
    int len;

    i = 0;
    len = count_node(stack_a);
    arr = malloc(sizeof (int) * (len + 1));
    if (!arr)
    {
        ft_putstr_fd("Error Overflow\n", 2);
        return (NULL);
    }
    while (i < len)
    {
        arr[i++]  = stack_a->data;
        stack_a = stack_a->next;
    }
    arr[i] = 0;
    return (arr);
}

void split_stacks(t_list **stack_a, t_list **stack_b, s_list *arr)
{
    int *array;
    int i;
    int len;

    i = 0;
    array = convert_arr(*stack_a);
    len = count_node(*stack_a);
    while (i < len)
    {
        if (is_it_here(arr, array[i]) == 1)
            ra_rb(stack_a, "ra\n");
        else
            push_b(stack_a, stack_b);
        i++;
    }
}
