/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-oliv <kde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 10:41:50 by kde-oliv          #+#    #+#             */
/*   Updated: 2021/06/16 18:58:40 by kde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	cont;

	cont = 0;
	while (s[cont] != '\0')
		cont++;
	return (cont);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*new_s;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new_s = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!new_s)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		new_s[i++] = s1[j++];
	j = 0;
	while (s2[j])
		new_s[i++] = s2[j++];
	new_s[i] = '\0';
	return (new_s);
}

char	*ft_strdup(const char *str)
{
	char	*ret;
	size_t	size;
	size_t	offset;

	size = ft_strlen(str);
	ret = malloc(size + 1);
	offset = 0;
	while (str[offset])
	{
		ret[offset] = str[offset];
		offset++;
	}
	ret[offset] = '\0';
	return (ret);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_cp_blockstr(char *save, size_t end)
{
	char	*dup;
	size_t	offset;

	dup = malloc(end + 1);
	if (dup == NULL)
		return (NULL);
	offset = 0;
	while (offset < end)
	{
		dup[offset] = save[offset];
		offset++;
	}
	dup[offset] = '\0';
	return (dup);
}
