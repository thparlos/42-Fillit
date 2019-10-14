/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maptocube.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 16:00:51 by tpacaud           #+#    #+#             */
/*   Updated: 2019/01/28 20:34:40 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

void	ft_lefttetri(char ***cube, int i, int j, int k)
{
	int firstc;

	while (cube[k])
	{
		while (cube[k][i] && cube[k][i][j] && cube[k][i][j] == '.')
			i++;
		if (cube[k][i] == NULL)
		{
			i = 0;
			j++;
		}
		else if (cube[k][i] != NULL && j > 0)
		{
			firstc = j;
			j = ft_norme(cube, firstc, k);
			i = 0;
			k++;
		}
		else if (j == 0)
		{
			k++;
			i = 0;
		}
	}
}

void	ft_clrcoltetri(char ***cube, int i, int k, int j)
{
	while (cube[k])
	{
		j = 3;
		while (cube[k][i])
		{
			while (cube[k][i] != NULL && cube[k][i][j] == '.')
				i++;
			if (cube[k][i] == NULL)
			{
				j--;
				i = 0;
			}
			else
				break ;
		}
		if (j != 3)
		{
			i = 0;
			while (cube[k][i])
				cube[k][i++][j + 1] = 0;
		}
		k++;
		i = 0;
	}
}

char	*ft_replaceletter(char *str, int k)
{
	char	*replace;
	int		i;

	i = 0;
	if (!(replace = (char*)malloc(sizeof(char) * 5)))
		return (NULL);
	while (str[i])
	{
		if (str[i] == '#')
			replace[i] = 'A' + k;
		else
			replace[i] = str[i];
		i++;
	}
	replace[i] = '\0';
	return (replace);
}

char	***ft_filltocube(char **tab, int *l, char ***cube, int k)
{
	int i;
	int j;
	int y;

	i = *l;
	j = i;
	y = 0;
	while (tab[j] != NULL && ft_strcmp(tab[j], "$l") != 0
		&& ft_strcmp(tab[j], "....") != 0)
		j++;
	if (!(cube[k] = (char**)malloc(sizeof(char*) * (j - i + 2))))
		return (NULL);
	while (tab[i] != NULL && ft_strcmp(tab[i], "$l") != 0
		&& ft_strcmp(tab[i], "....") != 0)
	{
		cube[k][y] = ft_replaceletter(tab[i], k);
		i++;
		y++;
	}
	cube[k][y] = NULL;
	*l = i;
	return (cube);
}

char	***ft_maptocube(char **map, int i, int k)
{
	char	***cube;

	if (!(cube = (char***)malloc(sizeof(char**) * ft_howmanytetri(map))))
		return (NULL);
	while (map[i] != NULL)
	{
		while (ft_strcmp(map[i], "....") == 0 || ft_strcmp(map[i], "$l") == 0)
		{
			if (map[i + 1] == NULL)
			{
				i++;
				break ;
			}
			i++;
		}
		if (map[i] != NULL && !(cube = ft_filltocube(map, &i, cube, k)))
			return (NULL);
		k++;
	}
	cube[ft_howmanytetri(map) - 1] = NULL;
	ft_lefttetri(cube, 0, 0, 0);
	ft_clrcoltetri(cube, 0, 0, 3);
	return (cube);
}
