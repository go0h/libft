/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 19:11:28 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/03 17:49:13 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IO_H
# define FT_IO_H

# define BUFF_SIZE	4096
# define MAX_FD		256

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

int				ft_putchar(int c);

int				ft_putchar_fd(int c, int fd);

int				ft_putchar_utf8(int c);

int				ft_putchar_utf8_fd(int c, int fd);

int				ft_putstr(char const *s);

int				ft_putstr_fd(char const *s, int fd);

int				ft_putstr_utf8(int const *s);

int				ft_putstr_utf8_fd(int const *s, int fd);

int				ft_putnstr_utf8_fd(int const *s, int fd, int len);

char			ft_lenwchar(int c);

size_t			ft_lstrlen(const int *s);

void			ft_putendl(char const *s);

void			ft_putnbr(int n);

void			ft_putendl_fd(char const *s, int fd);

void			ft_putnbr_fd(int n, int fd);

int				get_next_line(const int fd, char **line);

char			*ft_read_from_file_to_var(int fd);

#endif
