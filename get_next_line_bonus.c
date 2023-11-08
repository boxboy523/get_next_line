/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyekim <junyekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:58:17 by junyekim          #+#    #+#             */
/*   Updated: 2023/11/08 19:00:14 by junyekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	t_fd	*target;
	char	*rtn;
	int		flag;

	if (fd < 0)
		return (NULL);
	target = find_target(fd, 0);
	if (!target)
		return (NULL);
	flag = 0;
	rtn = ft_strdup(target->remain);
	if (!rtn)
		flag = 1;
	if (!flag && !append_str(fd, &rtn))
		flag = 1;
	if (!flag && !ft_strchr(rtn, '\n'))
		flag = 2;
	if (!flag && !slice_str(&rtn, target))
		flag = 1;
	if (flag != 0)
		find_target(fd, 1);
	if (flag == 1)
		return (NULL);
	return (rtn);
}

char	*append_str(int fd, char **str)
{
	int		buf_len;
	char	buf[BUFFER_SIZE + 1];

	buf[0] = '\0';
	buf_len = 1;
	while (buf_len && !ft_strchr(buf, '\n'))
	{
		buf_len = read(fd, buf, BUFFER_SIZE);
		if (buf_len < 0 || (ft_strlen(*str) == 0 && buf_len == 0))
		{
			free(*str);
			*str = NULL;
			return (NULL);
		}
		buf[buf_len] = '\0';
		if (!ft_strdcat(str, buf, 1))
			return (NULL);
	}
	return (*str);
}

char	*slice_str(char **str, t_fd *t)
{
	size_t	newline;
	char	*swap;

	newline = (size_t)(ft_strchr(*str, '\n') - *str) + 1;
	free(t->remain);
	if (ft_strlen(*str) == newline)
		t->remain = NULL;
	else
	{
		t->remain = ft_substr(*str, newline, ft_strlen(*str) - newline);
		if (!t->remain)
		{
			free(*str);
			return (NULL);
		}
	}
	swap = ft_substr(*str, 0, newline);
	free(*str);
	if (!swap)
		return (NULL);
	*str = swap;
	return (*str);
}

t_fd	*find_target(int fd, int free_flag)
{
	static t_fd	data;
	t_fd		*target;
	t_fd		*temp;

	target = &data;
	while (target->next && target->next->fd != fd)
		target = target->next;
	if (free_flag && target->next)
	{
		temp = target->next->next;
		free(target->next->remain);
		free(target->next);
		target->next = temp;
	}
	if (!free_flag && !target->next)
	{
		target->next = ft_calloc(1, sizeof(t_fd));
		if (!target->next)
			return (NULL);
		target->next->fd = fd;
	}
	return (target->next);
}

char	*ft_strdup(const char *src)
{
	char	*dup;
	int		idx;
	int		size;

	if (!src)
		size = 0;
	else
		size = ft_strlen(src);
	dup = (char *)ft_calloc(size + 1, sizeof(char));
	if (!dup)
		return (NULL);
	idx = 0;
	while (idx < size)
	{
		dup[idx] = src[idx];
		idx++;
	}
	return (dup);
}
