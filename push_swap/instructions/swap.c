/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vihane <vihane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:54:09 by vihane            #+#    #+#             */
/*   Updated: 2024/10/11 19:12:58 by vihane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_stack(t_list_node **stack)
{
	t_list_node	*first;
	t_list_node	*second;

	if (!stack || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	*stack = second;
}

void	sa(t_list_node **stack_a)
{
	swap_stack(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_list_node **stack_b)
{
	swap_stack(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_list_node **stack_a, t_list_node **stack_b)
{
	swap_stack(stack_a);
	swap_stack(stack_b);
	write(1, "ss\n", 3);
}
