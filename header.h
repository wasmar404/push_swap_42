/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:04:37 by wasmar            #+#    #+#             */
/*   Updated: 2024/09/07 20:53:01 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_stack
{
	int				number;
	int				median;
	int				cost;
	int				position;
	struct t_stack	*next;
	struct t_stack	*prev;
	struct t_stack	*target;
}					t_stack;
typedef struct t_input
{
	int				input_count;
}					t_input;
t_stack				*create_new_node(int number);
t_stack				*create_list_a(int *input, int count, int flag);
void				add_cost_of_a_and_b(t_stack *stack_a, t_stack **stack_b);
int					count_list(t_stack *temp);
bool				check_numeric(char **data, int flag);
void				find_cost(t_stack *head);
void				free_2d_array(char **data);
void				one_argument_helper(t_input **input, t_stack **stack_a,
						bool indicator, int **data);
void				one_argument_helper1(t_input **input, t_stack **stack_a,
						bool indicator, int **data);
void				set_target_of_a(t_stack *stack_a, t_stack *stack_b);
void				free_linked_list(t_stack *node);
void				return_pointer_to_first(t_stack **node);
void				free_2d_array(char **data);
void				swap(t_stack **head);
void				rotate(t_stack **head);
void				reverse_rotate(t_stack **head);
void				push(t_stack **send_form, t_stack **send_to);
t_stack				*find_cheapest_node(t_stack *head);
bool				split_argument(char *argv, t_input *input, int **data);
bool				check_if_sorted(t_stack *head);
bool				create_array_with_input(char **input, int count,
						int **data);
int					ft_atoi(char *nptr, int *ftatoi);
bool				check_dup(t_stack *head);
void				set_pos_and_median(t_stack *head);
t_stack				*find_max_pointer(t_stack *head);
bool				check_if_sorted(t_stack *head);
bool				check_dup(t_stack *head);
bool				check_numeric(char **data, int flag);
void				one_argument(char *argv, t_stack **stack_a);
char				**ft_split(char *str, char *charset);
void				sa(t_stack **head, int flag);
void				pa(t_stack **head_a, t_stack **head_b);
void				ra(t_stack **head, int flag);
void				rra(t_stack **head, int flag);
void				rrb(t_stack **head, int flag);
void				rb(t_stack **head, int flag);
void				sb(t_stack **head, int flag);
void				many_args_error(int *data, bool error);
void				many_arguments(t_stack **stack_a, char **argv, int argc);
void				pb(t_stack **head_a, t_stack **head_b);
void				rr(t_stack **head_a, t_stack **head_b);
void				rrr(t_stack **head_a, t_stack **head_b);
void				sort(t_stack *stack_a, t_stack *stack_b);
void				sort_max(t_stack **stack_b);
void				sort_h(t_stack **stack_a, t_stack **stack_b);
void				rotate_a_and_b(t_stack **stack_a, t_stack **stack_b,
						t_stack *cheap);
void				reverse_rotate_a_and_b(t_stack **stack_a, t_stack **stack_b,
						t_stack *cheapest);
void				put_node_on_top_a(t_stack **stack_a, t_stack *cheapest);
void				put_node_on_top_b(t_stack **stack_b, t_stack *cheapest);
void				free_and_exit_1(t_input *input, int *data,
						t_stack **stack_a);
void				free_and_exit_if_sorted(int *data, t_stack **stack_a);
#endif
