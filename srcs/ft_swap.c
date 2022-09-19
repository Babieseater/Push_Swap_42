/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 03:11:50 by smayrand          #+#    #+#             */
/*   Updated: 2022/09/13 22:26:18 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushlib.h"

void	ft_swap(int *x, int *y)
{
	int	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

void	ft_sort_swap(t_stack *stack, int move)
{
	if (move == SA)
	{
		ft_swap(&stack->a[0], &stack->a[1]);
		ft_printf("%s\n", "sa");
			ft_print_stack(stack);
	}
	else if (move == SB)
	{
		ft_swap(&stack->b[0], &stack->b[1]);
		ft_printf("%s\n", "sb");
			ft_print_stack(stack);
	}
	else if (move == BS)
	{
		ft_swap(&stack->a[0], &stack->a[1]);
		ft_swap(&stack->b[0], &stack->b[1]);
		ft_printf("%s\n", "ss");
			ft_print_stack(stack);
	}
}
