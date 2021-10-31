/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabel-co <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:26:16 by dabel-co          #+#    #+#             */
/*   Updated: 2021/10/11 13:21:56 by dabel-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_change_z(t_data *d, int c, int z)
{
	int	x;
	int	y;

	y = 0;
	while (y < d->l - 1)
	{
		x = 0;
		while (x < d->w - 1)
		{
			if (z == 1)
				d->matrix[y][x].z = d->matrix[y][x].z * 5;
			if (c > 0 && d->matrix[y][x].z > 9)
				d->matrix[y][x].color = 0xff0000;
			x++;
		}
		y++;
	}
}

int	ft_free(t_data *d)
{
	int	x;

	x = 0;
	while (x < d->l)
	{
		free(d->matrix[x]);
		x++;
	}
	free(d->matrix);
	return (0);
}

int	ft_key_hook(int keycode)
{
	if (keycode == 53)
		exit (0);
	return (0);
}

int	ft_hooked_funtion(int keycode)
{
	keycode = 53;
	ft_key_hook(keycode);
	return (0);
}

void	ft_maperror(int s)
{
	if (s == 0)
		write(1, "error : no file or multiple files supplied\n", 43);
	if (s == 1)
		write(1, "Bad filename or permissions\n", 28);
	if (s == 2)
		write(1, "Error : map not properly formatted\n", 35);
	ft_key_hook(53);
}
