/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 21:33:41 by mannahri          #+#    #+#             */
/*   Updated: 2022/05/30 18:21:43 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_help	*add_at_end1(t_help *head, int data)
{
	t_help	*tmp;

	tmp = create_node1(data);
	if (head == NULL)
		return (tmp);
	head->next = tmp;
	return (tmp);
}

t_help	*ft_lstlast(t_help *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

t_list	*ft_lstlastt(t_list *lst)
{
	t_list	*last;

	last = lst;
	while (last)
	{
		if (!last->next)
			return (last);
		last = last->next;
	}
	return (last);
}

void	ft_lstadd_back(t_help **lst, t_help *new)
{
	t_help	*tmp;

	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = ft_lstlast(*lst);
		tmp->next = new;
		new->next = NULL;
	}
}
