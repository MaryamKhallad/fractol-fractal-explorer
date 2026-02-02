/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhallad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:42:37 by mkhallad          #+#    #+#             */
/*   Updated: 2025/11/26 11:42:41 by mkhallad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include <math.h>
# include "mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define WIDTH 800
# define HEIGHT 600

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_fractal
{
	void	*mlx;
	void	*win;
	t_img	img;
	char	*type;
	int		max_iter;
	double	julia_r;
	double	julia_i;
	double	zoom;
	double	shift_x;
	double	shift_y;
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
	int		color_shift;
	double	zr;
	double	zi;
	double	tmp;
}			t_fractal;

typedef struct s_map
{
	double	value;
	double	in_min;
	double	in_max;
	double	out_min;
	double	out_max;
}	t_map;

typedef struct s_extra
{
	double	result;
	double	fraction;
	int		sign;
	int		divisor;
	double	final;
}	t_extra;

void		print_usage(void);
void		init_julia(t_fractal *fractal, int ac, char **av);
void		init_mlx(t_fractal *fractal);
void		init_fractol(t_fractal *fractal, char *type, int ac, char **av);
int			run(t_fractal *fractal, int ac, char **av);
int			main(int ac, char **av);
void		my_pixel_put(t_fractal *fractal, int x, int y, int color);
void		render_fractal(t_fractal *fractal);
void		error_exit(char *m);
void		error_exit_clean(char *m, t_fractal *fractal);
double		map_range(t_map map);
int			is_valid_number(char *str);
double		ft_atod(const char *c);
int			close_handler(t_fractal *fractal);
int			key_handler(int keycode, t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
int			mandelbrot(double cr, double ci, t_fractal *fractal);
int			julia(double zr, double zi, t_fractal *fractal);
int			burning_ship(double cr, double ci, t_fractal *fractal);
#endif