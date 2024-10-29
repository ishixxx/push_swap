/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vihane <vihane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:11:16 by vihane            #+#    #+#             */
/*   Updated: 2024/10/13 01:21:36 by vihane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate_2(t_list_node **stack_a, t_list_node **stack_b,
		t_list_node *cheapest_node)
{
	while (*stack_a != cheapest_node->target_node && *stack_b != cheapest_node)
		rr(stack_a, stack_b);
	index_stack(*stack_a);
	index_stack(*stack_b);
}

static void	reverse_r2(t_list_node **stack_a, t_list_node **stack_b,
		t_list_node *cheapest_node)
{
	while (*stack_a != cheapest_node->target_node && *stack_b != cheapest_node)
		rrr(stack_a, stack_b);
	index_stack(*stack_a);
	index_stack(*stack_b);
}

void	move_stack(t_list_node **stack_a, t_list_node **stack_b)
{
	t_list_node	*cheapest_node;

	cheapest_node = get_cheapest(*stack_b);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_2(stack_a, stack_b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		reverse_r2(stack_a, stack_b, cheapest_node);
	first_push(stack_b, cheapest_node, 'b');
	first_push(stack_a, cheapest_node->target_node, 'a');
	pa(stack_a, stack_b);
}

static void	data_min_top(t_list_node **stack_a)
{
	while ((*stack_a)->data != find_smallest(*stack_a)->data)
	{
		if (find_smallest(*stack_a)->above_median)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

void	sort_stack(t_list_node **stack_a, t_list_node **stack_b)
{
	int	len_a;

	len_a = size_of_stack(*stack_a);
	while (len_a-- > 3)
		pb(stack_b, stack_a);
	sort_three(stack_a);
	while (*stack_b)
	{
		init_a(*stack_a, *stack_b);
		move_stack(stack_a, stack_b);
	}
	if (!stack_is_sorted(*stack_a))
	{
		index_stack(*stack_a);
		data_min_top(stack_a);
	}
}
