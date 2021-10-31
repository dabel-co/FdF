/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabel-co <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 18:49:03 by dabel-co          #+#    #+#             */
/*   Updated: 2021/10/11 13:21:02 by dabel-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H
# include "./libft/libft.h"
# include "./GNL/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct s_pixel
{
	float	x;
	float	y;
	int		z;
	int		color;
}				t_pixel;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*line;
	int		a;
	int		fd;
	int		x;
	int		y;
	int		w;
	int		l;
	int		z1;
	int		z2;
	int		c1;
	int		c2;
	float	x1;
	float	y1;
	float	x2;
	float	y2;
	t_pixel	**matrix;
}				t_data;

void	ft_put_pixel(t_data *d, int x, int y, int color);
int		ft_l(char *lines);
int		ft_w(char *lines);
void	ft_maperror(int	s);
int		ft_hex_position(char x);
t_pixel	**ft_fill(t_data *d, char *file);
void	ft_draw(t_data *d);
int		ft_max(float x_step, float y_step);
int		ft_forward(char *x);
float	ft_get_x(t_data *d);
float	ft_get_y(t_data *d);
void	ft_check_z(t_data *d, int c, int z);
void	ft_change_z(t_data *d, int c, int z);
void	ft_init_value(t_data *d);
void	ft_init_win(t_data *d);
void	ft_bresenham(t_data *d, int z1, int z2);
void	ft_send_data(t_data *d, int x, int y);
void	ft_send_data_x(t_data *d, int x, int y, int p);
float	ft_color_change(t_data *d);
int		ft_key_hook(int keycode);
int		ft_hooked_funtion(int keycode);
void	ft_exit(t_data *d);
int		ft_free(t_data *d);
#endif
