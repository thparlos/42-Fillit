/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_cube.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:03:26 by tpacaud           #+#    #+#             */
/*   Updated: 2019/02/01 12:02:27 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

void	ft_free_cube(char ***cube)
{
	int i;
	int y;
	int k;

	k = 0;
	i = 0;
	y = 0;
	while (cube[k])
	{
		while (cube[k][i] != NULL)
			free(cube[k][i++]);
		free(cube[k][i++]);
		free(cube[k]);
		k++;
		i = 0;
	}
	free(cube[k]);
	free(cube);
}

void	ft_freemap(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
