/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushlib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 01:43:39 by smayrand          #+#    #+#             */
/*   Updated: 2022/09/20 15:33:11 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHLIB_H
# define PUSHLIB_H

# include "./printf/libftprintf.h"
# include "./libft/libft.h"
# include <stdio.h>

# define SA 2
# define SB 3
# define BS 4

typedef struct s_stack
{
	int		*a;
	int		*b;
	int		i;
	int		chunk;
	int		chunkadd;
	int		nxtnb;
	int		blast;
	int		splitsize;
	char	*split;
	int		moves;
}	t_stack;

int			ft_nxtnb(int *stack, int nb, int chunk);
int			ft_residual(int *stack, int nb, int chunk);
int			ft_get_index(int *stack, int nb);
int			ft_stacksize(int *stack);
long int	ft_atoli(char *str);
void		ft_error(char *msg);
void		ft_doubles(char **arg);
void		ft_is_digital(char **arg);
void		ft_max_int(char **arg);
void		ft_errors_check(char **argv);
void		ft_sort_swap(t_stack *stack, int move);
void		*ft_stack_init(int argc, char **argv, t_stack *stack);
void		ft_print_stack(t_stack *stack);
void		ft_print_stack(t_stack *stack);
void		ft_sort(int argc, t_stack *stack);
void		ft_rotate(int *stack);
void		ft_rev_rotate(int *stack);
void		ft_sort_rotate(t_stack *stack, int move);
void		ft_sort_rev_rotate(t_stack *stack, int move);
void		ft_swap(int *x, int *y);
void		ft_sort_swap(t_stack *stack, int move);
void		ft_add(int *dest, int src);
void		ft_rm(int *stack);
void		ft_push(t_stack *stack, int move);
void		ft_3num(t_stack *stack);
void		ft_5num(t_stack *stack, int nb);
void		ft_lrg_atob(t_stack *stack, int nb);
void		ft_lrg_btoa(t_stack *stack);

#endif