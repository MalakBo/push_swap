/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 23:12:03 by mac               #+#    #+#             */
/*   Updated: 2025/01/30 02:14:44 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(const char *str, char c)
{
	int	i;
	int	k;
	int	count;

	i = 0;
	k = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			k = 0;
		else
		{
			if (k == 0)
				count++;
			k = 1;
		}
		i++;
	}
	return (count);
}

void	free_split(char **a)
{
	int	i;

	i = 0;
	if (!a)
		return ;
	while (a[i])
		free(a[i++]);
	free(a);
}
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
char	*ft_strdup(const char *s)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dest || !s)
		return (0);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	n;
	size_t	i;
	char	*dest;

	i = 0;
	if (!s)
		return (NULL);
	n = ft_strlen(s);
	if (start >= n)
		return (ft_strdup("\0"));
	if (start + len >= n)
		len = n - start;
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (i < len && s[start])
	{
		dest[i] = s[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**a;

	int (i), (k), (start);
	if (!s)
		return (NULL);
	a = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!a)
		return (NULL);
	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
			a[k++] = ft_substr(s, start, i - start);
		if (!a)
			free_split(a);
	}
	a[k] = NULL;
	return (a);
}