/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:57:25 by wasmar            #+#    #+#             */
/*   Updated: 2024/09/16 12:12:38 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	one_argument(char *argv, t_stack **stack_a)
{
	t_input	*input;
	int		*data;
	bool	error;
	int		i;

	error = true;
	check_space_and_null(argv);
	check_negative(argv);
	input = malloc(sizeof(t_input));
	error = split_argument(argv, &input, &data);
	if (error == false)
	{
		free(input);
		write(2, "Error\n", 5);
		exit(0);
	}
	(*stack_a) = create_list_a(data, input->input_count, 0);
	i = count_list(*stack_a);
	if (i == 1)
		free_and_exit_1(input, data, stack_a);
	one_argument_helper(&input, stack_a, check_dup(*stack_a), &data);
	one_argument_helper1(&input, stack_a, check_if_sorted(*stack_a), &data);
	free(data);
	free(input);
}

void	check_space_and_null(char *argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[i])
	{
		if (argv[i] != ' ')
		{
			j++;
		}
		i++;
	}
	if (j == 0)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
}

void	main_sort_h(t_stack **stack_a)
{
	if (count_list(*stack_a) == 2)
	{
		sort_2(stack_a);
	}
	else if (count_list(*stack_a) == 3)
	{
		sort_3_nodes(stack_a);
	}
}

void	main_sort(t_stack **stack_a, t_stack **stack_b)
{
	main_sort_h(stack_a);
	if (count_list(*stack_a) == 4)
	{
		sort_4_numbers(stack_a, stack_b);
		free_linked_list(*stack_a);
		free_linked_list(*stack_b);
	}
	else if (count_list(*stack_a) == 5)
	{
		sort_5_num(stack_a, stack_b);
		free_linked_list(*stack_a);
		free_linked_list(*stack_b);
	}
	else
		sort(*stack_a, *stack_b);
}
