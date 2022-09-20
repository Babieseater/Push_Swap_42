/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 01:44:14 by smayrand          #+#    #+#             */
/*   Updated: 2022/09/20 16:43:19 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushlib.h"

int	ft_check_sort(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] && argv[i + 1])
	{
		if (ft_atoi(argv[i]) > ft_atoi(argv[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

void	ft_print_stack(t_stack *stack)
{
	int	i;

	i = -1;
	printf("\033[0;32mSTACK A  \033[0;37m");
	while (stack->a[++i] != 0)
		printf("[\033[0;36m%03d\033[0;37m]", stack->a[i]);
	printf("\n");
	i = -1;
	printf("\033[0;33mSTACK B  \033[0;37m");
	while (stack->b[++i] != 0)
		printf("[\033[0;36m%03d\033[0;37m]", stack->b[i]);
	printf("\n");
	stack->moves++;
}

int	main(int argc, char **argv)
{
	t_stack	stack;
	int		sf;

	sf = 0;
	if (argc < 2)
		ft_error("Not enough arguments");
	if (ft_strchr(argv[1], 32) != NULL && argc == 2)
	{
		stack.split = ft_strjoin("push_swap ", argv[1]);
		argc = ft_splitsize(stack.split, 32);
		argv = ft_split(stack.split, 32);
		free (stack.split);
		sf = 3;
	}
	ft_errors_check(argv);
	if (ft_check_sort(argv) == 0)
		exit (0);
	ft_stack_init(argc, argv + 1, &stack);
	ft_print_stack(&stack);
	ft_sort(argc, &stack);
	if (sf == 3)
		ft_free_ptr(argv);
	free(stack.a);
	free(stack.b);
	return (0);
}
