/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:09:46 by mannahri          #+#    #+#             */
/*   Updated: 2022/05/26 11:05:46 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char *av[])
{
    t_list *stack_a;
    t_list *stack_b;
    if (ac <= 2)
        exit(1);
    stack_a = initial_stack(ac, av);
    stack_b = NULL;
    ft_check_sorted(stack_a);
    if (ac == 4)
        sort_3_num(&stack_a);
    send_min_to_top(&stack_a);
    s_list *lis = find_lis(stack_a);
    split_stacks(&stack_a, &stack_b, lis);
    index_stack(stack_a);
    index_stack(stack_b);
    if (ac > 4)
    {
        big_sort(&stack_a, &stack_b);
        send_min_to_top(&stack_a);
    }
    // tmp = stack_a;
    // while (tmp != NULL)
    // {
    //     printf("yooo finlly : >>>>>>> stack_a->data >>>>> : %d\n", tmp->data);
    //     tmp = tmp->next;
    // }
}