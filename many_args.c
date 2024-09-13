/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   many_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 18:52:30 by wasmar            #+#    #+#             */
/*   Updated: 2024/09/13 10:44:39 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	many_args_error(int *data, bool error)
{
	if (error == false)
	{
		free(data);
		write(2, "Error3", 6);
		exit(0);
	}
}

void	many_arguments(t_stack **stack_a, char **argv, int argc)
{
	bool	error2;
	bool	error1;
	int		*data;

	data = malloc((argc - 1) * sizeof(int));
	many_args_error(data, create_array_with_input(argv, argc, &data));
	many_args_error(data, check_numeric(argv, 1));
	(*stack_a) = create_list_a(data, argc, 1);
	error2 = true;
	error2 = check_if_sorted(*stack_a);
	if (error2 == false)
		free_and_exit_if_sorted(data, stack_a);
	error1 = check_dup(*stack_a);
	if (error1 == false)
	{
		free(data);
		free_linked_list(*stack_a);
		write(2, "Error2", 6);
		exit(0);
	}
	free(data);
}
