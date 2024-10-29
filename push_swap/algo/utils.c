/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vihane <vihane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:44:24 by vihane            #+#    #+#             */
/*   Updated: 2024/10/13 03:31:02 by vihane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*RETOURNE LA NOEUD AVEC LA VALEUR MAXIMALE*/
t_list_node	*find_biggest(t_list_node *stack)
{
	long		biggest;
	t_list_node	*biggest_node;

	if (!stack)
		return (NULL);
	biggest = LONG_MIN;
	while (stack)
	{
		if (stack->data > biggest)
		{
			biggest = stack->data;
			biggest_node = stack;
		}
		stack = stack->next;
	}
	return (biggest_node);
}

t_list_node	*find_smallest(t_list_node *stack)
{
	long		min;
	t_list_node	*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->data < min)
		{
			min = stack->data;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_list_node	*find_last(t_list_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	size_of_stack(t_list_node *stack)
{
	int	size;

	if (!stack)
		return (0);
	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

/*FONCTION QUI RECHERCHE LE NOEUD QUI A CHEPEAST DEFINI PAR SET_THE_CHEAPEST*/
t_list_node	*get_cheapest(t_list_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
