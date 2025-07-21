/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis <louis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 11:32:58 by louis             #+#    #+#             */
/*   Updated: 2025/07/21 12:15:51 by louis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	ft_double_swap(t_struct *env)
{
    ft_swap(&env->head_a, 0);
    ft_swap(&env->head_a, 0);
    write(1, "ss\n", 3);
}
void    ft_double_rotate(t_struct *env)
{
    ft_rotate(&env->head_a,&env->tail_a, 0);
    ft_rotate(&env->head_b,&env->tail_b, 0);
    write(1, "rr\n", 3);
}
void    ft_double_reverse_rotate(t_struct *env)
{
    ft_reverse_rotate(&env->head_a,&env->tail_a, 0);
    ft_reverse_rotate(&env->head_b,&env->tail_b, 0);
    write(1, "sss\n", 4);
}