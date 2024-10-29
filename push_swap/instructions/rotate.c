/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vihane <vihane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:53:37 by vihane            #+#    #+#             */
/*   Updated: 2024/10/11 17:54:20 by vihane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_stack(t_list_node **stack)
{
	t_list_node	*first;
	t_list_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = find_last(*stack);
	*stack = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->next = NULL;
	first->prev = last;
}

void	ra(t_list_node **stack_a)
{
	rotate_stack(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_list_node **stack_b)
{
	rotate_stack(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_list_node **stack_a, t_list_node **stack_b)
{
	rotate_stack(stack_a);
	rotate_stack(stack_b);
	write(1, "rr\n", 3);
}
