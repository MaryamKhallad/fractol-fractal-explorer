/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhallad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:55:34 by mkhallad          #+#    #+#             */
/*   Updated: 2025/11/26 11:55:36 by mkhallad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_exit(char *m)
{
	write(2, "ERROR: ", 7);
	write(2, m, ft_strlen(m));
	write(2, "\n", 1);
	exit(1);
}

void	error_exit_clean(char *m, t_fractal *fractal)
{
	if (fractal->win)
		mlx_destroy_window(fractal->mlx, fractal->win);
	if (fractal->mlx)
	{
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
	}
	write(2, "ERROR: ", 7);
	write(2, m, ft_strlen(m));
	write(2, "\n", 1);
	exit(1);
}

double	map_range(t_map map)
{
	double	r;

	r = map.out_min + (map.value - map.in_min) * (map.out_max - map.out_min)
		/ (map.in_max - map.in_min);
	return (r);
}

static double	ft_atod_frac(const char **str)
{
	double	f;
	double	d;
	double	m;

	d = 1.0;
	f = 0.0;
	if (**str == '.')
	{
		(*str)++;
		if (**str == '\0')
			return (0.0);
		while (**str >= '0' && **str <= '9')
		{
			f = f * 10.0 + (**str - '0');
			d *= 10.0;
			(*str)++;
		}
	}
	m = (f / d);
	return (m);
}

double	ft_atod(const char *str)
{
	double	result;
	double	fraction;
	int		sign;

	if (!str || *str == '\0')
		error_exit("Invalid num");
	while (*str == ' ' || *str == '\t')
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	result = 0.0;
	while (*str >= '0' && *str <= '9')
		result = result * 10.0 + (*str++ - '0');
	fraction = ft_atod_frac(&str);
	if (*str != '\0')
		error_exit("Invalid num");
	return (sign * (result + fraction));
}
