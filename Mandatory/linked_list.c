/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:13:10 by mannahri          #+#    #+#             */
/*   Updated: 2022/05/30 17:22:46 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*create_node(int data)
{
	t_list	*head;

	head = (t_list *)malloc(sizeof(t_list));
	if (!head)
	{
		ft_putstr_fd("Error allocation.", 0);
		return (NULL);
	}
	head->data = data;
	head->next = NULL;
	return (head);
}

int	count_node(t_list *head)
{
	int		count;
	t_list	*tmp;

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

t_list	*add_at_end(t_list *head, int data)
{
	t_list	*tmp;

	tmp = create_node(data);
	if (head == NULL)
		return (tmp);
	head->next = tmp;
	return (tmp);
}

void	add_at_front(t_list **head, int data)
{
	t_list	*tmp;
	int		datta;

	tmp = create_node(data);
	if ((*head) == NULL)
	{
		(*head) = tmp;
		return ;
	}
	else
	{
		tmp->next = (*head);
		(*head) = tmp;
	}
	datta = tmp->data;
	while (tmp->next)
	{
		if (datta == tmp->next->data)
		{
			ft_putstr_fd("Error duplication.", 2);
			exit(0);
		}
		tmp = tmp->next;
	}
}

void	add_at_pos(t_list *head, int data, int pos)
{
	t_list	*tmp;
	t_list	*new;

	tmp = head;
	new = create_node(data);
	while (--pos != 1)
		tmp = tmp->next;
	new->next = tmp->next;
	tmp->next = new;
}
