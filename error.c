/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 18:49:28 by wasmar            #+#    #+#             */
/*   Updated: 2024/09/07 19:07:51 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bool	check_if_sorted(t_stack *head)
{
	while (head->next != NULL)
	{
		if (head->number > head->next->number)
		{
			return (true);
		}
		head = head->next;
	}
	return (false);
}

bool	check_dup(t_stack *head)
{
	t_stack	*temp;

	while (head != NULL)
	{
		temp = head->next;
		while (temp != NULL)
		{
			if (temp->number == head->number)
			{
				return (false);
			}
			temp = temp->next;
		}
		head = head->next;
	}
	return (true);
}

bool	check_numeric(char **data, int flag)
{
	int	i ;
	int	j;

	i = 0;
	if (flag == 1)
	{
		i = 1;
	}
	while (data[i])
	{
		j = 0;
		while (data[i][j])
		{
			if (data[i][j] == '-' && j != 0)
				return (false);
			if ((data[i][j] < '0' || data[i][j] > '9') && data[i][j] != '-'
				&& data[i][j] != ' ')
			{
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}
