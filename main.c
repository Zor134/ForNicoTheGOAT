/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis <louis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 07:23:54 by laudinot          #+#    #+#             */
/*   Updated: 2025/07/21 10:15:00 by louis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
t_stack	*ft_newnode(int value, int index)
{
	t_stack	*node;
	
	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = index;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
void	ft_lstadd_back1(t_stack **lst, t_stack *new) // lst = stack_a ; new = nouveau noeud a ajouter
{
	t_stack *temp;

	if (lst == NULL || new == NULL) // si ma stack ou mon noeud nexiste pas return
		return;
	if (*lst == NULL) //si ma stack existe mais vide, mon noeud devient head de liste
	{
		*lst = new;
		return;
	}
	temp = *lst; // temp pointe vers tete de liste
	while (temp->next != NULL) // parcours ma liste jusqu'au dernier noeud
		temp = temp->next;
	temp->next = new; // donne ladresse du nouveau noeud au next du denirer de la liste
	new->prev = temp; // donne l'adresse du neoud precedent au nouveau noeud
}
void	init_var(t_struct *env)
{
	env->index_argv = 1;
	env->head_a = NULL;
	env->head_b = NULL;
	env->tail_a = NULL;
	env->tail_b = NULL;
	env->node = NULL;
	env->split = NULL;
}

int	main(int argc, char **argv)
{
	t_struct	env;

	init_var(&env);
	if (argc < 2)
		return (1);
	while (argv[env.index_argv]) // tant que jai des parametres
	{
		env.index_split = 0;
		env.split = ft_split(argv[env.index_argv], ' '); // stock dans char **split
		//printf("%s", env.split[0]);
		if(!env.split)
			return(ft_free_stack(&env.head_a)); //verifie si que des chiffres, min/max int et signe
		while (env.split[env.index_split]) // tant que jai des chiffres dans mon split
		{
			env.node = ft_newnode(ft_atol(env.split[env.index_split]), env.pos); // creation dun noeud avec value et index
			free(env.split[env.index_split]); // free le nombre qu'on met dans noeud
			ft_lstadd_back1(&env.head_a, env.node); // rajoute le noeud creer a la liste si existante sinon creer la liste
			env.index_split++; // pour passer au prochain chiffre de split
			env.pos++; // pour incrementer l'index qu'on donne au noeud
		}
		env.tail_a = env.node;
		env.index_argv++; // passe au prochain argument
		free(env.split); // free le tableau de nombre
	}
	if (ft_check_doublons(&env.head_a)) // check doublon car split check le reste
			return(1);
	env.tmp = env.head_a; //tmp pointe vers stack_a donc head de stack_a
	printf("Stack A :\n");
	while (env.tmp != NULL) // parcours jusqu'a un noeud nul et pas jusqu'a arriver a lavant dernier
	{
		printf("le nombre est %i\n", env.tmp->value);
		env.tmp = env.tmp->next; //incrementation de la liste
	}
	ft_swap(&env.head_a); // SWAP A
	printf("SWAP A\n");
	env.tmp = env.head_a;
	while (env.tmp != NULL) // parcours jusqu'a un noeud nul et pas jusqu'a arriver a lavant dernier
	{
		printf("le nombre est %i\n", env.tmp->value);
		env.tmp = env.tmp->next; //incrementation de la liste
	}
	ft_reverse_rotate(&env.head_a, &env.tail_a);
	printf("rotate A\n");
	env.tmp = env.head_a;
	while (env.tmp != NULL) // parcours jusqu'a un noeud nul et pas jusqu'a arriver a lavant dernier
	{
		printf("le nombre est %i\n", env.tmp->value);
		env.tmp = env.tmp->next; //incrementation de la liste
	}
	// ft_push(&env.stack_a, &env.stack_b);
	// printf("Push A dans B\n");
	// env.tmp = env.head_a;
	// while (env.tmp != NULL) // parcours jusqu'a un noeud nul et pas jusqu'a arriver a lavant dernier
	// {
	// 	printf("STACK A:  %i\n", env.tmp->value);
	// 	env.tmp = env.tmp->next; //incrementation de la liste
	// }
	// env.tmp = env.head_a;
	// while (env.tmp != NULL) // parcours jusqu'a un noeud nul et pas jusqu'a arriver a lavant dernier
	// {
	// 	printf("STACK B : %i\n", env.tmp->value);
	// 	env.tmp = env.tmp->next; //incrementation de la liste
	// }
	
	printf("index_argv vaut : %i\nReverse Stack_A\n", env.index_argv);
	env.tmp_end = env.tail_a;
	while (env.tmp_end != NULL)  // parcours jusqua noeud nul dans lautre sens
	{
		printf("le nombre est %i\n", env.tmp_end->value);
		env.tmp_end = env.tmp_end->prev;
	}
	printf("index_argv vaut : %i\nReverse Stack_B\n", env.index_argv);
	env.tmp_end = env.tail_b;
	while (env.tmp_end != NULL)  // parcours jusqua noeud nul dans lautre sens
	{
		printf("le nombre est %i\n", env.tmp_end->value);
		env.tmp_end = env.tmp_end->prev;
	}
	// ft_free_stack(&env.head_a);
	// ft_free_stack(&env.head_b);
	return (0);
}
// il faut gerer si liste est deja triée