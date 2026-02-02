/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhallad <mkhallad@student.42.fr>      		+#+  +:+      
			+#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:53:21 by mkhallad          #+#    #+#             */
/*   Updated: 2025/08/19 15:51:21 by mkhallad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp_ptr;

	tmp_ptr = (unsigned char *)b;
	while (len > 0)
	{
		*(tmp_ptr++) = (unsigned char)c;
		len--;
	}
	return (b);
}
// int main(void)
//{
//    char str[10] = "abcdefghi";
//
//    ft_memset(str, 'X', 5);
//    printf("%s\n", str);  // Should print: XXXXXfghi
//
//    return (0);
//}