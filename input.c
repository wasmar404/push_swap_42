/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:24:42 by wasmar            #+#    #+#             */
/*   Updated: 2024/09/07 19:09:52 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bool	create_array_with_input(char **input, int count, int **data)
{
	int	i;
	int	j;
	int	ftatoi;
	int	error;

	i = 0;
	j = 1;
	while (i < count - 1)
	{
		error = ft_atoi(input[j], &ftatoi);
		if (error == 0)
		{
			return (false);
		}
		(*data)[i] = ftatoi;
		i++;
		j++;
	}
	return (true);
}
