/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhallad <mkhallad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:36:06 by mkhallad          #+#    #+#             */
/*   Updated: 2025/08/28 16:59:59 by mkhallad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned int		result;

	sign = 1;
	result = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * sign);
}
// int main (void)
// {
// 	printf("%d\n", ft_atoi("42"));
// 	printf("%d\n", ft_atoi("      -42"));
// 	printf("%d\n", ft_atoi("+123"));
// 	printf("%d\n", ft_atoi("123 maryam"));
// 	printf("%d\n", ft_atoi("    +0"));
// }