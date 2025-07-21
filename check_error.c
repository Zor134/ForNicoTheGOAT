/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laudinot <laudinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 08:01:47 by louis             #+#    #+#             */
/*   Updated: 2025/07/16 16:37:40 by laudinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gerer les signes , les doublons, pas de parametres , int max int min , pas d'arg , un seul arg

#include "push_swap.h"
int ft_free_stack(t_stack **stack)
{
    t_stack *tmp;
    while (*stack != NULL)
    {
        tmp = *stack;
        *stack = (*stack)->next;
        free (tmp);
    }
    printf("Error\n");
    return (1);
}

int ft_check_doublons(t_stack **stack_a)
{
    t_stack *tmp;
    t_stack *stack;
    
    stack = *stack_a;
    while (stack->next != NULL)
    {
        tmp = stack->next;
        while (tmp != NULL)
        {
            if (tmp->value == stack->value)
                return (ft_free_stack(stack_a));
            tmp = tmp->next;
        }
        stack = stack->next;
    }
    return(0);
}
int push(t_stack **stack_source, t_stack **stack_dest)
{
    t_stack *tmp;

    tmp = NULL;
    if(!(*stack_source))
        return (1);
    tmp = *stack_source;
    *stack_source = (*stack_source)->next;
    if (*stack_source)
        (*stack_source)->prev = NULL;
    tmp->next = *stack_dest;
    if (*stack_dest)
        (*stack_dest)->prev = tmp;
    *stack_dest = tmp;
    tmp->prev = NULL;
    return(0);
}