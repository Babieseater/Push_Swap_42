/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:51:24 by smayrand          #+#    #+#             */
/*   Updated: 2022/09/16 15:51:16 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushlib.h"

long int	ft_atoli(char *str)
{
	long int	i;
	long int	op;
	long int	res;

	i = 0;
	op = 1;
	res = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32 || str[i] == 43)
		i++;
	if (str[i] == 45)
	{
		op *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * op);
}

int	ft_nxtnb(int *stack, int nb, int chunk)
{
	int	i;
	int	ii;
	int	top;
	int	bot;

	i = 0;
	while ((stack[i] <= ((nb / 2) - chunk))
		|| stack[i] > ((nb / 2) + chunk))
		i++;
	top = stack[i];
	ii = ft_stacksize(stack) - 1;
	while (stack[ii] <= ((nb / 2) - chunk)
		|| stack[ii] >= ((nb / 2) + chunk))
		ii--;
	bot = stack[ii];
	if (nb - ii < i)
		return (bot);
	else
		return (top);
}

int	ft_get_index(int *stack, int nb)
{
	int	i;

	i = 0;
	while (stack[i])
	{
		if (stack[i] == nb)
			return (i);
		i++;
	}
	return (0);
}

int	ft_residual(int *stack, int nb, int chunk)
{
	int	i;

	i = 0;
	while (stack[i])
	{
		if (stack[i] > ((nb / 2) - chunk)
			&& stack[i] < ((nb / 2) + chunk))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
