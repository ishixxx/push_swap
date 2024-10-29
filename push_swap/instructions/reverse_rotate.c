/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vihane <vihane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:22:15 by vihane            #+#    #+#             */
/*   Updated: 2024/10/12 22:23:08 by vihane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_r_stack(t_list_node **stack)
{
	t_list_node	*last;
	t_list_node	*second_last;

	if (!*stack || !(*stack)->next)
		return ;
	last = find_last(*stack);
	second_last = last->prev;
	second_last->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	(*stack)->prev = last;
	*stack = last;
}

void	rra(t_list_node **stack_a)
{
	reverse_r_stack(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_list_node **stack_b)
{
	reverse_r_stack(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list_node **stack_a, t_list_node **stack_b)
{
	reverse_r_stack(stack_a);
	reverse_r_stack(stack_b);
	write(1, "rrr\n", 4);
}
