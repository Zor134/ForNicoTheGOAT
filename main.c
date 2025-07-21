/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis <louis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 07:23:54 by laudinot          #+#    #+#             */
/*   Updated: 2025/07/21 15:30:40 by louis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_var(t_struct *env)
{
	env->index_argv = 1;
	env->head_a = NULL;
	env->head_b = NULL;
	env->tail_a = NULL;
	env->tail_b = NULL;
	env->node = NULL;
	env->split = NULL;
	env->arg_count = 0;
}

int	main(int argc, char **argv)
{
	t_struct	env;

	init_var(&env);
	if (argc < 2)
		return (1);
	ft_fill_stack_a(argv, &env);
	ft_check_doublons(&env.head_a);
	// faire une fonction qui check si liste est deja trié
	ft_reverse_rotate(&env.head_a, &env.tail_a, 'a');
	ft_swap(&env.head_a, 'a');
	if (env.arg_count == 3)
		ft_tri_algo(&env.head_a, &env.tail_a)
	env.tmp = env.head_a;
	while (env.tmp != NULL) // parcours jusqu'a un noeud nul et pas jusqu'a arriver a lavant dernier
	{
		printf("le nombre est %i\n", env.tmp->value);
		env.tmp = env.tmp->next; //incrementation de la liste
	}
	return (0);
}
// il faut gerer si liste est deja triée



	// env.tmp = env.head_a; //tmp pointe vers stack_a donc head de stack_a
	// printf("Stack A :\n");
	// while (env.tmp != NULL) // parcours jusqu'a un noeud nul et pas jusqu'a arriver a lavant dernier
	// {
	// 	printf("le nombre est %i\n", env.tmp->value);
	// 	env.tmp = env.tmp->next; //incrementation de la liste
	// }


	// ft_swap(&env.head_a, 'a'); // SWAP A
	// printf("SWAP A\n");
	// env.tmp = env.head_a;
	// while (env.tmp != NULL) // parcours jusqu'a un noeud nul et pas jusqu'a arriver a lavant dernier
	// {
	// 	printf("le nombre est %i\n", env.tmp->value);
	// 	env.tmp = env.tmp->next; //incrementation de la liste
	// }


	// ft_reverse_rotate(&env.head_a, &env.tail_a, 'a');
	// printf("rotate A\n");
	// env.tmp = env.head_a;
	// while (env.tmp != NULL) // parcours jusqu'a un noeud nul et pas jusqu'a arriver a lavant dernier
	// {
	// 	printf("le nombre est %i\n", env.tmp->value);
	// 	env.tmp = env.tmp->next; //incrementation de la liste
	// }

	
	// ft_push(&env.head_a, &env.tail_a, &env.head_b, &env.tail_b, 'a');
	// ft_push(&env.head_a, &env.tail_a, &env.head_b, &env.tail_b, 'a');
	// // ft_push(&env.head_b, &env.tail_b, &env.head_a, &env.tail_a);
	// // ft_push(&env.head_a, &env.tail_a, &env.head_b, &env.tail_b);
	// // ft_push(&env.head_b, &env.tail_b, &env.head_a, &env.tail_a);
	// // ft_push(&env.head_a, &env.tail_a, &env.head_b, &env.tail_b);
	// printf("x2 Push A dans B\n");
	// env.tmp = env.head_a;
	// while (env.tmp != NULL) // parcours jusqu'a un noeud nul et pas jusqu'a arriver a lavant dernier
	// {
	// 	printf("STACK A:  %i\n", env.tmp->value);
	// 	env.tmp = env.tmp->next; //incrementation de la liste
	// }
	// env.tmp = env.head_b;
	// printf("\n");
	// while (env.tmp != NULL) // parcours jusqu'a un noeud nul et pas jusqu'a arriver a lavant dernier
	// {
	// 	printf("STACK B : %i\n", env.tmp->value);
	// 	env.tmp = env.tmp->next; //incrementation de la liste
	// }

	// ft_double_reverse_rotate(&env);
	// printf("Double reverse rotate\n");
	// env.tmp = env.head_a;
	// while (env.tmp != NULL) // parcours jusqu'a un noeud nul et pas jusqu'a arriver a lavant dernier
	// {
	// 	printf("STACK A : %i\n", env.tmp->value);
	// 	env.tmp = env.tmp->next; //incrementation de la liste
	// }
	// printf("\n");
	// env.tmp = env.head_b;
	// while (env.tmp != NULL) // parcours jusqu'a un noeud nul et pas jusqu'a arriver a lavant dernier
	// {
	// 	printf("STACK B : %i\n", env.tmp->value);
	// 	env.tmp = env.tmp->next; //incrementation de la liste
	// }
	
	// printf("index_argv vaut : %i\nReverse Stack_A\n", env.index_argv);
	// env.tmp_end = env.tail_a;
	// while (env.tmp_end != NULL)  // parcours jusqua noeud nul dans lautre sens
	// {
	// 	printf("le nombre est %i\n", env.tmp_end->value);
	// 	env.tmp_end = env.tmp_end->prev;
	// }
	// printf("index_argv vaut : %i\nReverse Stack_B\n", env.index_argv);
	// env.tmp_end = env.tail_b;
	// while (env.tmp_end != NULL)  // parcours jusqua noeud nul dans lautre sens
	// {
	// 	printf("le nombre est %i\n", env.tmp_end->value);
	// 	env.tmp_end = env.tmp_end->prev;
	// }
	// ft_free_stack(&env.head_a);
	// ft_free_stack(&env.head_b);