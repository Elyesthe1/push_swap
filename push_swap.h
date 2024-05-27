/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahal <erahal@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 01:52:32 by erahal            #+#    #+#             */
/*   Updated: 2024/05/27 17:00:52 by erahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				nb;
	int				index;
	int				prix;
	struct s_stack	*target;
	struct s_stack	*next;
}					t_stack;

int					ft_strlen(char *s);

void				ft_config_index(t_stack *lst);

void				ft_config_target_a(t_stack *first, t_stack *second);

void				ft_push(t_stack **first, t_stack **second);

void				ft_push_back(t_stack **first, t_stack **second);

void				min(t_stack **first);

void				ft_config_lst(t_stack **first, t_stack **second, int a);

void				ft_config_target_b(t_stack *second, t_stack *first);

void				ft_error(t_stack **lst, char **tab);

char				**ft_split(char *str, char c);

void				ft_free(char **s);

void				ft_check_doublon(t_stack *lst, int n, char **tab);

int					ft_atoi(char *s1, t_stack **lst, char **tab);

int					ft_nbmot(char *str, char c);

char				*ft_strchr(char *str, int c);

char				*ft_substr(char *s, unsigned int start, int len);

void				ft_lstadd_back(t_stack **lst, t_stack *new);

t_stack				*ft_lstnew(int n);

t_stack				*ft_lstlast(t_stack *lst);

t_stack				*swap_a(t_stack *lst, int a);

t_stack				*stack_a(char **arg);

void				push_a(t_stack **first, t_stack **second);

void				ft_lstadd_front(t_stack **lst, t_stack *new);

t_stack				*swap_b(t_stack *lst, int a);

void				push_b(t_stack **second, t_stack **first);

void				rotate_a(t_stack **first, int a);

void				rotate_b(t_stack **second, int a);

int					ft_lstsize(t_stack *lst);

void				ft_lstfree(t_stack **lst);

void				swap_all(t_stack **first, t_stack **second);

void				ft_rotate_all(t_stack **first, t_stack **second);

void				reverse_rotate_b(t_stack **second, int a);

void				reverse_rotate_a(t_stack **first, int a);

void				reverse_rotate_all(t_stack **first, t_stack **second);

void				ft_sort_trois(t_stack **first);

int					ft_alreadysort(t_stack *first);

void				ft_sort(t_stack **first, t_stack **second);

t_stack				*biggeststack(t_stack *lst);

void				ft_prix(t_stack *first);

t_stack				*reduc(t_stack *lst);

void				ft_config_target_b(t_stack *second, t_stack *first);

t_stack				*loweststack(t_stack *lst);

int					ft_abs(int n);

#endif
