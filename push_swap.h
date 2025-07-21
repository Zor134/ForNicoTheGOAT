/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis <louis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 07:15:32 by laudinot          #+#    #+#             */
/*   Updated: 2025/07/21 10:14:44 by louis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_struct //ENV
{
	t_stack			*head_a;
	t_stack			*head_b;
	t_stack			*tail_a;
	t_stack			*tail_b;
	t_stack			*node;
	t_stack			*tmp;
	t_stack			*tmp_end;
	char			**split;
	int				index_argv;
	int				index_split;
	int				pos;
}					t_struct;

int					main(int argc, char **argv);
void				init_var(t_struct *env);
void				ft_lstadd_back1(t_stack **lst, t_stack *new);
t_stack				*ft_newnode(int value, int index);
void				ft_push(t_stack **stack_source, t_stack **stack_destination);
void				ft_rotate(t_stack **head, t_stack **tail);
void				ft_reverse_rotate(t_stack **head, t_stack **tail);
void				ft_swap(t_stack **stack);
int					ft_check_doublons(t_stack **stack_a);
int 				ft_free_stack(t_stack **stack_a);

#endif