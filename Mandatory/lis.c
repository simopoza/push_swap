/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:49:01 by mannahri          #+#    #+#             */
/*   Updated: 2022/05/30 18:14:42 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_help	*ft_strduppp(t_help *list)
{
	t_help	*tmp;
	t_help	*tmp1;
	int		len;

	len = count_node1(list);
	tmp1 = list;
	tmp = NULL;
	while (tmp1)
	{
		ft_lstadd_back(&tmp, create_node1(tmp1->data));
		tmp1 = tmp1->next;
	}
	return (tmp);
}

t_help	*ft_join_arr(t_help *list, int data)
{
	if (list == NULL)
	{
		list = create_node1(data);
	}
	else
		ft_lstadd_back(&list, create_node1(data));
	return (list);
}

t_help	*copy_list(t_help *head)
{
	t_help	*new_node;

	if (head == NULL)
		return (NULL);
	else
	{
		new_node = (t_help *)malloc(sizeof(t_help));
		new_node->data = head->data;
		new_node->next = copy_list(head->next);
		return (new_node);
	}
}

void	free_list(t_help *list)
{
	t_help	*tmp;
	t_help	*head;

	head = list;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

t_help	*ft_find_max_arr(t_list *stack_a)
{
	t_list	*curr;
	t_list	*tmp;
	t_help	*max;

	max = NULL;
	tmp = stack_a;
	curr = stack_a->next;
	while (curr)
	{
		if (count_node1(tmp->arr) < count_node1(curr->arr))
		{
			free_list(max);
			max = copy_list(curr->arr);
		}
		tmp = tmp->next;
		curr = curr->next;
	}
	curr = stack_a;
	while (curr)
	{
		free_list(curr->arr);
		curr = curr->next;
	}
	return (max);
}
