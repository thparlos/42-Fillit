/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filltotab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 18:10:25 by tpacaud           #+#    #+#             */
/*   Updated: 2019/02/01 12:06:09 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

char	**ft_problem(char *temp)
{
	free(temp);
	return (NULL);
}

char	**ft_filltotab(int fd)
{
	char	buf[546];
	char	*temp;
	char	**tab;
	int		i;

	if (read(fd, buf, 0) < 0)
		return (NULL);
	i = 0;
	tab = NULL;
	ft_bzero(buf, 546);
	if (read(fd, buf, 546) < 0)
		return (NULL);
	if ((temp = ft_strdup(buf)) == NULL)
		return (NULL);
	if (read(fd, buf, 546) > 0)
		return (ft_problem(temp));
	if (!(tab = ft_strsplit(temp, '\n', 0, 0)))
		return (NULL);
	free(temp);
	return (tab);
}
