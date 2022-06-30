/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:49:21 by mfroissa          #+#    #+#             */
/*   Updated: 2022/05/16 05:52:26 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count_words(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		while (str[i] && str[i] != c)
		{
			if (str[i + 1] == c || str[i + 1] == '\0')
				count++;
			i++;
		}
	}
	return (count);
}

static int	count_chars(char *str, char c, int n)
{
	int	i;
	int	chars;
	int	count;

	i = 0;
	count = 0;
	chars = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		while (str[i] && str[i] != c)
		{
			if (count == n)
				chars++;
			i++;
		}
		count++;
	}
	return (chars);
}

static char	*put_words(char *str, char c, int n, char *mot)
{
	int	i;
	int	count;
	int	chars;

	i = 0;
	count = 0;
	chars = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		while (str[i] && str[i] != c)
		{
			if (count == n)
			{
				mot[chars] = str[i];
				chars++;
			}
			if (str[i + 1] == c || str[i + 1] == '\0')
				count++;
			i++;
		}
	}
	mot[chars] = '\0';
	return (mot);
}

static char	**freev2(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	return (0);
}

char	**ft_split(const char *s, char c)
{
	char	**tab;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (count_words((char *) s, c) + 1));
	if (!tab)
		return (NULL);
	while (i < count_words((char *)s, c))
	{
		tab[i] = malloc(sizeof(char) * (count_chars((char *) s, c, i) + 1));
		if (!tab[i])
			return (freev2(tab));
		tab[i] = put_words((char *) s, c, i, tab[i]);
		i++;
	}
	tab[i] = 0;
	return (tab);
}
/*
#include <stdio.h>

int	main()
{
	char	**tab;
	int	i;

	i = 0;
	tab = ft_split("la kcorp a gagne 3 2 ", ' ');
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		free(tab[i]);
		i++;
	}
	free(tab);
}*/
