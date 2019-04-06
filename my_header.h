/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:35:40 by astripeb          #+#    #+#             */
/*   Updated: 2019/04/06 10:47:07 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MY_HEADER_H
# define MY_HEADER_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>

int		ft_atoi(const char *str);

int		ft_strcmp(const char *s1, const char *s2);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

int		ft_isalpha(int c);

int		ft_isdigit(int c);

int		ft_isprint(int c);

int		ft_toupper(int c);

int		ft_tolower(int c);

size_t	ft_strlen(const char *c);

char	*ft_strdup(const char *s1);

char	*ft_strcpy(char *dst, const char *src);

char	*ft_strncpy(char *dst, const char *src, size_t len);

char	*ft_strstr(const char *haystack, const char *needle);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

char	*ft_strcat(char *restrict s1, const char *restrict s2);

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n);

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size);

#endif
