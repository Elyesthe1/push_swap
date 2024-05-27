/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahal <erahal@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:42:02 by erahal            #+#    #+#             */
/*   Updated: 2024/05/27 16:43:18 by erahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_trois(t_stack **first)
{
	t_stack	*big;

	big = biggeststack(*first);
	if ((*first) == big)
		rotate_a(first, 0);
	else if ((*first)->next == big)
		reverse_rotate_a(first, 0);
	if (ft_alreadysort(*first) == 2)
		swap_a(*first, 0);
}

void	ft_config_index(t_stack *lst)
{
	long	mid;
	int		i;
	int		negative;

	i = 0;
	mid = (ft_lstsize(lst) / 2);
	while (lst)
	{
		if (i <= mid)
			lst->index = i++;
		else
		{
			negative = -ft_lstsize(lst);
			lst->index = negative++;
		}
		lst = lst->next;
	}
}

void	ft_config_target_a(t_stack *first, t_stack *second)
{
	t_stack	*target;
	t_stack	*temp;
	long	min;

	temp = second;
	while (first)
	{
		min = LONG_MIN;
		target = NULL;
		while (second)
		{
			if (first->nb > second->nb && second->nb > min)
			{
				target = second;
				min = second->nb;
			}
			second = second->next;
		}
		second = temp;
		if (min == LONG_MIN)
			first->target = biggeststack(second);
		else
			first->target = target;
		first = first->next;
	}
}

void	ft_config_target_b(t_stack *second, t_stack *first)
{
	t_stack	*target;
	t_stack	*temp;
	long	min;

	temp = first;
	while (second)
	{
		min = LONG_MAX;
		target = NULL;
		while (first)
		{
			if (second->nb < first->nb && first->nb < min)
			{
				target = first;
				min = first->nb;
			}
			first = first->next;
		}
		first = temp;
		if (min == LONG_MAX)
			second->target = loweststack(first);
		else
			second->target = target;
		second = second->next;
	}
}

void	ft_sort(t_stack **first, t_stack **second)
{
	int	count;

	count = ft_lstsize(*first);
	if (count-- > 3)
		push_b(second, first);
	if (count-- > 3)
		push_b(second, first);
	while (count-- > 3)
	{
		ft_config_lst(first, second, 0);
		ft_push(first, second);
	}
	ft_sort_trois(first);
	while (*second)
	{
		ft_config_lst(first, second, 1);
		ft_push_back(first, second);
	}
	ft_config_lst(first, second, 2);
	min(first);
}
