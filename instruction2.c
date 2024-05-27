/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahal <erahal@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:41:41 by erahal            #+#    #+#             */
/*   Updated: 2024/05/27 16:00:28 by erahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack **first, int a)
{
	int		nombre;
	t_stack	*temp;

	if (!(*first))
		return ;
	nombre = (*first)->nb;
	temp = (*first)->next;
	free(*first);
	(*first) = temp;
	ft_lstadd_back(first, ft_lstnew(nombre));
	if (a == 0)
		write(1, "ra\n", 3);
}

void	rotate_b(t_stack **second, int a)
{
	int		nombre;
	t_stack	*temp;

	if (!(*second))
		return ;
	nombre = (*second)->nb;
	temp = (*second)->next;
	free(*second);
	(*second) = temp;
	ft_lstadd_back(second, ft_lstnew(nombre));
	if (a == 0)
		write(1, "rb\n", 3);
}

void	ft_rotate_all(t_stack **first, t_stack **second)
{
	rotate_a(first, 1);
	rotate_b(second, 1);
	write(1, "rr\n", 3);
}

void	reverse_rotate_a(t_stack **first, int a)
{
	t_stack	*temp;
	t_stack	*tmp;
	int		len;
	int		i;

	if (!(*first))
		return ;
	i = 0;
	temp = (*first);
	len = ft_lstsize(*first);
	while (i < len - 2)
	{
		i++;
		(*first) = (*first)->next;
	}
	tmp = (*first)->next;
	(*first)->next = NULL;
	tmp->next = temp;
	(*first) = tmp;
	if (a == 0)
		write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack **second, int a)
{
	int		nb;
	t_stack	*temp;
	t_stack	*tmp;
	int		len;
	int		i;

	if (!(*second))
		return ;
	i = 0;
	temp = (*second);
	len = ft_lstsize(*second);
	while (i < len - 2)
	{
		i++;
		(*second) = (*second)->next;
	}
	tmp = (*second)->next;
	(*second)->next = NULL;
	nb = tmp->nb;
	free(tmp);
	(*second) = temp;
	ft_lstadd_front(second, ft_lstnew(nb));
	if (a == 0)
		write(1, "rrb\n", 4);
}
