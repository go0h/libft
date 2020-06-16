/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 18:45:36 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/02 19:40:22 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <unistd.h>
# include <stdlib.h>

int				ft_atoi_base(char *s, int base);

int				ft_atoi(const char *str);

size_t			ft_char_count(char *str, char c);

size_t			ft_count_words(char const *s, char c);

void			ft_free_arr(char **data);

int				ft_isalnum(int c);

int				ft_isalpha(int c);

int				ft_isascii(int c);

int				ft_isdigit(int c);

int				ft_isdigitstr(char *str);

int				ft_isprint(int c);

int				ft_isspace(int c);

char			*ft_itoa(int n);

int				ft_len_arr(char **tab);

char			*ft_llitoa(long long int n);

size_t			ft_strlen(const char *s);

char			*ft_strdup(const char *s1);

char			*ft_strcpy(char *dst, const char *src);

char			*ft_strncpy(char *dst, const char *src, size_t len);

char			*ft_strcat(char *s1, const char *s2);

char			*ft_strncat(char *s1, const char *s2, size_t n);

size_t			ft_strlcat(char *dst, const char *src, size_t size);

char			*ft_strchr(const char *s, int c);

char			*ft_strrchr(const char *s, int c);

char			*ft_strstr(const char *haystack, const char *needle);

char			*ft_strnstr(const char *haystack,\
				const char *needle, size_t len);

int				ft_strcmp(const char *s1, const char *s2);

int				ft_strncmp(const char *s1, const char *s2, size_t n);

char			*ft_strnew(size_t size);

void			ft_strdel(char **as);

void			ft_strclr(char *s);

void			ft_striter(char *s, void (*f)(char *));

void			ft_striteri(char *s, void (*f)(unsigned int, char *));

char			*ft_strmap(char const *s, char (*f)(char));

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int				ft_strequ(char const *s1, char const *s2);

int				ft_strnequ(char const *s1, char const *s2, size_t n);

char			*ft_strsub(char const *s, unsigned int start, size_t len);

char			*ft_strjoin(char const *s1, char const *s2);

char			*ft_strjoin_f(char const *s1, char const *s2);

char			*ft_strjoin_s(char const *s1, char const *s2);

char			*ft_strtrim(char const *s);

char			**ft_strsplit(char const *s, char c);

char			**ft_strsplit_sp(char const *s);

void			ft_to_uppercase(char *str);

int				ft_toupper(int c);

int				ft_tolower(int c);

#endif
