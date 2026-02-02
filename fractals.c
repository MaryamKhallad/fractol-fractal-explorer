/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhallad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:56:48 by mkhallad          #+#    #+#             */
/*   Updated: 2025/11/26 11:56:49 by mkhallad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

static int	get_color(int iterations, int max_iter, int shift)
{
	int	r;
	int	g;
	int	b;
	int	m;

	if (iterations == max_iter)
		return (0x000000);
	r = ((iterations * 9) + shift) % 256;
	g = ((iterations * 15) + shift) % 256;
	b = ((iterations * 20) + shift) % 256;
	m = (r << 16) | (g << 8) | b;
	return (m);
}

int	mandelbrot(double cr, double ci, t_fractal *fractal)
{
	int			i;
	int			color;
	int			m;
	t_fractal	test;

	test.zr = 0;
	test.zi = 0;
	i = 0;
	while (i < fractal->max_iter)
	{
		if ((test.zr * test.zr + test.zi * test.zi) > 4.0)
		{
			m = get_color(i, fractal->max_iter, fractal->color_shift);
			return (m);
		}
		test.tmp = test.zr * test.zr - test.zi * test.zi + cr;
		test.zi = 2 * test.zr * test.zi + ci;
		test.zr = test.tmp;
		i++;
	}
	color = get_color(fractal->max_iter, fractal->max_iter,
			fractal->color_shift);
	return (color);
}

int	julia(double zr, double zi, t_fractal *fractal)
{
	double	tmp;
	int		i;
	int		color;
	int		c;

	i = 0;
	while (i < fractal->max_iter)
	{
		if ((zr * zr + zi * zi) > 4.0)
		{
			c = get_color(i, fractal->max_iter, fractal->color_shift);
			return (c);
		}
		tmp = zr * zr - zi * zi + fractal->julia_r;
		zi = 2 * zr * zi + fractal->julia_i;
		zr = tmp;
		i++;
	}
	color = get_color(fractal->max_iter, fractal->max_iter,
			fractal->color_shift);
	return (color);
}

int	burning_ship(double cr, double ci, t_fractal *fractal)
{
	int			i;
	int			color;
	int			m;
	t_fractal	test;

	test.zr = 0;
	test.zi = 0;
	i = 0;
	while (i < fractal->max_iter)
	{
		if ((test.zr * test.zr + test.zi * test.zi) > 4.0)
		{
			m = get_color(i, fractal->max_iter, fractal->color_shift);
			return (m);
		}
		test.tmp = test.zr * test.zr - test.zi * test.zi + cr;
		test.zi = fabs(2 * test.zr * test.zi) + ci;
		test.zr = fabs(test.tmp);
		i++;
	}
	color = get_color(fractal->max_iter, fractal->max_iter,
			fractal->color_shift);
	return (color);
}
