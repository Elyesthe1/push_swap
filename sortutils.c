/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahal <erahal@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:41:15 by erahal            #+#    #+#             */
/*   Updated: 2024/05/27 16:42:26 by erahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_prix(t_stack *first)
{
	while (first)
	{
		if ((first->index < 0 && first->target->index < 0) || (first->index > 0
				&& first->target->index > 0))
		{
			if (ft_abs(first->index) > ft_abs(first->target->index))
				first->prix = ft_abs(first->index);
			else
				first->prix = ft_abs(first->target->index);
		}
		else
			first->prix = ft_abs(first->index) + ft_abs(first->target->index);
		first = first->next;
	}
}

t_stack	*reduc(t_stack *lst)
{
	long	max;
	t_stack	*temp;
	t_stack	*cheap;

	temp = lst;
	max = LONG_MAX;
	while (lst)
	{
		if (lst->prix < max)
		{
			max = lst->prix;
			cheap = lst;
		}
		lst = lst->next;
	}
	return (cheap);
}

void	ft_push(t_stack **first, t_stack **second)
{
	t_stack	*cheap;
	int		i;

	i = 0;
	cheap = reduc(*first);
	while (i != 1)
	{
		ft_config_index(*first);
		ft_config_index(*second);
		if ((*first)->nb == cheap->nb && (*second)->nb == cheap->target->nb
			&& i++ == 0)
			push_b(second, first);
		else if (cheap->target->index > 0 && cheap->index > 0 && i == 0)
			ft_rotate_all(first, second);
		else if (cheap->target->index < 0 && cheap->index < 0 && i == 0)
			reverse_rotate_all(first, second);
		else if (cheap->index > 0 && i == 0)
			rotate_a(first, 0);
		else if (cheap->index < 0 && i == 0)
			reverse_rotate_a(first, 0);
		else if (cheap->target->index > 0 && i == 0)
			rotate_b(second, 0);
		else if (cheap->target->index < 0 && i == 0)
			reverse_rotate_b(second, 0);
	}
}

void	ft_push_back(t_stack **first, t_stack **second)
{
	t_stack	*cheap;
	int		i;

	i = 0;
	cheap = reduc(*second);
	while (i != 1)
	{
		ft_config_index(*first);
		ft_config_index(*second);
		if (cheap->target->index > 0 && cheap->index > 0)
			ft_rotate_all(first, second);
		else if (cheap->target->index < 0 && cheap->index < 0)
			reverse_rotate_all(first, second);
		else if (cheap->index > 0)
			rotate_b(second, 0);
		else if (cheap->index < 0)
			reverse_rotate_b(second, 0);
		else if (cheap->target->index > 0)
			rotate_a(first, 0);
		else if (cheap->target->index < 0)
			reverse_rotate_a(first, 0);
		if ((*first)->nb == cheap->target->nb && (*second)->nb == cheap->nb
			&& i++ == 0)
			push_a(first, second);
	}
}

void	min(t_stack **first)
{
	t_stack	*low;

	low = loweststack(*first);
	while ((*first) != low)
	{
		if (low->index < 0)
			reverse_rotate_a(first, 0);
		else
			rotate_a(first, 0);
	}
}
