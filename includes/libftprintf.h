/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 15:43:43 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/03 18:45:42 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "ft_memory.h"
# include "ft_string.h"
# include "ft_io.h"
# include "ft_math.h"

# include <stdarg.h>
# include <stdint.h>
# include <stddef.h>

# define MALLOC_FAILURE 2

# define BASE 1000000000
# define BASE_LEN 9
# define MAX_LEN 1300

# define LOG2 0x3fd34413509f79ff

/*
** Struct for modifiers storage after parsing '%'
** ' ' '#' '+' '-' '0' 'h' 'hh' 'l' 'll' 'j' 'z' 'L'
** Width and precision
*/

typedef struct	s_modific
{
	int		width;
	int		precision;
	int		fd;
	char	plus;
	char	align;
	char	zero;
	char	hash;
	char	space;
	char	type;
	char	sp;
}				t_modific;

/*
** Union to get the mantissa, exponent and sign
** from long double by IEEE 754, for little-endian systems
*/

typedef union	u_ex_double
{
	struct		s_fields
	{
		unsigned long int		mantissa:64;
		unsigned int			exponent:15;
		unsigned char			sign:1;
	}							t_fd;
	long double					dbl;
}				t_ex_double;

/*
** Utility functions
*/

int				print_filler(int len, char c, int fd);

int				numlen(long long int nbr, int base);

int				numlen_u(unsigned long long int nbr, int base);

void			add_dig_s(long long int nbr, int base, char *stack, int k);

void			add_dig_u(unsigned long long int nbr, int base,\
				char *stack, int k);

int				print_hex_prefix(char x, int fd);

int				set_precision(va_list ap, t_modific *mod, const char *str);

int				spec_star(int num, t_modific *mod);

/*
** Functions for add information about format in the structure
*/

int				ft_ismodific(char c);

int				isspec(char c);

t_modific		*new_modific(t_modific *mod, int fd);

int				parsing_modific(const char *str, t_modific *mod, va_list ap);

int				ft_strlen_s(const char *str);

/*
** main (start) functions
*/

int				ft_printf(const char *format, ...);

int				ft_fprintf(int fd, const char *format, ...);

int				pr_sp(va_list ap, t_modific *mod, char spec);

int				pr_non_sp(t_modific *mod, char c);

/*
** Functions for print for %s %S %c %C %p specificators
*/

int				print_char(int c, t_modific *mod, char spec);

int				print_str(char *str, t_modific *mod, char spec);

int				print_pointer(long long int adr, t_modific *mod);

/*
** Functions for print for
** %d %u %U %o %O %x %X %i specificators
*/

int				preint_ox_num(unsigned long long num, t_modific *mod,\
				char spec);

int				print_num_s(intmax_t num, t_modific *mod, char spec);

int				print_num_u(uintmax_t num, t_modific *mod, char spec);

int				print_not_dec(unsigned long long int num, t_modific *mod,\
				char spec);

int				ft_putnbr_s(long long n, t_modific *mod);

int				ft_putnbr_u(unsigned long long n, t_modific *mod);

int				ft_putnbr_b(unsigned long long n, t_modific *mod);

int				print_nbr(unsigned long long int nbr, int base, char spec,\
				int fd);

/*
** Bonus functions
*/

void			count_print(long long int addr, int pr_count);

int				print_binary(unsigned long long num, t_modific *mod);

int				set_color(const char *str, int *n, int fd);

/*
** Functions for print specifier %f %F %e %E
** works with long arithmetic
*/

int				print_double(va_list ap, t_modific *mod, char spec);

int				print_scientific(va_list ap, t_modific *mod, char spec);

char			*ft_dtoa(long double dbl, int precision);

char			*ft_dtoe(long double dbl, int precision);

int				ft_round_e(char **str, long double d, t_modific *mod);

int				ft_round_dbl(char **str, int precision);

char			*ft_dec_part(long int mantissa, int exp, char *ofset,\
				char flag);

char			*ft_isspecdouble(t_ex_double dbl);

/*
** Functions for calculating large numbers
** and convert to string for specifier %f %F %e %E
*/

char			*laitoa(long int a[]);

char			*laitoe(long int a[]);

void			ft_add(long int a[], long int b[]);

void			ft_mul_s(long int a[], long int b, short len);

void			ft_pow_l(long int a[], int exp, int base, short len);

int				size_long(long int a[], short len);

void			ft_bzero_long(long int a[], short len);

#endif
