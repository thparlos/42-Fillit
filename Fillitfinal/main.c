/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 18:11:20 by tpacaud           #+#    #+#             */
/*   Updated: 2019/02/01 12:06:58 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

int		ft_printerror(void)
{
	ft_putendl("error");
	return (0);
}

int		ft_errors(char **tab)
{
	int count_touch[2];

	count_touch[0] = 0;
	count_touch[1] = 0;
	if (ft_headcheck(tab, 0, 0, count_touch) == 0)
	{
		ft_freemap(tab);
		return (ft_printerror());
	}
	return (1);
}

int		ft_usage(int ac)
{
	if (ac != 2)
	{
		ft_putendl("usage: ./fillit source_file_tetri");
		return (0);
	}
	return (1);
}

int		main(int ac, char **av)
{
	char	**tab;
	char	***tetri;
	int		fd;
	int		k;

	k = 0;
	if (ft_usage(ac) == 0)
		return (0);
	fd = open(av[1], O_RDONLY);
	if (!(tab = ft_filltotab(fd)))
		return (ft_printerror());
	if (ft_errors(tab) == 0)
		return (0);
	if (!(tetri = ft_maptocube(tab, 0, 0)))
		return (ft_printerror());
	if ((ft_resolution(tetri)) == -1)
		return (ft_printerror());
	ft_free_cube(tetri);
	ft_freemap(tab);
	return (0);
}
