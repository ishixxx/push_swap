/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vihane <vihane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:49:27 by vihane            #+#    #+#             */
/*   Updated: 2024/10/08 17:54:35 by vihane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_lstadd_back(t_list_node **stack, t_list_node *new)
{
	t_list_node	*nb;

	if (*stack)
	{
		nb = ft_lstlast(*stack);
		nb->next = new;
		new->next = NULL;
	}
	else
	{
		nb = new;
		(*stack)->next = NULL;
	}
}

void	ft_lstadd_front(t_list_node **stack, t_list_node *new)
{
	new->next = *stack;
	*stack = new;
}

t_list_node	*ft_lstlast(t_list_node *stack)
{
	t_list_node	*tmp;

	tmp = stack;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

t_list_node	*ft_lstnew(int value)
{
	t_list_node	*new_node;

	new_node = (t_list_node *)malloc(sizeof(*new_node));
	if (!new_node)
		return (NULL);
	new_node->data = value;
	new_node->index = -1;
	new_node->next = NULL;
	return (new_node);
}

int	ft_lstsize(t_list_node *stack)
{
	int			size;
	t_list_node	*tmp;

	tmp = stack;
	size = 0;
	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}
