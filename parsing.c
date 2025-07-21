/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis <louis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 12:40:50 by louis             #+#    #+#             */
/*   Updated: 2025/07/21 13:11:55 by louis            ###   ########.fr       */
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

void ft_free_stack(t_stack **stack)
{
    t_stack *tmp;
    while (*stack != NULL)
    {
        tmp = *stack;
        *stack = (*stack)->next;
        free (tmp);
    }
    printf("Error\n");
    exit(1);
}

void ft_check_doublons(t_stack **stack_a)
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
}
void    ft_fill_stack_a(char **argv, t_struct *env)
{
    while (argv[env->index_argv]) // tant que jai des parametres
	{
		env->index_split = 0;
		env->split = ft_split(argv[env->index_argv], ' '); // stock dans char **split
		if(!env->split)
			return(ft_free_stack(&(env->head_a))); //verifie si que des chiffres, min/max int et signe
		while (env->split[env->index_split]) // tant que jai des chiffres dans mon split
		{
			env->node = ft_newnode(ft_atol(env->split[env->index_split]), env->arg_count); // creation dun noeud avec value et index
			free(env->split[env->index_split]); // free le nombre qu'on met dans noeud
			ft_lstadd_back1(&env->head_a, env->node); // rajoute le noeud creer a la liste si existante sinon creer la liste
			env->index_split++; // pour passer au prochain chiffre de split
            env->arg_count++;
		}
		env->tail_a = env->node;
		env->index_argv++; // passe au prochain argument
		free(env->split); // free le tableau de nombre
	}
}
