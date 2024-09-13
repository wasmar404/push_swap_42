/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:04:33 by wasmar            #+#    #+#             */
/*   Updated: 2024/09/13 13:05:18 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	set_pos_and_median_if_even(t_stack *head, int list_size)
{
	int	i;

	i = 1;
	while (head != NULL)
	{
		head->position = i;
		if (i <= list_size / 2)
			head->median = 1;
		else
			head->median = 0;
		head = head->next;
		i++;
	}
}

void	set_pos_and_median(t_stack *head)
{
	int	i;
	int	list_size;

	i = 1;
	list_size = count_list(head);
	if (list_size % 2 != 0)
	{
		while (head != NULL)
		{
			head->position = i;
			if (i <= list_size / 2 + 1)
				head->median = 1;
			else
				head->median = 0;
			head = head->next;
			i++;
		}
	}
	else
		set_pos_and_median_if_even(head, list_size);
}

t_stack	*find_max_pointer(t_stack *head)
{
	t_stack	*max;

	max = head;
	while (head != NULL)
	{
		if (max->number < head->number)
			max = head;
		head = head->next;
	}
	return (max);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	if (argc != 1)
	{
		if (argc == 2)
			one_argument(argv[1], &stack_a);
		else if (argc > 2)
			many_arguments(&stack_a, argv, argc);
		main_sort(&stack_a, &stack_b);
	}
	else
	{
		exit(0);
	}
}

void	main_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (count_list(*stack_a) == 2)
	{
		sort_2(stack_a);
		free_linked_list(*stack_a);
		free_linked_list(*stack_b);
	}
	else if (count_list(*stack_a) == 3)
	{
		sort_3_nodes(stack_a);
		free_linked_list(*stack_a);
		free_linked_list(*stack_b);
	}
	else if (count_list(*stack_a) == 4)
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
