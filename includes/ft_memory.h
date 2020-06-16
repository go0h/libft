/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 19:28:08 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/02 19:41:33 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMORY_H
# define FT_MEMORY_H

# include <unistd.h>
# include <stdlib.h>

void			ft_bzero(void *s, size_t n);

void			*ft_memalloc(size_t size);

void			*ft_memcpy(void *dest, const void *src, size_t n);

void			*ft_memccpy(void *dest, const void *src, int c, size_t n);

void			*ft_memchr(const void *s, int c, size_t n);

void			*ft_memmove(void *dest, const void *src, size_t n);

int				ft_memcmp(const void *s1, const void *s2, size_t n);

void			*ft_memset(void *s, int c, size_t n);

void			ft_memdel(void **ap);

#endif
