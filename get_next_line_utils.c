/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhunter <mhunter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:55:08 by mhunter           #+#    #+#             */
/*   Updated: 2022/04/15 19:32:33 by mhunter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	*out;

	out = (char *)s;
	while (*out != '\0')
	{
		if (*out == (char)c)
			return (out);
		out++;
	}
	if (*out == (char)c)
		return (out);
	return (NULL);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*ret;
	char	*tmp;
	size_t	i;

	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	tmp = (char *)s + start;
	i = 0;
	while (*tmp && i < len)
		ret[i++] = *tmp++;
	ret[i] = 0;
	return (ret);
}

size_t	ft_strlen(const char *s)
{
	size_t	ret;

	ret = 0;
	while (*s++)
		++ret;
	return (ret);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		s2_ind;
	char	*output;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	s2_ind = 0;
	output = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!output)
		return (NULL);
	while (s1[i] != '\0')
	{
		output[i] = s1[i];
		i++;
	}
	while (s2[s2_ind] != '\0')
	{
		output[i] = s2[s2_ind];
		i++;
		s2_ind++;
	}
	output[i] = '\0';
	return (&output[0]);
}
