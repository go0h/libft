/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:35:40 by astripeb          #+#    #+#             */
/*   Updated: 2019/04/04 21:46:29 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MY_HEADER_H
# define MY_HEADER_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>

int		ft_atoi(char *str);

int		ft_strcmp(char *s1, char *s2);

int		ft_strncmp(char *s1, char *s2, int n);

int		ft_isalpha(int c);

int		ft_isdigit(int c);

int		ft_isprint(int c);

int		ft_toupper(int c);

int		ft_tolower(int c);

size_t	ft_strlen(const char *c);

char	*ft_strdup(const char *s1);

char *ft_strcpy(char *dest, const char *src);

char *ft_strncpy(char *dest, const char *src, size_t n);

char *ft_strstr(const char *haystack, const char *needle);

#endif
