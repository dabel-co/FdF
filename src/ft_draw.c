/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabel-co <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 12:56:03 by dabel-co          #+#    #+#             */
/*   Updated: 2021/10/11 13:21:06 by dabel-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	iso1(t_data *d)
{
	d->x1 = (d->x1 - d->y1) * cos(0.8) + 500;
	d->y1 = (d->x1 + d->y1) * sin (0.8) - 350 - d->z1;
}

void	iso2(t_data *d)
{
	d->x2 = (d->x2 - d->y2) * cos(0.8) + 500;
	d->y2 = (d->x2 + d->y2) * sin (0.8) - 350 - d->z2;
}

void	ft_bresenham(t_data *d, int z1, int z2)
{
	float	x_step;
	float	y_step;
	float	mod;
	float	l;
	float	k;

	d->z1 = z1;
	d->z2 = z2;
	iso1(d);
	iso2(d);
	x_step = d->x2 - d->x1;
	y_step = d->y2 - d->y1;
	mod = ft_max(x_step, y_step);
	x_step /= mod;
	y_step /= mod;
	l = ft_color_change(d);
	while ((int)(d->x1 - d->x2) || (int)(d->y1 - d->y2))
	{
		ft_put_pixel(d, (int)d->x1, (int)d->y1,
			((k - 0) / (l - 0) * (d->c1 - d->c2) + d->c2));
		d->x1 += x_step;
		d->y1 += y_step;
		k = ft_color_change(d);
	}	
}

void	ft_draw(t_data *d)
{
	int	x;
	int	y;

	y = 0;
	ft_check_z(d, 0, 0);
	while (y < d->l - 1)
	{
		x = 0;
		while (x < d->w - 1)
		{
			if (y == d->l - 2)
				ft_send_data_x(d, x, y, 1);
			ft_send_data(d, x, y);
			x++;
		}
		if (y < d->l - 1)
			ft_send_data_x(d, x, y, 0);
		y++;
	}
}

void	ft_check_z(t_data *d, int c, int z)
{
	int	x;
	int	y;

	y = 0;
	z = 1;
	c = 0;
	while (y < d->l)
	{
		x = 0;
		while (x < d->w)
		{
			if (d->matrix[y][x].z > 20 || d->matrix[y][x].color != 0xffffff)
				z = 0;
			if (d->matrix[y][x].color == 0xffffff)
				c++;
			if (d->matrix[y][x].color != 0xffffff)
				c = -15000;
			x++;
		}
		y++;
	}
	ft_change_z(d, c, z);
}
