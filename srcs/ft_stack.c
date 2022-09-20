/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 14:11:27 by smayrand          #+#    #+#             */
/*   Updated: 2022/09/20 16:20:00 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushlib.h"

int	ft_stacksize(int *stack)
{
	int	size;

	size = 0;
	while (stack[size] != 0)
		size++;
	return (size);
}

int	ft_indexation(char **argv, char *nb)
{
	int	i;
	int	index;

	index = 1;
	i = 0;
	while (argv[i])
	{
		if (ft_atoi(nb) > ft_atoi(argv[i]))
			index++;
		i++;
	}
	return (index);
}

void	*ft_stack_init(int argc, char **argv, t_stack *stack)
{
	int	i;

	stack->a = ft_calloc(sizeof(int), argc);
	stack->b = ft_calloc(sizeof(int), argc);
	if (!stack->a || !stack->b)
	{
		free(stack->a);
		free(stack->b);
		ft_error("Can't malloc the stacks");
	}
	i = 0;
	while (argv[i])
	{
		stack->a[i] = ft_indexation(argv, argv[i]);
		i++;
	}
	if (argc > 250)
		stack->chunk = 33;
	else
		stack->chunk = 15;
	stack->chunkadd = stack->chunk;
	return (stack);
}
