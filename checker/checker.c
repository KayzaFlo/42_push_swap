/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin42 <fgeslin42@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:36:10 by fgeslin42         #+#    #+#             */
/*   Updated: 2023/01/29 20:52:28 by fgeslin42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// "" && exit : arg NULL
// "OK\n" : a sorted && b empty
// "KO\n" : a !sorted || b !empty
// "ERROR\n" : nan, int overflow, duplicate, wrong instruction

int main(int argc, char const *argv[])
{
    t_stack stack_a;
    t_stack stack_b;
    char    *str;
    //char    *instruction;
    int     i;

    if (argc < 2)
        return (-1);
    parse(&stack_a, argc, argv);
    stack_b.lst = 0;
    str = get_next_line(STDIN_FILENO);
    i = 0;
    while (str)
    {
        if (str[i] == 's')
        {
            i++;
            if (str[i] == '\0')
            {
                str = get_next_line(STDIN_FILENO);
                i = 0;
            }
            if (str[i] == 'a')
            {
                swap(&stack_a);
            }
            else if (str[i] == 'b')
            {
                swap(&stack_b);
            }
            else
            {
                printf("ERROR1\n");
                exit (-1);
            }
        }
        else if (str[i] == 'p')
        {
            i++;
            if (str[i] == '\0')
            {
                str = get_next_line(STDIN_FILENO);
                i = 0;
            }
            if (str[i] == 'a')
            {
                push(&stack_a);
            }
            else if (str[i] == 'b')
            {
                push(&stack_b);
            }
            else
            {
                printf("ERROR1\n");
                exit (-1);
            }
        }
        else if (str[i] == 'r')
        {
            i++;
            if (str[i] == '\0')
            {
                str = get_next_line(STDIN_FILENO);
                i = 0;
            }
            if (str[i] == 'a')
            {
                rotate(&stack_a);
            }
            else if (str[i] == 'b')
            {
                rotate(&stack_b);
            }
            else if (str[i] == 'r')
            {
                i++;
                if (str[i] == '\0')
                {
                    str = get_next_line(STDIN_FILENO);
                    i = 0;
                }
                if (str[i] == 'a')
                {
                    r_rotate(&stack_a);
                }
                else if (str[i] == 'b')
                {
                    r_rotate(&stack_b);
                }
                else
                {
                    printf("ERROR2\n");
                    exit (-1);
                }
            }
            else
            {
                printf("ERROR3\n");
                exit (-1);
            }
        }
        else
        {
            printf("ERROR4\n");
            exit (-1);
        }
        i++;
        if (str[i] == '\n')
        {
            i++;
        }
        if (str[i] == '\0')
        {
            str = get_next_line(STDIN_FILENO);
            i = 0;
        }
    }
    printf("%d\n", *(int *)stack_a.lst->content);
    printf("str %s\n", str);
    return 0;
}
