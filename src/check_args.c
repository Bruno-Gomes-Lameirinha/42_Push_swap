/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomes-l <bgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:30:13 by bgomes-l          #+#    #+#             */
/*   Updated: 2024/06/10 19:08:48 by bgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_is_num(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_num_is_repeated(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

void	ft_check_push_args(char **args, t_stack_info *info_a)
{
	int		j;
	long	tmp;

	j = 0;
	while (args[j])
	{
		tmp = ft_atoi(args[j]);
		if (!ft_is_num(args[j]) || ft_num_is_repeated(tmp, args, j))
		{
			ft_free_args(args, ft_count_args(args));
			ft_free_memory_a(info_a);
			ft_error("Error");
		}
		if (tmp < -2147483648 || tmp > 2147483647)
		{
			ft_free_args(args, ft_count_args(args));
			ft_free_memory_a(info_a);
			ft_error("Error");
		}
		j++;
	}
}

int	ft_count_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}
