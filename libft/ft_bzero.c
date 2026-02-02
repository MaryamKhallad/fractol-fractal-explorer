/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhallad <mkhallad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:55:49 by mkhallad          #+#    #+#             */
/*   Updated: 2025/08/27 12:31:41 by mkhallad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}
// int main(void)
//{
//    char str[10] = "ABCDEFGHIJ";
//    printf("Before ft_bzero: %s\n", str);
//
//    ft_bzero(str, 5);  // Set the first 5 characters to '\0'
//	int i = 0;
//	while(i < 10)
//	{
//		printf("After ft_bzero: %c\n", str[i]);
//		i++;
//	}
//    return (0);
//}