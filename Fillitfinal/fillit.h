/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 17:51:20 by tpacaud           #+#    #+#             */
/*   Updated: 2019/02/01 11:30:00 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./libft/libft.h"

void	ft_freemap(char **tab);

char	**ft_filltotab(int fd);

int		ft_headcheck(char **tab, int i, int y, int count_touch[2]);

void	ft_free_cube(char ***cube);

int		ft_resolution(char ***all_tetra);

void	ft_printtab(char **map);

int		ft_sqrt(int nb);

int		ft_square_size(int nbrtetri);

char	**ft_square_generation(int x, int y, char c, int i);

void	ft_free_final_table(char **final_table);

int		ft_nbr_tetri(char ***all_tetra);

char	***ft_maptocube(char **map, int i, int k);

int		ft_howmanytetri(char **tab);

int		ft_norme(char ***cube, int firstc, int k);

char	**ft_strsplit(char const *s, char c, int i, int j);

#endif
