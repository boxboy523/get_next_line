/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyekim <junyekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:55:27 by junyekim          #+#    #+#             */
/*   Updated: 2023/11/08 19:24:25 by junyekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif
# if BUFFER_SIZE < 1
#  error BUFFER_SIZE must be greater than 0
# endif
# if BUFFER_SIZE > 100000
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 100000
# endif

typedef struct s_fd
{
	int			fd;
	char		*remain;
	struct s_fd	*next;
}	t_fd;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *c);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdcat(char **dst, const char *src, int ismalloc);
t_fd	*find_target(int fd, int free_flag);
char	*append_str(int fd, char **str);
char	*slice_str(char **str, t_fd *t);
char	*ft_strdup(const char *src);

#endif