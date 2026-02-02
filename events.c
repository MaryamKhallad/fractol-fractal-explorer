/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhallad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:55:47 by mkhallad          #+#    #+#             */
/*   Updated: 2025/11/26 11:55:50 by mkhallad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img.img);
	mlx_destroy_window(fractal->mlx, fractal->win);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	exit(0);
}

static void	handle_arrow_keys(int keycode, t_fractal *fractal, double shift)
{
	if (keycode == 65361)
	{
		fractal->min_re -= shift;
		fractal->max_re -= shift;
	}
	else if (keycode == 65363)
	{
		fractal->min_re += shift;
		fractal->max_re += shift;
	}
	else if (keycode == 65362)
	{
		fractal->min_im -= shift;
		fractal->max_im -= shift;
	}
	else if (keycode == 65364)
	{
		fractal->min_im += shift;
		fractal->max_im += shift;
	}
}

int	key_handler(int keycode, t_fractal *fractal)
{
	double	shift;

	if (keycode == 65307)
		close_handler(fractal);
	shift = 0.1 * (fractal->max_re - fractal->min_re);
	handle_arrow_keys(keycode, fractal, shift);
	if (keycode >= 65361 && keycode <= 65364)
		render_fractal(fractal);
	else if (keycode == 99)
	{
		fractal->color_shift += 10;
		render_fractal(fractal);
	}
	else if (keycode == 118)
	{
		fractal->color_shift -= 10;
		render_fractal(fractal);
	}
	return (0);
}

static void	zoom_handler(t_fractal *f, int x, int y, double factor)
{
	double	mouse_re;
	double	mouse_im;

	mouse_re = map_range((t_map){x, 0, WIDTH, f->min_re, f->max_re});
	mouse_im = map_range((t_map){y, 0, HEIGHT, f->min_im, f->max_im});
	f->min_re = mouse_re + (f->min_re - mouse_re) * factor;
	f->max_re = mouse_re + (f->max_re - mouse_re) * factor;
	f->min_im = mouse_im + (f->min_im - mouse_im) * factor;
	f->max_im = mouse_im + (f->max_im - mouse_im) * factor;
	if (factor < 1.0 && f->max_iter < 500)
		f->max_iter += 10;
	render_fractal(f);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	if (button == 4)
		zoom_handler(fractal, x, y, 0.55);
	else if (button == 5)
		zoom_handler(fractal, x, y, 2.0);
	return (0);
}
