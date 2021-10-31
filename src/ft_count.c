/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabel-co <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:54:36 by dabel-co          #+#    #+#             */
/*   Updated: 2021/10/09 20:18:41 by dabel-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int	ft_hex_to_decimal(char *line)
{
	int	result;

	result = ft_hex_position(line[0]);
	result = result * 16;
	result = result + ft_hex_position(line[1]);
	return (result);
}

int	ft_get_color(char *line, int r, int g, int b)
{
	if (line[0] == ' ' || line[0] == '\0')
		return (0xffffff);
	r = ft_hex_to_decimal(&line[3]);
	if (line[5] != ' ' && line[5] != '\n' && line[5] != '\0')
		g = ft_hex_to_decimal(&line[5]);
	else
		return (0 << 24 | r << 16 | 0 << 8 | 0);
	if (line[7] != ' ' && line[7] != '\n' && line[7] != '\0')
		b = ft_hex_to_decimal(&line[7]);
	return (0 << 24 | r << 16 | g << 8 | b);
}

t_pixel	**ft_fill(t_data *d, char *file)
{
	d->fd = open(file, O_RDONLY);
	d->y = 0;
	while (get_next_line(d->fd, &d->line))
	{
		ft_init_value(d);
		while (d->line[d->x] != '\0')
		{
			d->matrix[d->y][d->x].z = ft_atoi(&d->line[d->a]);
			while (ft_forward(&d->line[d->a]))
				d->a++;
			d->matrix[d->y][d->x].x = ft_get_x(d);
			d->matrix[d->y][d->x].y = ft_get_y(d);
			d->matrix[d->y][d->x].color = ft_get_color(&d->line[d->a], 0, 0, 0);
			while (d->line[d->a] != ' ' && d->line[d->a] != '\0')
				d->a++;
			if (d->line[d->a] == '\0')
				break ;
			d->a++;
			d->x++;
		}
		free (d->line);
		d->y++;
	}
	close (d->fd);
	return (0);
}

int	ft_w(char *file)
{
	int		x;
	int		result;
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		x = 0;
		result = 0;
		while (line[x] != '\0')
		{
			if (line[x] == ' ')
				result++;
			while (line[x] == ' ' && line[x + 1] != '\0')
				x++;
			x++;
		}
		free(line);
	}
	free(line);
	close (fd);
	return (result + 1);
}

int	ft_l(char *file)
{
	int		fd;
	char	*line;
	int		result;

	fd = open(file, O_RDONLY);
	result = 0;
	while (get_next_line(fd, &line))
	{
		result++;
		free(line);
	}
	close (fd);
	free(line);
	return (result);
}
