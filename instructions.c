/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis <louis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:57:03 by laudinot          #+#    #+#             */
/*   Updated: 2025/07/21 15:30:40 by louis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **head, char id)
{
	int	tmp;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return ;
	tmp = (*head)->value;
	(*head)->value = (*head)->next->value;
	(*head)->next->value = tmp;
	if (id == 'a')
		write(1, "sa\n", 3);
	else if (id == 'b')
		write(1, "sb\n", 3);
}

void	ft_rotate(t_stack **head, t_stack **tail, char id)
{
	t_stack	*tmp;

	tmp = *head;
	if ((*head)->next)
		(*head)->next->prev = NULL;
	*head = (*head)->next;
	tmp->next = NULL;
	ft_lstadd_back1(head, tmp);
	*tail = tmp;
	if (id == 'a')
		write(1, "ra\n", 3);
	else if (id == 'b')
		write(1, "rb\n", 3);
}
void	ft_reverse_rotate(t_stack **head, t_stack **tail, char id)
{
	t_stack	*tmp;

	if (*head == *tail)
		return;
	tmp = *tail;
	if ((*tail)->prev)
		(*tail)->prev->next = NULL;
	*tail = (*tail)->prev;
	(*tail)->next = NULL;
	tmp->next = *head;
	tmp->prev = NULL;
	(*head)->prev = tmp;
	*head = tmp;
	if (id == 'a')
		write(1, "rra\n", 4);
	else if (id == 'b')
		write(1, "rrb\n", 4);
}

void	ft_push(t_stack **head_source, t_stack **tail_source, t_stack **head_dest, t_stack **tail_dest, char id)
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
		*tail_dest = tmp;
	*head_dest = tmp;
	if (id == 'a')
		write(1, "pa\n", 3);
	else if (id == 'b')
		write(1, "pb\n", 3);
}
