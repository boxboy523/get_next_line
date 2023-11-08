/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyekim <junyekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:50:36 by junyekim          #+#    #+#             */
/*   Updated: 2023/11/08 19:23:40 by junyekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	const size_t	len = ft_strlen(s) + 1;
	const char		char_c = (char)c;

	i = 0;
	while (i < len)
	{
		if (s[i] == char_c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			substr_size;
	char			*substr;
	unsigned int	i;

	if (len + start > ft_strlen(s))
		substr_size = ft_strlen(s) - start;
	else
		substr_size = len;
	if (start >= ft_strlen(s))
		substr_size = 0;
	substr = malloc(substr_size + 1 * sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < substr_size)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	size_t	n;

	if (size != 0 && count * size / size != count)
		return (NULL);
	mem = malloc(count * size);
	if (!mem)
		return (NULL);
	n = count * size;
	while (n > 0)
	{
		((unsigned char *)mem)[n - 1] = 0;
		n--;
	}
	return (mem);
}

char	*ft_strdcat(char **dst, const char *src, int dstallocated)
{
	const long long	dstsize = ft_strlen(*dst);
	const long long	srcsize = ft_strlen(src);
	char			*swap;
	long long		i;

	swap = (*dst);
	*dst = ft_calloc(dstsize + srcsize + 1, sizeof(char));
	if (!(*dst) && dstallocated)
	{
		free(swap);
		return (NULL);
	}
	else if (!(*dst))
		return (NULL);
	i = -1;
	while (i++ < dstsize + srcsize)
	{
		if (i < dstsize)
			(*dst)[i] = swap[i];
		else
			(*dst)[i] = src[i - dstsize];
	}
	if (dstallocated)
		free(swap);
	return (*dst);
}
