/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahal <erahal@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:41:46 by erahal            #+#    #+#             */
/*   Updated: 2024/05/27 17:10:15 by erahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_all(t_stack **first, t_stack **second)
{
	reverse_rotate_a(first, 1);
	reverse_rotate_b(second, 1);
	write(1, "rrr\n", 4);
}

int	ft_lstsize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ft_lstfree(t_stack **lst)
{
	t_stack	*temp;

	while ((*lst) != NULL)
	{
		temp = (*lst)->next;
		free(*lst);
		(*lst) = temp;
	}
}
