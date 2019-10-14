/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 18:18:38 by thparlos          #+#    #+#             */
/*   Updated: 2019/01/18 16:37:18 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

int		ft_norme(char ***cube, int firstc, int k)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (cube[k][i])
	{
		while (cube[k][i][j])
		{
			if (cube[k][i][j] == 'A' + k)
			{
				cube[k][i][j - firstc] = cube[k][i][j];
				cube[k][i][j] = '.';
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (j);
}

int		ft_howmanytetri(char **tab)
{
	int i;
	int count;

	i = 0;
	count = 1;
	while (tab[i])
	{
		if (ft_strcmp(tab[i], "$l") == 0)
			count++;
		i++;
	}
	return (count + 1);
}
