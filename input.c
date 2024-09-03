/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:24:42 by wasmar            #+#    #+#             */
/*   Updated: 2024/09/03 14:17:12 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bool create_array_with_input(char **input,int count,int **data)
{
    int i = 0;
    int j = 1;
    int ftatoi;
    int error;
    
    while (i < count -1)
    {
        error = ft_atoi(input[j],&ftatoi);
            if(error == 0)
            {
                return (false);
            }
        (*data)[i] = ftatoi;
        i++;
        j++;
    }
    return (true);
}