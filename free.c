/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 18:19:50 by wasmar            #+#    #+#             */
/*   Updated: 2024/09/07 20:17:24 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_2d_array(char **data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		free(data[i]);
		i++;
	}
	free(data);
}

void	free_and_exit_1(t_input *input, int *data, t_stack **stack_a)
{
	free(input);
	free(data);
	free_linked_list(*stack_a);
	exit(0);
}

void free_and_exit_if_sorted(int *data,t_stack **stack_a)
{
   		free(data);
		free_linked_list(*stack_a);
		exit(0); 
}
