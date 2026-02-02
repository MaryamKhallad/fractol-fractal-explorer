/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhallad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:42:49 by mkhallad          #+#    #+#             */
/*   Updated: 2025/11/26 11:42:51 by mkhallad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_usage(void)
{
	write(1, "usage:\n", 7);
	write(1, "./fractol Mandelbrot\n", 22);
	write(1, "./fractol Julia <re> <im> if u wanna see her\n", 45);
	write(1, "./fractol burning_ship\n", 24);
	exit(1);
}

void	init_julia(t_fractal *fractal, int ac, char **av)
{
	double	re;
	double	im;

	if (ac != 4)
	{
		write(2, "Julia requires exactly 2 parameters (real and imaginary)\n", 57);
		exit(1);
	}
	re = ft_atod(av[2]);
	im = ft_atod(av[3]);
	if ((re < -2.0 || re > 2.0) || (im < -2.0 || im > 2.0))
	{
		write(2, "Parameters must be between -2.0 and 2.0\n", 40);
		exit(1);
	}
	fractal->julia_r = re;
	fractal->julia_i = im;
}

static void	set_fractal_bounds(t_fractal *fractal, char *type)
{
	if (!ft_strncmp(type, "Mandelbrot", 10))
	{
		fractal->min_re = -2.5;
		fractal->max_re = 1.0;
		fractal->min_im = -1.0;
		fractal->max_im = 1.0;
	}
	else if (!ft_strncmp(type, "Julia", 5))
	{
		fractal->min_re = -2.0;
		fractal->max_re = 2.0;
		fractal->min_im = -2.0;
		fractal->max_im = 2.0;
	}
	else if (!ft_strncmp(type, "burning_ship", 12))
	{
		fractal->min_re = -2.5;
		fractal->max_re = 1.5;
		fractal->min_im = -2.0;
		fractal->max_im = 1.0;
	}
}

void	init_fractol(t_fractal *fractal, char *type, int ac, char **av)
{
	fractal->type = type;
	fractal->zoom = 1.0;
	fractal->shift_x = 0;
	fractal->shift_y = 0;
	fractal->max_iter = 100;
	fractal->color_shift = 0;
	if (!type)
		print_usage();
	if (!ft_strncmp(type, "Mandelbrot", 10))
		set_fractal_bounds(fractal, type);
	else if (!ft_strncmp(type, "Julia", 5))
	{
		init_julia(fractal, ac, av);
		set_fractal_bounds(fractal, type);
	}
	else if (!ft_strncmp(type, "burning_ship", 12))
		set_fractal_bounds(fractal, type);
	else
		print_usage();
}

void	init_mlx(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		error_exit("MLX initialization failed");
	fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, fractal->type);
	if (!fractal->win)
	{
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
		error_exit("window creation failed");
	}
	fractal->img.img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->img.img)
	{
		mlx_destroy_window(fractal->mlx, fractal->win);
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
		error_exit("image creation failed");
	}
	fractal->img.addr = mlx_get_data_addr(fractal->img.img, &fractal->img.bpp,
			&fractal->img.line_len, &fractal->img.endian);
	if (!fractal->img.addr)
	{
		mlx_destroy_image(fractal->mlx, fractal->img.img);
		error_exit_clean("image creation failed", fractal);
	}
}
