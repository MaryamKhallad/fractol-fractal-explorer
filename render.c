/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhallad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:56:15 by mkhallad          #+#    #+#             */
/*   Updated: 2025/11/26 11:56:17 by mkhallad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_pixel_put(t_fractal *fractal, int x, int y, int color)
{
	char	*dst;

	dst = fractal->img.addr + (y * fractal->img.line_len + x * (fractal->img.bpp
				/ 8));
	*(unsigned int *)dst = color;
}

static void	render_pixel(t_fractal *fractal, int x, int y)
{
	double	cr;
	double	ci;
	int		color;

	cr = map_range((t_map){x, 0, WIDTH, fractal->min_re, fractal->max_re});
	ci = map_range((t_map){y, 0, HEIGHT, fractal->min_im, fractal->max_im});
	if (!ft_strncmp(fractal->type, "Mandelbrot", 10))
	{
		color = mandelbrot(cr, ci, fractal);
	}
	else if (!ft_strncmp(fractal->type, "Julia", 5))
	{
		color = julia(cr, ci, fractal);
	}
	else
	{
		color = burning_ship(cr, ci, fractal);
	}
	my_pixel_put(fractal, x, y, color);
}

void	render_fractal(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			render_pixel(fractal, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img.img, 0, 0);
}
