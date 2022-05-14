/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:49:01 by mannahri          #+#    #+#             */
/*   Updated: 2022/05/14 12:54:09 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_max(t_list * stack_a)
{
    t_list *tmp = stack_a;
    int max = tmp->count;
    while (tmp)
    {
        if (max <= tmp->count)
            max = tmp->count;
        tmp = tmp->next;
    }
    return (max);
}

int find_lis(t_list *stack_a)
{
    t_list *tmp;
    t_list *top;
    int     max;
    max = 1;
    tmp = stack_a->next;
    top = stack_a;
    while (top)
    {
        top->count = 0;
        top = top->next;
    }
    top = stack_a; 
    top->count = 1;
    while (tmp)
    {
        max = 1;
        top = stack_a;
        while (top != tmp)
        {
            if (top->data < tmp->data && tmp->count <= top->count)
            {
                if (top->count >= max)
                    max = top->count + 1;
            }
            top = top->next;
        }
        tmp->count = max;
        tmp = tmp->next;
    }
    return (ft_max(stack_a));
}