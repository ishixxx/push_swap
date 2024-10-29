/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vihane <vihane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:59:05 by vihane            #+#    #+#             */
/*   Updated: 2024/10/12 22:45:07 by vihane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_syntax(char *arg)
{
	if (!arg || !arg[0])
		return (1);
	if (!(*arg == '+' || *arg == '-' || (*arg >= '0' && *arg <= '9')))
		return (1);
	if ((*arg == '-' || *arg == '+') && !(arg[1] >= '0' && arg[1] <= '9'))
		return (1);
	while (*++arg)
	{
		if (!(*arg >= '0' && *arg <= '9'))
			return (1);
	}
	return (0);
}

int	check_double(t_list_node *stack_a, long n)
{
	t_list_node	*current;

	current = stack_a;
	while (current)
	{
		if (current->data == n)
			return (1);
		current = current->next;
	}
	return (0);
}

void	put_error(t_list_node **stack, char **param, bool is_split)
{
	if (is_split)
		free_split(param);
	free_stack(stack);
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

int	stack_is_sorted(t_list_node *stack)
{
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}
