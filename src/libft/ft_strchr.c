/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabel-co <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 11:51:38 by dabel-co          #+#    #+#             */
/*   Updated: 2021/04/12 17:09:52 by dabel-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s1;
	size_t	x;

	s1 = (char *)s;
	x = ft_strlen(s);
	if (*s1 == (char)c)
		return (s1);
	while (*s1++ != '\0')
	{
		if (*s1 == (char)c)
			return (s1);
	}
	if ((char)c == '\0')
		return (s1);
	return (NULL);
}
