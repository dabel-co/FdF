/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabel-co <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 10:22:50 by dabel-co          #+#    #+#             */
/*   Updated: 2021/10/09 17:37:54 by dabel-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_send_data(t_data *d, int x, int y)
{
	d->x1 = d->matrix[y][x].x;
	d->y1 = d->matrix[y][x].y;
	d->x2 = d->matrix[y][x].x;
	d->y2 = d->matrix[y + 1][x].y;
	d->c1 = d->matrix[y][x].color;
	d->c2 = d->matrix[y + 1][x].color;
	ft_bresenham(d, d->matrix[y][x].z, d->matrix[y + 1][x].z);
	d->x1 = d->matrix[y][x].x;
	d->y1 = d->matrix[y][x].y;
	d->x2 = d->matrix[y][x + 1].x;
	d->y2 = d->matrix[y][x].y;
	d->c1 = d->matrix[y][x].color;
	d->c2 = d->matrix[y][x + 1].color;
	ft_bresenham(d, d->matrix[y][x].z, d->matrix[y][x + 1].z);
}

void	ft_init_value(t_data *d)
{
	d->x = 0;
	d->a = 0;
}

int	ft_forward(char *x)
{
	if (x[0] == ' ' && x[1] == ' ')
		return (1);
	if (x[0] == ' ' && x[1] != ' ')
		return (0);
	if (x[0] == ',' || x[0] == '\n' || x[0] == '\0')
		return (0);
	return (1);
}

int	ft_max(float x_step, float y_step)
{
	int	result;
	int	aux;

	result = x_step;
	if (x_step < 0)
		result = x_step * -1;
	aux = y_step;
	if (y_step < 0)
		aux = y_step * -1;
	if (result > aux)
		aux = result;
	else
		result = aux;
	return (result);
}

int	ft_hex_position(char x)
{
	int		result;
	char	aux;

	result = 0;
	aux = '0';
	while (x != aux && aux <= '9')
	{
		result++;
		aux++;
	}
	if (x >= 97 && x <= 103)
		x = x - 32;
	aux = 'A';
	while (x != aux && aux <= 'G')
	{
		if (result <= 9)
			break ;
		result++;
		aux++;
	}
	return (result);
}
