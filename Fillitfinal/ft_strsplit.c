/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:24:20 by tpacaud           #+#    #+#             */
/*   Updated: 2019/02/01 11:57:17 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_countwords(const char *str, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count + 1);
}

static int	wordlen(const char *str, char c, int i)
{
	int count;

	count = 0;
	while (str[i] != c && str[i])
	{
		count++;
		i++;
	}
	return (count + 1);
}

static char	**ft_ifmallocerror(char **tab, int j)
{
	while (j)
		free(tab[j--]);
	free(tab);
	return (NULL);
}

char		**ft_fillendtab(char **tab, const char *s, int j, char c)
{
	int i;

	i = ft_strlen(s);
	if (s[i - 1] != c)
		tab[j] = 0;
	else
		tab[j - 1] = 0;
	return (tab);
}

char		**ft_strsplit(char const *s, char c, int i, int j)
{
	int		y;
	char	**tab;

	if (!(tab = (char**)malloc(sizeof(char*) * ft_countwords(s, c))))
		return (NULL);
	while (s[i])
	{
		y = 0;
		while (s[i] == c)
		{
			if (s[i - 1] == c && s[i] == c)
				tab[j++] = ft_strdup("$l");
			i++;
		}
		if (s[i] != 0)
			if (!(tab[j] = (char*)malloc(sizeof(char) * wordlen(s, c, i))))
				return (ft_ifmallocerror(tab, j));
		while (s[i] != c && s[i])
			tab[j][y++] = s[i++];
		if (y != 0)
			tab[j][y] = 0;
		j++;
	}
	return (ft_fillendtab(tab, s, j, c));
}
