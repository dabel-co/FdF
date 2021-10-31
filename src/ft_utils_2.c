/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabel-co <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 12:33:58 by dabel-co          #+#    #+#             */
/*   Updated: 2021/10/11 13:21:08 by dabel-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

float	ft_color_change(t_data *d)
{
	float	x;

	x = (d->x1 - d->x2) * (d->x1 - d->x2);
	x = x + ((d->y1 - d->y2) * (d->y1 - d->y2));
	return (x);
}

void	ft_init_win(t_data *d)
{
	d->mlx = mlx_init();
	d->mlx_win = mlx_new_window(d->mlx, 1920, 1080, "FdF");
	d->img = mlx_new_image(d->mlx, 1920, 1080);
	d->addr = mlx_get_data_addr(d->img, &d->bits_per_pixel,
			&d->line_length, &d->endian);
	ft_draw(d);
	mlx_put_image_to_window(d->mlx, d->mlx_win, d->img, 0, 0);
	mlx_key_hook(d->mlx_win, ft_key_hook, &d);
	mlx_hook(d->mlx_win, 17, 0, ft_hooked_funtion, &d);
	ft_free(d);
	mlx_loop(d->mlx);
}

void	ft_send_data_x(t_data *d, int x, int y, int p)
{
	if (p == 0)
	{
		d->x1 = d->matrix[y][x].x;
		d->y1 = d->matrix[y][x].y;
		d->x2 = d->matrix[y][x].x;
		d->y2 = d->matrix[y + 1][x].y;
		d->c1 = d->matrix[y][x].color;
		d->c2 = d->matrix[y + 1][x].color;
		ft_bresenham(d, d->matrix[y][x].z, d->matrix[y + 1][x].z);
	}
	if (p == 1)
	{
		d->x1 = d->matrix[y][x].x;
		d->y1 = d->matrix[y + 1][x].y;
		d->x2 = d->matrix[y][x + 1].x;
		d->y2 = d->matrix[y + 1][x].y;
		d->c1 = d->matrix[y + 1][x].color;
		d->c2 = d->matrix[y + 1][x].color;
		ft_bresenham(d, d->matrix[y + 1][x].z, d->matrix[y + 1][x + 1].z);
	}
}

float	ft_get_x(t_data *d)
{
	int		max;
	float	x;

	max = 2000 / d->w;
	x = d->x * (max / 2) + 500;
	return (x);
}

float	ft_get_y(t_data *d)
{
	int	max;
	int	y;

	max = (2000 / d->l);
	y = d->y * (max / 2);
	return (y);
}
