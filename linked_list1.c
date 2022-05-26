/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:06:32 by mannahri          #+#    #+#             */
/*   Updated: 2022/05/24 14:09:08 by mannahri         ###   ########.fr       */
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

int count_node1(s_list *head)
{
    int count;
    s_list *tmp;

    tmp = head;
    count = 0;
    if (head == NULL)
        return (count);
    else
    {
        while (tmp != NULL)
        {
            count++;
            tmp = tmp->next;
        }
    }
    return (count);
}

s_list *create_node1(int data)
{
    s_list *head;

    head = (s_list *)malloc(sizeof(s_list));
    if (!head)
    {
        ft_putstr_fd("Error allocation.", 0);
        return (NULL);
    }
    head->data = data;
    head->next = NULL;
    return (head);
}

s_list *add_at_end1(s_list *head, int data)
{
    s_list *tmp;

    tmp = create_node1(data);
    if (head == NULL)
        return (tmp);
    head->next = tmp;
    return (tmp);
}

s_list *ft_lstlast(s_list *lst)
{
    while (lst)
    {
        if (!lst->next)
            return (lst);
        lst = lst->next;
    }
    return (lst);
}

t_list *ft_lstlastt(t_list *lst)
{
    t_list *last;

    last = lst;
    while (last)
    {
        if (!last->next)
            return (last);
        last = last->next;
    }
    return (last);
}

void ft_lstadd_back(s_list **lst, s_list *new)
{
    s_list *tmp;

    if (*lst == NULL)
        *lst = new;
    else
    {
        tmp = ft_lstlast(*lst);
        tmp->next = new;
        new->next = NULL;
    }
}