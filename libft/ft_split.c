/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmarti <cedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:41:40 by cedmarti          #+#    #+#             */
/*   Updated: 2024/11/05 12:52:48 by cedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	word;
	size_t	in_word;

	i = 0;
	word = 0;
	in_word = 0;
	while (s[i])
	{
		if (s[i] != c && in_word == 0)
		{
			word++;
			in_word = 1;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (word);
}

void	ft_strcopy(char *dest, const char *from, const char *to)
{
	while (from < to)
	{
		*dest = *from;
		dest++;
		from++;
	}
	*dest = '\0';
}

char	**ft_split(char const *s, char c)
{
	char		**d_tab;
	const char	*start;
	size_t		i;

	d_tab = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (d_tab == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s && *s != c)
		{
			start = s;
			while (*s && *s != c)
				s++;
			d_tab[i] = malloc(sizeof(char) * (s - start + 1));
			ft_strcopy(d_tab[i], start, s);
			i++;
		}
		else
			s++;
	}
	d_tab[i] = NULL;
	return (d_tab);
}

// int	main(void)
// {
// 	char	**tab;
// 	char	s[] = "  	coucou/je/suis cedric   ";
// 	char	c = '/';
// 	int	i;

// 	i = 0;
// 	tab = ft_split(s, c);
// 	while (tab[i] != NULL)
// 	{
// 		printf("%s\n", tab[i]);
// 		i++;
// 	}
// }
