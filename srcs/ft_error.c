/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 12:16:21 by smayrand          #+#    #+#             */
/*   Updated: 2022/09/16 16:00:18 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushlib.h"

void	ft_error(char *msg)
{
	ft_printf("Error\n%s", msg);
	exit (0);
}

void	ft_doubles(char **arg)
{
	int	i;
	int	j;

	i = 0;
	while (arg[i] && arg[i] + 1)
	{
		j = (i + 1);
		while (arg[i] && arg[j])
		{
			if (ft_strncmp(arg[i], arg[j], ft_strlen(arg[j])) == 0
				&& ft_strncmp(arg[i], arg[j], ft_strlen(arg[i])) == 0)
				ft_error("Check doubles");
			j++;
		}
		i++;
	}
}

void	ft_is_digital(char **arg)
{
	int	i;
	int	j;

	i = 0;
	while (arg[i])
	{
		j = 0;
		while (arg[i][j])
		{
			if (arg[i][j] == '-')
				j++;
			if (!ft_isdigit(arg[i][j]))
				ft_error("Not all arguments are numbers");
			j++;
		}
		i++;
	}
}

void	ft_max_int(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (ft_atoli(arg[i]) > 2147483647 || ft_atoli(arg[i]) < -2147483648)
			ft_error("Int capacity exceeded");
		i++;
	}
}

void	ft_errors_check(char **argv)
{
	ft_doubles(argv + 1);
	ft_is_digital(argv + 1);
	ft_max_int(argv + 1);
}
