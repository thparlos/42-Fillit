/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readtotab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 11:10:03 by tpacaud           #+#    #+#             */
/*   Updated: 2019/01/18 16:27:53 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

int		ft_touch(char **tab, int i, int y)
{
	int touch;

	touch = 0;
	if (i != 3 && i % 5 != 3 && tab[i + 1][y] == '#')
		touch++;
	if (i != 0 && i % 5 != 0 && tab[i - 1][y] == '#')
		touch++;
	if (y != 3 && tab[i][y + 1] == '#')
		touch++;
	if (y != 0 && tab[i][y - 1] == '#')
		touch++;
	return (touch);
}

int		ft_iserror(int i, int *count, int *touch)
{
	if (*count != 4)
		return (0);
	if (i % 5 != 4)
		return (0);
	if (*touch < 6)
		return (0);
	*count = 0;
	*touch = 0;
	return (1);
}

int		ft_isnormed(char **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tab[i] != NULL)
	{
		if (i % 5 == 4 && tab[i] == 0)
			return (0);
		i++;
	}
	if (tab[i] == NULL && tab[i - 1] == 0)
		return (0);
	if (tab[i] == NULL && i % 5 != 4)
		return (0);
	return (1);
}

int		ft_annexhc(char **tab, int i, int *y)
{
	if (*y != 4 && tab[i][*y] == 0)
		return (-1);
	if (tab[i][*y] == 0)
	{
		i++;
		*y = 0;
	}
	return (i);
}

int		ft_headcheck(char **tab, int i, int y, int count_touch[2])
{
	if (ft_isnormed(tab) == 0)
		return (0);
	while (tab[i] != NULL)
	{
		if (ft_strcmp(tab[i], "$l") == 0)
			if (ft_iserror(i++, &count_touch[0], &count_touch[1]) == 0)
				return (0);
		if (tab[i][y] != '.' && tab[i][y] != '#' && tab[i][y] != 0)
			return (0);
		while (tab[i][y] == '.' && tab[i][y])
			y++;
		if (tab[i][y] == '#')
		{
			if ((count_touch[1] += ft_touch(tab, i, y++)) == 0)
				return (0);
			count_touch[0] += 1;
		}
		if ((i = ft_annexhc(tab, i, &y)) == -1)
			return (0);
	}
	if (tab[i] == NULL)
		if (ft_iserror(i++, &count_touch[0], &count_touch[1]) == 0)
			return (0);
	return (1);
}
