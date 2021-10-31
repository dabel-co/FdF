/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabel-co <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 11:19:34 by dabel-co          #+#    #+#             */
/*   Updated: 2021/09/13 16:10:09 by dabel-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define ERROR "Error\n"
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
int		ft_finishing(char *aux, char **line, int x, int i);
int		ft_analize(char *aux);
int		ft_strlena(const char *s);
char	*ft_strjoina(char *s1, char *s2);
#endif
