/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_argument.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:54:10 by wasmar            #+#    #+#             */
/*   Updated: 2024/09/16 11:59:05 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bool	split_argument_helper(char *argv, char ***split)
{
	char	*charset;
	bool	errorr;

	charset = " \t\v";
	(*split) = ft_split(argv, charset);
	if (split == NULL)
		return (false);
	errorr = check_numeric(*split, 0);
	if (errorr == false)
	{
		free_2d_array(*split);
		return (false);
	}
	return (true);
}

int	count_input(char **data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		i++;
	}
	return (i);
}

bool	split_argument_helper_1(char **split, int **data)
{
	int	i;
	int	error;
	int	ftatoi;

	i = 0;
	error = 0;
	ftatoi = 0;
	while (split[i])
	{
		error = ft_atoi(split[i], &ftatoi);
		if (error == 0)
		{
			free_2d_array(split);
			free(*data);
			return (false);
		}
		(*data)[i] = ftatoi;
		i++;
	}
	return (true);
}

bool	split_argument(char *argv, t_input **input, int **data)
{
	char	**split;

	if (split_argument_helper(argv, &split) == false)
		return (false);
	*data = (int *)malloc(sizeof(int) * (count_input(split)));
	if (!data)
		return (NULL);
	if (!split_argument_helper_1(split, data))
		return (false);
	(*input)->input_count = count_input(split);
	free_2d_array(split);
	return (true);
}

void	check_negative(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == '-' && (argv[i + 1] < '0' || argv[i + 1] > '9'))
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		i++;
	}
}
