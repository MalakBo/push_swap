/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 23:41:23 by mbouyi            #+#    #+#             */
/*   Updated: 2025/02/10 16:05:54 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*s3;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		s3[i++] = s2[j++];
	s3[i] = '\0';
	free((char *)s1);
	return (s3);
}
char	*get_buffer(int fd, char *res)
{
	ssize_t	i;
	char	*buff;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	i = 1;
	while (i > 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(buff);
			free(res);
			return (NULL);
		}
		if (i == 0)
			break ;
		buff[i] = '\0';
		res = ft_strjoin(res, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	return (res);
}

char	*get_f(char *res)
{
	int		i;
	char	*line;

	i = 0;
	while (res[i] && res[i] != '\n')
		i++;
	if (res[i] == '\n')
		i++;
	line = ft_substr(res, 0, i);
	return (line);
}

char	*get_n(char *res)
{
	int		i;
	char	*line;

	i = 0;
	while (res[i] && res[i] != '\n')
		i++;
	if (res[i] == '\n')
		i++;
	line = ft_substr(res, i, ft_strlen(res) - i);
	free(res);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*res;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	res = get_buffer(fd, res);
	if (!res || *res == '\0')
	{
		if (res)
			free(res);
		res = NULL;
		return (NULL);
	}
	line = get_f(res);
	res = get_n(res);
	return (line);
}

// int main()
// {
//     int fd = open("test.txt",O_RDONLY);
//     char *line;
//     line = get_next_line(fd);
//     if(line)
//     {
//         printf("%s", line);
//         free(line);
//     }
// //     while((line = get_next_line(fd)))
// //     {
// //         printf("%s",line);
// //         free(line);
// //    }
//    close(fd);
//    return(0);
// }
/*int main()
{
		int fd = open("test.txt",O_RDONLY);
		printf("%s",get_next_line(fd));
		printf("%s",get_next_line(fd));
		printf("%s",get_next_line(fd));
		printf("%s",get_next_line(fd));
		printf("%s",get_next_line(fd));
}*/