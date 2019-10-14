/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_annex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 22:31:05 by thparlos          #+#    #+#             */
/*   Updated: 2019/01/18 16:48:57 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

int		ft_sqrt(int nb)
{
	int i;

	i = 1;
	if (nb <= 0)
		return (0);
	while ((i * i) < nb)
		i++;
	if ((i * i) <= nb)
		return (i);
	else
		return (i);
}

int		ft_square_size(int nbrtetri)
{
	int i;

	i = ft_sqrt(nbrtetri * 4);
	return (i);
}

char	**ft_square_generation(int x, int y, char c, int i)
{
	int		j;
	char	**tab;

	j = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * (x + 1))))
	{
		free(tab);
		return (NULL);
	}
	while (i < y)
	{
		if (!(tab[i] = (char*)malloc(sizeof(char) * (x + 1))))
		{
			ft_freemap(tab);
			return (NULL);
		}
		while (j < y)
			tab[i][j++] = c;
		tab[i][j] = 0;
		j = 0;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

void	ft_free_final_table(char **final_table)
{
	int i;

	i = 0;
	while (final_table[i] != 0)
	{
		free(final_table[i]);
		i++;
	}
	free(final_table[i]);
}

int		ft_nbr_tetri(char ***all_tetra)
{
	int i;

	i = 0;
	while (all_tetra[i] != NULL)
		i++;
	return (i);
}
