/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:06:40 by smayrand          #+#    #+#             */
/*   Updated: 2022/09/15 13:59:08 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushlib.h"

void	ft_rotate(int *stack)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = stack[i];
	while (stack[i + 1])
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i] = tmp;
}

void	ft_sort_rotate(t_stack *stack, int move)
{
	if (move == SA)
	{
		ft_rotate(stack->a);
		ft_printf("%s\n", "ra");
			ft_print_stack(stack);
	}
	else if (move == SB)
	{
		ft_rotate(stack->b);
		ft_printf("%s\n", "rb");
			ft_print_stack(stack);
	}
	else if (move == BS)
	{
		ft_rotate(stack->a);
		ft_rotate(stack->b);
		ft_printf("%s\n", "rr");
			ft_print_stack(stack);
	}
}

void	ft_rev_rotate(int *stack)
{
	int	i;
	int	tmp;

	i = 0;
	while (stack[i + 1])
	{
		i++;
	}
	tmp = stack[i];
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[i] = tmp;
}

void	ft_sort_rev_rotate(t_stack *stack, int move)
{
	if (move == SA)
	{
		ft_rev_rotate(stack->a);
		ft_printf("%s\n", "rra");
			ft_print_stack(stack);
	}
	else if (move == SB)
	{
		ft_rev_rotate(stack->b);
		ft_printf("%s\n", "rrb");
			ft_print_stack(stack);
	}
	else if (move == BS)
	{
		ft_rev_rotate(stack->a);
		ft_rev_rotate(stack->b);
		ft_printf("%s\n", "rrr");
			ft_print_stack(stack);
	}
}
