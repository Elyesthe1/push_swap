/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahal <erahal@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:42:06 by erahal            #+#    #+#             */
/*   Updated: 2024/05/27 16:43:40 by erahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_alreadysort(t_stack *first)
{
	int	a;
	int	i;

	i = 1;
	while (first->next != NULL)
	{
		a = first->nb;
		first = first->next;
		i++;
		if (first->nb < a)
			return (i);
	}
	return (0);
}

t_stack	*biggeststack(t_stack *lst)
{
	long	litle;
	t_stack	*bigstack;

	litle = LONG_MIN;
	while (lst)
	{
		if (lst->nb > litle)
		{
			litle = lst->nb;
			bigstack = lst;
		}
		lst = lst->next;
	}
	return (bigstack);
}

t_stack	*loweststack(t_stack *lst)
{
	long	big;
	t_stack	*lowstack;

	big = LONG_MAX;
	while (lst)
	{
		if (lst->nb < big)
		{
			big = lst->nb;
			lowstack = lst;
		}
		lst = lst->next;
	}
	return (lowstack);
}

int	ft_abs(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

void	ft_config_lst(t_stack **first, t_stack **second, int a)
{
	ft_config_index(*first);
	ft_config_index(*second);
	ft_config_target_a(*first, *second);
	ft_config_target_b(*second, *first);
	if (a == 0)
		ft_prix(*first);
	else if (a == 1)
		ft_prix(*second);
}
