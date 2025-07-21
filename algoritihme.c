/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritihme.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis <louis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:04:43 by louis             #+#    #+#             */
/*   Updated: 2025/07/21 15:31:00 by louis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"

ft_tri_algo(t_stack **head_a, t_stack **tail_a)
{
    int a;
    int b;
    int c;

    a = (*head_a)->value;
    b = (*head_a)->next->value;
    c = (*head_a)->next->next->value;
    if (a > b && a < c)
        ft_swap(head_a, 'a');
    else if (a > b && a > c && b < c)
    {
        ft_reverse_rotate(head_a, tail_a, 'a');
        ft_swap(head_a, 'a');   
    }
}