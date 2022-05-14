/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:06:32 by mannahri          #+#    #+#             */
/*   Updated: 2022/05/10 17:38:57 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_empty(t_list *head)
{
    if (head == NULL)
    {
        ft_putstr_fd("the list is empty",0);
        return (0);
    }
    return (1);
}

int del_first_node(t_list **head)
{
    t_list *tmp;
    int i;

    tmp = *head;
    *head = (*head)->next;
    i = tmp->data;
    free(tmp);
    return (i);
}