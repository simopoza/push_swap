/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:49:01 by mannahri          #+#    #+#             */
/*   Updated: 2022/05/26 11:06:11 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int ft_max(t_list *stack_a)
// {
//     t_list *curr = stack_a;
//     int max = curr->count;
//     while (curr)
//     {
//         if (max <= curr->count)
//             max = curr->count;
//         curr = curr->next;
//     }
//     return (max);
// }

// int find_lis(t_list *stack_a)
// {
//     t_list *curr;
//     t_list *perv;
//     int max;
//     max = 1;
//     curr = stack_a->next;
//     perv = stack_a;
//     while (perv)
//     {
//         perv->count = 0;
//         perv = perv->next;
//     }
//     perv = stack_a;
//     perv->count = 1;
//     while (curr)
//     {
//         max = 1;
//         perv = stack_a;
//         while (perv != curr)
//         {
//             if (perv->data < curr->data && curr->count <= perv->count)
//             {
//                 if (perv->count >= max)
//                     max = perv->count + 1;
//             }
//             perv = perv->next;
//         }
//         curr->count = max;
//         curr = curr->next;
//     }
//     return (ft_max(stack_a));
// }

// int *ft_join(int *max, int *arr, int i, int j)
// {
//     int p;
//     int *perv;
//     int k;
//     int l;

//     p = i + j;
//     printf (">>>>> : %d\n", p);
//     k = 0;
//     l = 0;
//     perv = malloc(sizeof(int) * (p + 1));
//     if (!perv)
//     {
//         printf("overflow\n");
//         return (NULL);
//     }
//     while (max[l])
//         perv[k++] = max[l++];
//     l = 0;
//     while (arr[l])
//         perv[k++] = arr[l++];
//     perv[k] = '\0';
//     return (perv);
// }

// void    ft_finder(t_list *stack_a)
// {
//     int *max;
//     t_list *perv;
//     t_list *curr;

//     curr = stack_a->next;
//     perv = stack_a;
//     while (perv)
//     {
//         perv->arr = NULL; 
//         perv = perv->next;
//     }
//     perv = stack_a;
//     perv->arr = malloc (sizeof (int) * 2);
//     perv->arr[0] = perv->data;
//     perv->arr[1] = 0;
//     while (curr)
//     {
//         perv = stack_a;
//         while (perv != curr)
//         {
//             if (perv->data < curr->data && ft_lenght(perv->arr) > ft_lenght(curr->arr))
//             {
//                 max = ft_strduppp(perv->arr);
//             }
//             perv = perv->next;
//         }
//         curr->arr = ft_join(max, perv->arr, ft_lenght(max), ft_lenght(perv->arr));
//         curr = curr->next;
//     }
// }

// int ft_lenght(int *arr)
// {
//     int i = 0;
//     if (arr == NULL)
//         return (0);
//     while (arr[i] != '\0')
//         i++;
//     return (i);
// }

// int *ft_strduppp(int *s1)
// {
//     int *str1;
//     int i;

//     i = 0;
//     str1 = malloc(sizeof(int) * (ft_lenght(s1) + 1));
//     if (!str1)
//         return (NULL);
//     while (s1[i])
//     {
//         str1[i] = s1[i];
//         i++;
//     }
//     str1[i] = '\0';
//     return (str1);
// }

// int *ft_join_arr(int *arr, int data)
// {
//     int *max;
//     int len;

//     len = ft_lenght(arr);
//     if (arr == NULL)
//     {
//         max = malloc(sizeof (int) * 2);
//         if (!max)
//         {
//             printf ("Overflow\n");
//             return (NULL);
//         }
//         max[0] = data;
//         max[1] = 0;
//         free (arr);
//         return (max);
//     }
//     max = malloc (sizeof (int) * (len + 2));
//     if (!max)
//     {
//         printf("Overflow\n");
//         return (NULL);
//     }
//     len = 0;
//     while (arr[len])
//     {
//         max[len] = arr[len];
//         len++;
//     }
//     max[len] = data;
//     max[++len] = 0;
//     len = 0;
//     free (arr);
//     return (max);
// }

s_list *ft_strduppp(s_list *list)
{
    s_list *tmp;
    s_list *tmp1;
    int len;

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

s_list *ft_join_arr(s_list *list, int data)
{
    if (list == NULL)
    {
        list = create_node1(data);
    }
    else
        ft_lstadd_back(&list, create_node1(data));

    return (list);
}
s_list *copyList(s_list *head)
{
    if (head == NULL)
        return NULL;
    else
    {
        s_list *newNode = (s_list *)malloc(sizeof(s_list));
        newNode->data = head->data;
        newNode->next = copyList(head->next);
        return newNode;
    }
}

s_list *ft_find_max_arr(t_list *stack_a)
{
    t_list *curr;
    t_list *tmp;
    s_list *max;
    
    tmp = stack_a;
    curr = stack_a->next;
    while (curr)
    {
        if (count_node1(tmp->arr) < count_node1(curr->arr))
        {
            free (curr->arr);
            max = copyList(curr->arr);
        }
        tmp = tmp->next;
        curr = curr->next;
    }
    return (max);
}

s_list *find_lis(t_list *stack_a)
{
    t_list *curr;
    t_list *perv;

    perv = stack_a;
    while (perv)
    {
        perv->arr = NULL;
        perv = perv->next;
    }
    perv = stack_a;
    perv->arr = create_node1(perv->data);
    curr = stack_a->next;
    while (curr)
    {
        perv = stack_a;
        while (perv != curr)
        {
            if (curr->data > perv->data && count_node1(perv->arr) > count_node1(curr->arr))
            {
                if(curr->arr)
                    free(curr->arr);
                curr->arr = ft_strduppp(perv->arr);
            }
            perv = perv->next;
        }
        curr->arr = ft_join_arr(curr->arr, curr->data);  
        curr = curr->next;
    }
    return (ft_find_max_arr(stack_a));
}