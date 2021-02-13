/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 19:28:08 by astripeb          #+#    #+#             */
/*   Updated: 2021/02/13 19:14:11 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMORY_H
# define FT_MEMORY_H

# include <unistd.h>
# include <stdlib.h>

# define FT_HIMAGIC	0x8080808080808080L
# define FT_LOMAGIC	0x0101010101010101L

void			ft_bzero(void *s, size_t n);

void			*ft_memalloc(size_t size);

void			*ft_realloc(void *ptr, size_t old_size, size_t new_size);

void			*ft_memcpy(void *dest, const void *src, size_t n);

void			*ft_memccpy(void *dest, const void *src, int c, size_t n);

void			*ft_memchr(const void *s, int c, size_t n);

void			*ft_memmove(void *dest, const void *src, size_t n);

int				ft_memcmp(const void *s1, const void *s2, size_t n);

void			*ft_memset(void *s, int c, size_t n);

void			ft_memdel(void **ap);

#endif
