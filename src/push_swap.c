/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomes-l <bgomes-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:34:16 by bgomes-l          #+#    #+#             */
/*   Updated: 2024/05/07 20:19:25 by bgomes-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	string_to_number(char *argument)
{
	ft_printf("pegar a lista dividi-la por espaço e transformar para int o char");
	ft_printf("\n%s", argument);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		exit(0);
	else if (argc == 2)
		string_to_number(argv[1]);
	else
		ft_printf("A lista é dividida");
}
