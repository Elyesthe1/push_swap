/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahal <erahal@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 01:53:23 by erahal            #+#    #+#             */
/*   Updated: 2024/05/27 16:57:26 by erahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*second;
	t_stack	*first;

	if ((ac < 2) || (ac >= 2 && ft_strlen(av[1]) == 0))
		return (1);
	first = NULL;
	second = NULL;
	first = stack_a(av);
	if (ft_alreadysort(first) != 0)
	{
		if (ft_lstsize(first) == 2)
			swap_a(first, 0);
		else if (ft_lstsize(first) == 3)
			ft_sort_trois(&first);
		else
			ft_sort(&first, &second);
	}
	ft_lstfree(&first);
	ft_lstfree(&second);
	return (0);
}
