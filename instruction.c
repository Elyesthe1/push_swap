/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahal <erahal@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:41:37 by erahal            #+#    #+#             */
/*   Updated: 2024/05/27 15:23:45 by erahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*swap_a(t_stack *lst, int a)
{
	t_stack	*temp;
	int		tmp;

	temp = lst;
	if (!lst->next)
		return (NULL);
	lst = lst->next;
	tmp = lst->nb;
	lst->nb = temp->nb;
	lst = temp;
	lst->nb = tmp;
	if (a == 0)
		write(1, "sa\n", 3);
	return (lst);
}

t_stack	*swap_b(t_stack *lst, int a)
{
	t_stack	*lsttemp;
	int		tmp;

	if (!lst)
		return (NULL);
	lsttemp = lst;
	if (lst->next == NULL)
		return (NULL);
	lst = lst->next;
	tmp = lst->nb;
	lst->nb = lsttemp->nb;
	lsttemp->nb = tmp;
	if (a == 0)
		write(1, "sb\n", 3);
	return (lst);
}

void	swap_all(t_stack **first, t_stack **second)
{
	swap_a(*first, 1);
	swap_b(*second, 1);
	write(1, "ss\n", 3);
}

void	push_a(t_stack **first, t_stack **second)
{
	t_stack	*temp;

	if (!(*second))
		return ;
	ft_lstadd_front(first, ft_lstnew((*second)->nb));
	temp = (*second)->next;
	free(*second);
	(*second) = temp;
	write(1, "pa\n", 3);
}

void	push_b(t_stack **second, t_stack **first)
{
	t_stack	*temp;

	if (!(*first))
		return ;
	ft_lstadd_front(second, ft_lstnew((*first)->nb));
	temp = (*first)->next;
	free(*first);
	(*first) = temp;
	write(1, "pb\n", 3);
}
