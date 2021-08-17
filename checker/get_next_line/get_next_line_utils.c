/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheaton- <fheaton-@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 14:31:30 by fheaton-          #+#    #+#             */
/*   Updated: 2021/08/05 21:45:06 by fheaton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s && *s != (t_uc)c)
		s++;
	return ((char *)ft_ternary(*s == (t_uc)c, (int64_t)s, 0));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	size1;
	size_t	size2;

	if (!s2)
		return (NULL);
	if (!s1)
		size1 = 0;
	else
		size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	if (!ft_set((int64_t *)&ret, (int64_t)malloc(size1 + size2 + 1)))
		return (NULL);
	ft_memcpy(ret, s1, size1);
	ft_memcpy(ret + size1, s2, size2 + 1);
	return (ret);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	t_uc	*d;
	t_uc	*s;
	size_t	i;

	if (!src && !dest)
		return (NULL);
	d = (t_uc*)dest;
	s = (t_uc*)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	r;

	r = 0;
	while (s[r])
		r++;
	return (r);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	size;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		ret = malloc(1);
		ret[0] = '\0';
		return (ret);
	}
	size = ft_strlen(s + start);
	size = ft_ternary(size > len, len, size);
	if (!ft_set((int64_t *)&ret, (int64_t)malloc(size + 1)))
		return (NULL);
	ret = ft_memcpy(ret, s + start, size);
	ret[size] = '\0';
	return (ret);
}
