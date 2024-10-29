/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vihane <vihane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:05:47 by vihane            #+#    #+#             */
/*   Updated: 2024/10/13 03:31:36 by vihane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

void	add_node(t_list_node **stack, int value)
{
	t_list_node	*new_node;
	t_list_node	*last_node;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_list_node));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->data = value;
	if (!(*stack))
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

void	create_check_args(t_list_node **stack_a, char **argv, bool is_split)
{
	int		i;
	long	nb;

	i = 0;
	while (argv[i])
	{
		nb = ft_atol(argv[i]);
		if (check_syntax(argv[i]) || nb < INT_MIN || nb > INT_MAX
			|| check_double(*stack_a, nb))
		{
			put_error(stack_a, argv, is_split);
			return ;
		}
		add_node(stack_a, (int)nb);
		i++;
	}
}

/*FONCTION POUR PUSH LE NOEUD CIBLE AU DESSUS DE LA PILE*/
void	first_push(t_list_node **stack, t_list_node *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}
