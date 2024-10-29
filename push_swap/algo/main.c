/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vihane <vihane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 20:20:37 by vihane            #+#    #+#             */
/*   Updated: 2024/10/12 22:44:56 by vihane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// void	print_list(t_list_node *head)
// {
// 	t_list_node	*current;

// 	current = head;
// 	while (current != NULL)
// 	{
// 		printf("%d\n", current->data);
// 		current = current->next;
// 	}
// }

static void	full_sort(t_list_node **stack_a)
{
	int			len_a;
	t_list_node	*stack_b;

	stack_b = NULL;
	len_a = size_of_stack(*stack_a);
	if (len_a == 2 && !stack_is_sorted(*stack_a))
		sa(stack_a);
	else if (len_a == 3 && !stack_is_sorted(*stack_a))
		sort_three(stack_a);
	else if (len_a > 3 && !stack_is_sorted(*stack_a))
		sort_stack(stack_a, &stack_b);
}

int	main(int argc, char **argv)
{
	t_list_node	*stack_a;
	char		**split_argv;

	stack_a = NULL;
	if (argc == 1 || (argc == 2 && !argv[1]))
		return (1);
	else if (argc == 2)
	{
		if (argv[1][0] == '\0')
			write(2, "Error\n", 6);
		else
		{
			split_argv = ft_split(argv[1], ' ');
			if (!split_argv)
				return (1);
			create_check_args(&stack_a, split_argv, true);
			free_split(split_argv);
		}
	}
	else
		create_check_args(&stack_a, argv + 1, false);
	full_sort(&stack_a);
	free_stack(&stack_a);
	return (0);
}
