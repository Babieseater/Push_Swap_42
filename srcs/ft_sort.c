/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 22:05:43 by smayrand          #+#    #+#             */
/*   Updated: 2022/09/20 16:19:24 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushlib.h"

void	ft_sort(int args, t_stack *stack)
{
	if (args < 4)
		ft_sort_swap(stack, SA);
	else if (args < 5)
		ft_3num(stack);
	else if (args < 7)
		ft_5num(stack, args);
	else
	{
		ft_lrg_atob(stack, args);
		ft_lrg_btoa(stack);
	}
}

void	ft_3num(t_stack *stack)
{
	if (stack->a[0] > stack->a[1] && stack->a[0] > stack->a[2])
		ft_sort_rotate(stack, SA);
	if (stack->a[0] < stack->a[1] && stack->a[0] < stack->a[2]
		&& stack->a[1] > stack->a[2])
		ft_sort_rev_rotate(stack, SA);
	if (stack->a[0] > stack->a[1] && stack->a[0] < stack->a[2])
		ft_sort_swap(stack, SA);
	else if (stack->a[0] < stack->a[1] && stack->a[0] > stack->a[2])
		ft_sort_rev_rotate(stack, SA);
	else if (stack->a[0] > stack->a[1] && stack->a[0] > stack->a[2])
		ft_sort_rotate(stack, SA);
}

void	ft_5num(t_stack *stack, int nb)
{
	int	size;

	size = nb - 3;
	while (stack->a[3] != 0)
	{
		if (stack->a[0] <= size)
			ft_push(stack, SB);
		else
		{
			if (stack->a[ft_stacksize(stack->a) - 1] < size)
				ft_sort_rev_rotate(stack, SA);
			else
				ft_sort_rotate(stack, SA);
		}
	}
	ft_3num(stack);
	if (stack->b[0] < stack->b[1])
		ft_sort_swap(stack, SB);
	ft_push(stack, SA);
	if (stack->b[0] != 0)
		ft_push(stack, SA);
}

void	ft_lrg_atob(t_stack *stack, int nb)
{
	while (stack->a[0] != 0)
	{
		stack->nxtnb = ft_nxtnb(stack->a, nb, stack->chunk);
		stack->i = ft_get_index(stack->a, stack->nxtnb);
		while (stack->a[0] != stack->nxtnb)
		{
			if (stack->i < ft_stacksize(stack->a) / 2)
				ft_sort_rotate(stack, SA);
			else
				ft_sort_rev_rotate(stack, SA);
		}
		ft_push(stack, SB);
		if (stack->b[0] < nb / 2 && ft_stacksize(stack->b) != 1)
			ft_sort_rotate(stack, SB);
		if (ft_residual(stack->a, nb, stack->chunk) == 1)
			stack->chunk += stack->chunkadd;
	}
	stack->blast = 0;
	stack->nxtnb = nb - 1;
}

void	ft_lrg_btoa(t_stack *stack)
{
	while (stack->b[0] != 0)
	{
		stack->i = ft_get_index(stack->b, stack->nxtnb);
		while (stack->b[0] != stack->nxtnb)
		{
			if (stack->b[0] == stack->nxtnb - 1)
			{
				ft_push(stack, SA);
				stack->blast = 1;
			}
			else if (stack->i < ft_stacksize(stack->b) / 2)
				ft_sort_rotate(stack, SB);
			else
				ft_sort_rev_rotate(stack, SB);
		}
		ft_push(stack, SA);
		if (stack->blast == 1)
		{
			stack->nxtnb -= 2;
			stack->blast = 0;
			ft_sort_swap(stack, SA);
		}
		else
			stack->nxtnb--;
	}
}
