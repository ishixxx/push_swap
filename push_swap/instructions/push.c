/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vihane <vihane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:22:12 by vihane            #+#    #+#             */
/*   Updated: 2024/10/12 21:11:58 by vihane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_stack(t_list_node **dst, t_list_node **src)
{
	t_list_node	*push_node;

	if (!src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	if (!*dst)
	{
		*dst = push_node;
		push_node->next = NULL;
		push_node->prev = NULL;
	}
	else
	{
		push_node->next = *dst;
		push_node->next->prev = push_node;
		*dst = push_node;
	}
}

void	pa(t_list_node **stack_a, t_list_node **stack_b)
{
	push_stack(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	pb(t_list_node **stack_b, t_list_node **stack_a)
{
	push_stack(stack_b, stack_a);
	write(1, "pb\n", 3);
}
