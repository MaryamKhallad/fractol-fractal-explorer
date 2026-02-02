/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhallad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:55:14 by mkhallad          #+#    #+#             */
/*   Updated: 2025/11/26 11:55:20 by mkhallad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	run(t_fractal *fractal, int ac, char **av)
{
	if (ac < 2)
	{
		print_usage();
		exit(1);
	}
	else if (ft_strncmp(av[1], "Mandelbrot", 10) == 0 && av[1][10] == '\0'
		&& ac == 2)
		init_fractol(fractal, "Mandelbrot", ac, av);
	else if (ft_strncmp(av[1], "Julia", 5) == 0 && av[1][5] == '\0'
		&& ac == 4)
		init_fractol(fractal, "Julia", ac, av);
	else if (ft_strncmp(av[1], "burning_ship", 12) == 0 && av[1][12] == '\0'
		&& ac == 2)
		init_fractol(fractal, "burning_ship", ac, av);
	else
	{
		print_usage();
		exit(1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int			f;
	t_fractal	fractal;

	f = run(&fractal, ac, av);
	init_mlx(&fractal);
	render_fractal(&fractal);
	mlx_key_hook(fractal.win, key_handler, &fractal);
	mlx_mouse_hook(fractal.win, mouse_handler, &fractal);
	mlx_hook(fractal.win, 17, 0, close_handler, &fractal);
	mlx_loop(fractal.mlx);
	return (f);
}
