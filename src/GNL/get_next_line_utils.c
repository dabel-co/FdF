/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabel-co <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 11:19:05 by dabel-co          #+#    #+#             */
/*   Updated: 2021/09/14 17:39:07 by dabel-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlena(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoina(char *s1, char *s2)
{
	char	*x;
	int		i;
	int		a;

	if (!s1 || !s2)
		return (NULL);
	x = malloc(ft_strlena(s1) + ft_strlena(s2) + 1);
	if (!x)
		return (NULL);
	i = 0;
	a = 0;
	while (s1[i] != '\0')
		x[a++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		x[a++] = s2[i++];
	x[a] = '\0';
	free(s1);
	return (x);
}

int	ft_finishing(char *aux, char **line, int x, int i)
{
	char	split[BUFFER_SIZE + 1];

	while (aux[i] != '\n')
	{
		split[i] = aux[i];
		i++;
	}
	split[i] = '\0';
	*line = ft_strjoina(*line, split);
	i++;
	while (aux[i] != '\0')
	{
		aux[x] = aux[i];
		x++;
		i++;
	}
	aux[x] = '\0';
	return (1);
}

int	ft_analize(char *aux)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (aux[i] == '\n')
			return (1);
		if (aux[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}
