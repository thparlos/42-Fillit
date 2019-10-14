/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 22:02:30 by thparlos          #+#    #+#             */
/*   Updated: 2019/01/18 16:48:37 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

int		ft_insert_tetra(char **final_tab, char **tetra, int i_tab, int j_tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tetra[i] != 0)
	{
		while (tetra[i][j] != 0)
		{
			if (tetra[i][j] != '.')
				final_tab[i_tab + i][j_tab + j] = tetra[i][j];
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

void	ft_remove_tetra(char **final_tab, char **tetra, int i_tab, int j_tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tetra[i] != 0)
	{
		while (tetra[i][j] != 0)
		{
			if (tetra[i][j] != '.')
				final_tab[i_tab + i][j_tab + j] = '.';
			j++;
		}
		i++;
		j = 0;
	}
}

int		ft_is_positionable(char **final_tab, char **tetra, int i_tab, int j_tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tetra[i])
	{
		while (tetra[i][j])
		{
			if (final_tab[i + i_tab] == 0)
				return (0);
			if (final_tab[i_tab + i][j_tab + j] == 0)
				return (0);
			if (tetra[i][j] != '.' && final_tab[i_tab + i][j_tab + j] != '.')
				return (0);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

int		ft_fillit_solver(char **final_tab, char ***all_tetra, int k)
{
	int i_tab;
	int j_tab;

	i_tab = 0;
	j_tab = 0;
	if (all_tetra[k] == NULL)
		return (0);
	while (final_tab[i_tab] != 0)
	{
		while (final_tab[i_tab][j_tab] != 0)
		{
			if (ft_is_positionable(final_tab, all_tetra[k], i_tab, j_tab) == 1)
			{
				ft_insert_tetra(final_tab, all_tetra[k], i_tab, j_tab);
				if (ft_fillit_solver(final_tab, all_tetra, (k + 1)) == 0)
					return (0);
				ft_remove_tetra(final_tab, all_tetra[k], i_tab, j_tab);
			}
			j_tab++;
		}
		i_tab++;
		j_tab = 0;
	}
	return (1);
}

int		ft_resolution(char ***all_tetra)
{
	int		square_size;
	char	**final_table;

	square_size = ft_square_size(ft_nbr_tetri(all_tetra));
	if (!(final_table = ft_square_generation(square_size, square_size, '.', 0)))
		return (-1);
	while (ft_fillit_solver(final_table, all_tetra, 0))
	{
		square_size++;
		ft_freemap(final_table);
		if (!(final_table = \
					ft_square_generation(square_size, square_size, '.', 0)))
			return (-1);
	}
	ft_printtab(final_table);
	ft_freemap(final_table);
	return (0);
}
