/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:17:09 by tpacaud           #+#    #+#             */
/*   Updated: 2019/02/01 11:29:37 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

# define BUFF_SIZE 4096

void	ft_bzero(void *s, size_t n);

char	*ft_strchr(const char *s, int c);

void	ft_putstr(char const *s);

char	*ft_strdup(const char *src);

size_t	ft_strlen(const char *str);

int		ft_strcmp(const char *s1, const char *s2);

void	ft_putchar(char c);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strcpy(char *dest, const char *src);

void	ft_putendl(char const *s);

int		ft_isascii(int c);

void	ft_bzero(void *s, size_t n);

#endif
