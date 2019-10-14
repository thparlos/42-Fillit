/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:03:56 by tpacaud           #+#    #+#             */
/*   Updated: 2018/11/24 13:49:55 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*s1;

	i = ft_strlen(src) + 1;
	if (src == NULL)
		return (NULL);
	if (!(s1 = (char*)malloc(sizeof(char) * i)))
		return (NULL);
	return (ft_strcpy(s1, src));
}
