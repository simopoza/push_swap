/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:09:46 by mannahri          #+#    #+#             */
/*   Updated: 2022/05/15 13:54:08 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char *av[])
{
    t_list *stack_a;
    t_list *stack_b;
    // t_list *tmp;

    // if (ac <= 2)
    //     exit(1);
    stack_a = initial_stack(ac, av);
    stack_b = NULL;
    // ft_check_sorted(stack_a);
    // ft_finder(stack_a);
    int *k = find_lis(stack_a);
    int i = 0;
    while (k[i])
        printf (">>>>> %d\n", k[i++]);
    // int i = find_lis(stack_a);
    // printf("lis : %d\n", i);
    // sort_3_num(stack_a);
    // tmp = stack_a;
    // while (tmp != NULL)
    // {
    //     printf(">>>>>>>Tis node after : %d\n", tmp->data);
    //     tmp = tmp->next;
    // }
    // ra_rb(&stack_a, "ra\n");
    // tmp = stack_a;
    // while (tmp != NULL)
    // {
    //     printf("Tis node after : %d\n", tmp->data);
    //     tmp = tmp->next;
    // }
    // push_b(&stack_a, &stack_b);
    // push_b(&stack_a, &stack_b);
    // tmp = stack_b;
    // while (tmp != NULL)
    // {
    //     printf("\nTis node in stack_b : %d\n", tmp->data);
    //     tmp = tmp->next;
    // }
    // tmp = stack_a;
    // while (tmp != NULL)
    // {
    //     printf("Tis node in stack_a : %d\n", tmp->data);
    //     tmp = tmp->next;
    // }
}