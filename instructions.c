/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis <louis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:57:03 by laudinot          #+#    #+#             */
/*   Updated: 2025/07/21 10:57:35 by louis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **head)
{
	int	tmp;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return ;
	tmp = (*head)->value;
	(*head)->value = (*head)->next->value;
	(*head)->next->value = tmp;
}

void	ft_rotate(t_stack **head, t_stack **tail)
{
	t_stack	*tmp;

	tmp = *head;
	if ((*head)->next)
		(*head)->next->prev = NULL;
	*head = (*head)->next;
	tmp->next = NULL;
	ft_lstadd_back1(head, tmp);
	*tail = tmp;
}
void	ft_reverse_rotate(t_stack **head, t_stack **tail)
{
	t_stack	*tmp;

	tmp = *tail;
	if ((*tail)->prev)
		(*tail)->prev->next = NULL;
	*tail = (*tail)->prev;
	(*tail)->next = NULL;
	tmp->next = *head;
	tmp->prev = NULL;
	(*head)->prev = tmp;
	*head = tmp;
}

void	ft_push(t_stack **head_source, t_stack **tail_source, t_stack **head_dest, t_stack **tail_dest)
{
	t_stack	*tmp;

	tmp = *head_source;
	if ((*head_source)->next)
		(*head_source)->next->prev = NULL;
	*head_source = (*head_source)->next;
	if (!*head_source)
		*tail_source = NULL;
	if (*head_dest)
		(*head_dest)->prev = tmp;
	tmp->next = *head_dest;
	if (!*tail_dest)
		tail_dest = tmp;
	*head_dest = tmp;

}
// int	push(t_stack **stack_source, t_stack **stack_dest) // pa
// {
// 	t_stack *tmp;

// 	tmp = NULL;
// 	if (!(*stack_source))
// 		return (1);
// 	tmp = *stack_source;
// 	*stack_source = (*stack_source)->next;
// 	if (*stack_source)
// 		(*stack_source)->prev = NULL;
// 	tmp->next = *stack_dest;
// 	if (*stack_dest)
// 		(*stack_dest)->prev = tmp;
// 	*stack_dest = tmp;
// 	tmp->prev = NULL;
// 	return (0);
// }
// int    swap(t_stack **head)
// {
//     t_stack    *tmp;
//     t_stack    *tmp_next;

//     if (!(*head) || !(*head)->next)
//         return (1);
//     tmp = (*head);
//     tmp_next = tmp->next;
//     tmp->next = tmp_next->next;
//     tmp_next->next = tmp;
//     tmp_next->prev = NULL;
//     tmp->prev = tmp_next;
//     if (tmp->next != NULL)
//         tmp->next->prev = tmp;
//     *head = tmp_next;
//     return (0);
// }
// int    push(t_stack **head_source, t_stack **head_dest)
// {
//     t_stack *tmp;

//     if (!(*head_source))
//         return (1);
//     tmp = *head_source;
//     *head_source = (*head_source)->next;
//     if (*head_source)
//         (*head_source)->prev = NULL;
//     tmp->next = *head_dest;
//     if (*head_dest)
//         (*head_dest)->prev = tmp;
//     *head_dest = tmp;
//     tmp->prev = NULL;
//     return (0);
// }
// int    rotate(t_stack **head, t_stack **tail)
// {
//     t_stack    *tmp;

//     if (!(*head) || !(*head)->next)
//         return (1);
//     tmp = *head;
//     *head = (*head)->next;
//     (*head)->prev = NULL;
//     (*tail)->next = tmp;
//     *tail = (*tail)->next;
//     (*tail)->next = NULL;
//     (*tail)->prev = tmp;
//     return (0);
// }
// int    reverse_rotate(t_stack **head, t_stack **tail)
// {
//     t_stack *tmp;

//     if (!(*head) || !(*head)->next)
//         return (1);
//     tmp = *tail;
//     *tail = (*tail)->prev;
//     (*tail)->next = NULL;
//     tmp->prev = NULL;
//     tmp->next = *head;
//     (*head)->prev = tmp;
//     *head = tmp;
//     return (0);
// }