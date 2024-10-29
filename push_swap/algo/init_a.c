/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vihane <vihane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:20:52 by vihane            #+#    #+#             */
/*   Updated: 2024/10/13 03:30:50 by vihane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*FONCTION QUI DETERMINE LA FONCTION DE CHAQUE NOEUD
ET IDENTIFIE SA POSITION PAR RAPPORT A LA MEDIAN*/

void	index_stack(t_list_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = size_of_stack(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}
/*TROUVE LE TARGET NODE : LE PLUS PROCHE PLUS GRAND NOEUD DANS LA PILE A,
	DU NOEUD DE LA PILE B */

void	update_target_of_a(t_list_node *dest, t_list_node *to_move)
{
	t_list_node	*current;
	t_list_node	*target_node;
	long		match_value;

	while (to_move)
	{
		match_value = LONG_MAX;
		current = dest;
		target_node = NULL;
		while (current)
		{
			if (current->data > to_move->data && current->data < match_value)
			{
				match_value = current->data;
				target_node = current;
			}
			current = current->next;
		}
		if (match_value == LONG_MAX)
			to_move->target_node = find_smallest(dest);
		else
			to_move->target_node = target_node;
		to_move = to_move->next;
	}
}

/*CALCULE LE COUT DE MOUVEMENT POUR CHAQUE NOEUD
DANS STACK_B SELON SA POSITION ET LA POSITION DE SON TARGET NODE*/
/*STACK B EST LA SOURCE, STACK_A EST LA DEST*/

void	update_the_cost(t_list_node *stack_a, t_list_node *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = size_of_stack(stack_a);
	len_b = size_of_stack(stack_b);
	while (stack_b)
	{
		if (stack_b->above_median)
			stack_b->push_cost = stack_b->index;
		else
			stack_b->push_cost = len_b - (stack_b->index);
		if (stack_b->target_node->above_median)
			stack_b->push_cost += stack_b->target_node->index;
		else
			stack_b->push_cost += len_a - (stack_b->target_node->index);
		stack_b = stack_b->next;
	}
}

/*FONCTION AUI DETERMINE LE NOEUD LE CHEAPEST,
	DONC LES PLUS ECONOMIQUE A PUSH*/
void	set_the_cheapest(t_list_node *dst)
{
	long		cheapest_data;
	t_list_node	*cheapest_node;

	if (!dst)
		return ;
	cheapest_data = LONG_MAX;
	cheapest_node = NULL;
	while (dst)
	{
		if (dst->push_cost < cheapest_data)
		{
			cheapest_data = dst->push_cost;
			cheapest_node = dst;
		}
		dst = dst->next;
	}
	if (cheapest_node)
		cheapest_node->cheapest = true;
}

void	init_a(t_list_node *stack_a, t_list_node *stack_b)
{
	index_stack(stack_a);
	index_stack(stack_b);
	update_target_of_a(stack_a, stack_b);
	update_the_cost(stack_a, stack_b);
	set_the_cheapest(stack_b);
}
