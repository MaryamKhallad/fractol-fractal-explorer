/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhallad <mkhallad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:15:32 by mkhallad          #+#    #+#             */
/*   Updated: 2025/09/01 12:32:20 by mkhallad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*c_src;
	char	*c_dest;

	c_src = (char *)src;
	c_dest = (char *)dest;
	if (c_dest > c_src)
		while (len--)
			c_dest[len] = c_src[len];
	else
	{
		while (len--)
			*c_dest++ = *c_src++;
	}
	return (dest);
}
// int main()
//{
// no overlapping test case
//    char src1[] = "Hello, world!";
//    char dest1[50];
//    printf("Before : %s\n", src1);
//  ft_memmove(dest1, src1, strlen(src1) + 1);// +1 to include null terminator
//    printf("After : %s\n", dest1);
// Overlapping memory regions (move within the same array)
//    char src2[] = "Hello, world!";
//    printf("\nBefore : %s\n", src2);
//    ft_memmove(src2 + 6, src2, 5);  // Move "Hello" to position 6
//  printf("After : %s\n", src2);
// src and dest are the same address
//  char src3[] = "Hello, world!";
//    printf("\nBefore : %s\n", src3);
// ft_memmove(src3, src3 + 7, 6);  // Move "world!" to the start of the string
//    printf("After : %s\n", src3);
//    return (0);
//}