/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:06:32 by mannahri          #+#    #+#             */
/*   Updated: 2022/05/31 18:35:12 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_empty(t_list *head)
{
	if (head == NULL)
	{
		ft_putstr_fd("the list is empty", 0);
		return (0);
	}
	return (1);
}

int	del_first_node(t_list **head)
{
	t_list	*tmp;
	int		i;

	tmp = *head;
	*head = (*head)->next;
	i = tmp->data;
	free(tmp);
	return (i);
}

int	count_node1(t_help *head)
{
	int		count;
	t_help	*tmp;

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

t_help	*create_node1(int data)
{
	t_help	*head;

	head = (t_help *)malloc(sizeof(t_help));
	if (!head)
	{
		ft_putstr_fd("Error allocation.", 0);
		return (NULL);
	}
	head->data = data;
	head->next = NULL;
	return (head);
}
