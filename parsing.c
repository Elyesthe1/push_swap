/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahal <erahal@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:41:50 by erahal            #+#    #+#             */
/*   Updated: 2024/05/27 16:31:29 by erahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_doublon(t_stack *lst, int n, char **tab)
{
	while (lst)
	{
		if (lst->nb == n)
			ft_error(&lst, tab);
		lst = lst->next;
	}
}

int	ft_atoi(char *s1, t_stack **lst, char **tab)
{
	int		i;
	long	result;
	int		negative;

	i = 0;
	negative = 1;
	result = 0;
	if (s1[i] == '-')
	{
		negative = -negative;
		i++;
	}
	while (s1[i])
	{
		result = result * 10 + (s1[i] - '0');
		if (!((s1[i] >= '0' && s1[i] <= '9') || s1[i] == ' ' || s1[i] == '\0'))
			ft_error(lst, tab);
		i++;
	}
	if ((result * negative) > INT_MAX || (result * negative) < INT_MIN)
		ft_error(lst, tab);
	return (result * negative);
}

t_stack	*stack_a(char **arg)
{
	char	**tab;
	int		i;
	t_stack	*lst;
	int		j;

	i = 1;
	lst = NULL;
	j = 0;
	while (arg[i])
	{
		tab = ft_split(arg[i], ' ');
		j = 0;
		while (tab[j])
		{
			ft_check_doublon(lst, ft_atoi(tab[j], &lst, tab), tab);
			ft_lstadd_back(&lst, ft_lstnew(ft_atoi(tab[j], &lst, tab)));
			j++;
		}
		ft_free(tab);
		i++;
	}
	i = 0;
	return (lst);
}

void	ft_error(t_stack **lst, char **tab)
{
	t_stack	*temp;

	ft_free(tab);
	if (lst)
	{
		while ((*lst))
		{
			temp = (*lst)->next;
			free(*lst);
			(*lst) = temp;
		}
	}
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_free(char **s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	if (*s)
	{
		while (s[i])
		{
			free(s[i]);
			i++;
		}
		free(s);
	}
}
