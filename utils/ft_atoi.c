/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:31:59 by wasmar            #+#    #+#             */
/*   Updated: 2024/09/03 22:43:55 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"
int	ft_atoi(char *nptr, int *ftatoi)
{
	int	i;
	int	sign;


	i = 0;
	sign = 1;
	int indi;
	long long result = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
	{
		i ++;
	}
	while(nptr[i] == '+' || nptr[i] == '-')
	{
	// if (nptr[i] == '+' || nptr[i] == '-')
	// {
		if (nptr[i] == '-')
			sign *= -1;
		indi++;
		if(indi >1 || nptr[i] == '+')
			return 0;
		i++;
	}
	while (nptr[i] != '\0' && (nptr[i] >= 48 && nptr[i] <= 57))
	{
		result = result * 10 + nptr[i] - '0';
		if(result  < -2147483648 || result > 2147483647 )
		{
			return (0);
		}
		
		i ++;
	}
	*ftatoi = (int)result*sign;
	return (1);
	
}
