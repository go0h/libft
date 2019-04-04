/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:35:40 by astripeb          #+#    #+#             */
/*   Updated: 2019/04/04 20:26:29 by astripeb         ###   ########.fr       */
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

int		ft_isalpha(char *str);

int		ft_isdigit(char *str);

int		ft_isprint(char *str);

char	*ft_toupper(char *str);

char	*ft_tolower(char *str);

#endif
