/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vihane <vihane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:46:39 by vihane            #+#    #+#             */
/*   Updated: 2024/10/12 21:33:25 by vihane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				data;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_list	*target_node;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list_node;

void				push_stack(t_list_node **dst, t_list_node **src);
void				pa(t_list_node **stack_a, t_list_node **stack_b);
void				pb(t_list_node **stack_a, t_list_node **stack_b);

void				reverse_r_stack(t_list_node **stack);
void				rra(t_list_node **stack_a);
void				rrb(t_list_node **stack_b);
void				rrr(t_list_node **stack_a, t_list_node **stack_b);

void				rotate_stack(t_list_node **stack);
void				ra(t_list_node **stack_a);
void				rb(t_list_node **stack_b);
void				rr(t_list_node **stack_a, t_list_node **stack_b);

void				swap_stack(t_list_node **stack);
void				sa(t_list_node **stack_a);
void				sb(t_list_node **stack_b);
void				ss(t_list_node **stack_a, t_list_node **stack_b);

int					check_double(t_list_node *stack_a, long n);
int					check_syntax(char *arg);
int					stack_is_sorted(t_list_node *stack);
void				put_error(t_list_node **stack_a, char **param,
						bool is_split);

void				free_split(char **split);
void				free_stack(t_list_node **stack);

void				index_stack(t_list_node *stack);
void				update_target_of_a(t_list_node *dest, t_list_node *to_move);
void				update_the_cost(t_list_node *stack_a, t_list_node *stack_b);
void				set_the_cheapest(t_list_node *stack);
void				init_a(t_list_node *stack_a, t_list_node *stack_b);

void				print_list(t_list_node *head);
int					main(int argc, char **argv);

void				sort_three(t_list_node **stack);

void				move_stack(t_list_node **stack_a, t_list_node **stack_b);
void				sort_stack(t_list_node **stack_a, t_list_node **stack_b);

void				add_node(t_list_node **stack, int value);
void				create_check_args(t_list_node **stack_a, char **argv,
						bool is_split);
void				first_push(t_list_node **stack, t_list_node *top_node,
						char stack_name);

void				ft_lstadd_back(t_list_node **stack, t_list_node *new);
void				ft_lstadd_front(t_list_node **stack, t_list_node *new);
t_list_node			*ft_lstlast(t_list_node *stack);
t_list_node			*ft_lstnew(int value);
int					ft_lstsize(t_list_node *stack);

t_list_node			*get_cheapest(t_list_node *stack);
t_list_node			*find_last(t_list_node *stack);
t_list_node			*find_biggest(t_list_node *stack);
t_list_node			*find_smallest(t_list_node *stack);
int					size_of_stack(t_list_node *stack);

char				**ft_split(char *str, char separator);
int					nb_of_word(char *str, char separator);
char				*allocate_next_word(char **s, char separator);

#endif /* PUSH_SWAP_H */
