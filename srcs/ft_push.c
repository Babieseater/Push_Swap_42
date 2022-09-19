/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 03:12:01 by smayrand          #+#    #+#             */
/*   Updated: 2022/09/13 22:27:29 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushlib.h"

void	ft_add(int *dest, int src)
{
	int	i;

	i = 0;
	while (dest[i] != 0)
		i++;
	while (i != 0)
	{
		dest[i] = dest[i - 1];
		i--;
	}
	dest[i] = src;
}

void	ft_rm(int *stack)
{
	int	i;

	i = 0;
	while (stack[i] != 0)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i] = 0;
}

void	ft_push(t_stack *stack, int move)
{
	if (move == SA)
	{
		ft_add(stack->a, stack->b[0]);
		ft_rm(&stack->b[0]);
		ft_printf("%s\n", "pa");
			ft_print_stack(stack);
	}
	else if (move == SB)
	{
		ft_add(stack->b, stack->a[0]);
		ft_rm(&stack->a[0]);
		ft_printf("%s\n", "pb");
			ft_print_stack(stack);
	}
}
