/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahal <erahal@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 07:43:20 by erahal            #+#    #+#             */
/*   Updated: 2024/05/26 21:29:45 by erahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char *s, unsigned int start, int len)
{
	int				i;
	unsigned int	j;
	char			*str;

	i = 0;
	j = 0;
	if (!s || (unsigned int)ft_strlen(s) < start)
		return (NULL);
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s[j])
	{
		if (i < len && j >= start)
		{
			str[i] = s[j];
			i++;
		}
		j++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == (char)c)
		return ((char *)&str[i]);
	else
		return (NULL);
}

int	ft_nbmot(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] != c && str[i])
			i++;
	}
	return (count);
}

char	**ft_split(char *str, char c)
{
	char	**tab;
	int		i;
	int		len;

	i = 0;
	tab = (char **)malloc(sizeof(char *) * (ft_nbmot(str, c) + 1));
	if (!tab || !str)
		return (NULL);
	while (*str)
	{
		while (*str == c && *str)
			str++;
		if (*str)
		{
			if (!ft_strchr(str, c))
				len = ft_strlen(str);
			else
				len = ft_strchr(str, c) - str;
			tab[i++] = ft_substr(str, 0, len);
			str = str + len;
		}
	}
	tab[i] = 0;
	return (tab);
}
