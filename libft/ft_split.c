/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:55:37 by nrea              #+#    #+#             */
/*   Updated: 2023/11/20 12:18:20 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*ft_count_words: count the nb of words in the string s
separated by delimiter c*/
static int	ft_count_words(const char *s, char c)
{
	int	words_count;
	int	sep_found;

	words_count = 0;
	sep_found = 1;
	while (*s)
	{
		if (*s == c)
			sep_found = 1;
		else
		{
			if (sep_found)
			{
			words_count++;
			sep_found = 0;
			}
		}
		s++;
	}
	return (words_count);
}

/*ft_wordlen : count the nb of char in s until c is encounterd
				return the count nb*/
static int	ft_wordlen(const char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && (s[len] != c))
		len++;
	return (len);
}

/*Frees the splitted array if something went wrong during the malloc
of one of the words*/
static void	*ft_free_splitted(char **splitted, int wc)
{
	int	i;

	i = 0;
	while (i < wc)
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
	return (NULL);
}

/*Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must end
with a NULL pointer.*/
char	**ft_split(char const *s, char c)
{
	char	**splitted;
	int		split_nb;
	int		i;

	if (!s)
		return (NULL);
	split_nb = ft_count_words(s, c) + 1;
	splitted = malloc(split_nb * sizeof(char *));
	if (!splitted)
		return (NULL);
	i = 0;
	while (i < (split_nb - 1))
	{
		while (*s && (*s == c))
			s++;
		splitted[i] = malloc((ft_wordlen(s, c) + 1) * sizeof(char));
		if (!splitted[i])
			return (ft_free_splitted(splitted, i));
		ft_strlcpy(splitted[i], s, ft_wordlen(s, c) + 1);
		while (*s && (*s != c))
			s++;
		i++;
	}
	splitted[i] = NULL;
	return (splitted);
}
