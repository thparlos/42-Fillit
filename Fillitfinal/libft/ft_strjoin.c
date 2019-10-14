/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:25:49 by tpacaud           #+#    #+#             */
/*   Updated: 2018/11/22 09:54:55 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		y;
	int		sizemalloc;
	char	*str;

	i = 0;
	y = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	sizemalloc = ((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!(str = (char*)malloc(sizeof(char) * sizemalloc)))
		return (NULL);
	while (s1[i])
		str[y++] = s1[i++];
	i = 0;
	while (s2[i])
		str[y++] = s2[i++];
	str[y] = 0;
	return (str);
}
