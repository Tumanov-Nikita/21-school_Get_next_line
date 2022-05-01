/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhunter <mhunter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:54:48 by mhunter           #+#    #+#             */
/*   Updated: 2022/04/15 19:13:54 by mhunter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main()
{
	int		fd;
	char	*name;
	char	*res;

	name = "my.txt";
	fd = open(name, O_RDONLY);
	if (fd == -1)
		return (0);

	
	res = get_next_line(fd);
	printf("\'%s\'\n", res);
	free(res);
	res = get_next_line(fd);
	printf("\'%s\'\n", res);
	free(res);
	res = get_next_line(fd);
	printf("\'%s\'\n", res);
	free(res);
	res = get_next_line(fd);
	printf("\'%s\'\n", res);
	free(res);
	res = get_next_line(fd);
	printf("\'%s\'\n", res);
	free(res);
	res = get_next_line(fd);
	printf("\'%s\'\n", res);
	free(res);
	res = get_next_line(fd);
	printf("\'%s\'\n", res);
	free(res);
	res = get_next_line(fd);
	printf("\'%s\'\n", res);
	free(res);
	res = get_next_line(fd);
	printf("\'%s\'\n", res);
	free(res);
	close(fd);

	return (0);
}

static void	ft_read_line(int fd, char *buf, char **str)
{
	int		i;
	char	*tmp;

	if (!*str || !ft_strchr(*str, '\n'))
	{
		i = read(fd, buf, BUFFER_SIZE);
		while (i > 0)
		{
			buf[i] = 0;
			if (!*str)
				*str = ft_substr(buf, 0, i);
			else
			{
				tmp = *str;
				*str = ft_strjoin(*str, buf);
				free(tmp);
			}
			if (ft_strchr(buf, '\n'))
				break ;
			i = read(fd, buf, BUFFER_SIZE);
		}
	}
	free(buf);
}

static char	*ft_process_line(char **str)
{
	int		i;
	int		j;
	char	*ret;
	char	*tmp;

	if (!*str)
		return (0);
	if (!ft_strchr(*str, '\n'))
	{
		ret = ft_substr(*str, 0, ft_strlen(*str));
		free(*str);
		*str = 0;
		return (ret);
	}
	i = ft_strlen(*str);
	j = ft_strlen(ft_strchr(*str, '\n'));
	ret = ft_substr(*str, 0, i - j + 1);
	tmp = *str;
	*str = ft_substr(ft_strchr(*str, '\n'), 1, j - 1);
	free(tmp);
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*str;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	if (BUFFER_SIZE < 1 || fd == -1 || read(fd, buf, 0) == -1)
	{
		free(buf);
		return (0);
	}
	ft_read_line(fd, buf, &str);
	return (ft_process_line(&str));
}
