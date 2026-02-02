/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhallad <mkhallad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 12:00:07 by mkhallad          #+#    #+#             */
/*   Updated: 2025/08/31 15:09:16 by mkhallad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	word_count(char const *s, char c)
{
	size_t	count;
	size_t	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static	char	*word_dup(const char *s, size_t start, size_t end)
{
	char	*word;

	word = malloc(end - start + 1);
	if (!word)
		return (NULL);
	ft_memcpy(word, s + start, end - start);
	word[end - start] = '\0';
	return (word);
}

static size_t	fill_word(char **result, const char *s, char c, size_t *idx)
{
	size_t	start;
	size_t	i;

	i = *idx;
	while (s[i] && s[i] == c)
		i++;
	start = i;
	while (s[i] && s[i] != c)
		i++;
	*idx = i;
	result[0] = word_dup(s, start, i);
	return (!result[0]);
}

static size_t	fill_split(char **result, const char *s, char c)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (fill_word(result + k, s, c, &i))
				return (k + 1);
			k++;
		}
		else
			i++;
	}
	result[k] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	no_words;
	size_t	err_k;

	if (!s)
		return (NULL);
	no_words = word_count(s, c);
	result = malloc((no_words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	err_k = fill_split(result, s, c);
	if (err_k)
	{
		while (err_k-- > 0)
			free (result[err_k]);
		free(result);
		return (NULL);
	}
	return (result);
}
// int main(void)
// {
// char	**res = ft_split("been living here since 2005!", ' ');

// 	if (!res)
// 		return 1;
// 	for (size_t i = 0; res[i]; i++)
// 	{
// 		printf("word[%zu]: '%s'\n", i, res[i]);
// 		free(res[i]);
// 	}
// 	free(res);
// 	return (0);
// }