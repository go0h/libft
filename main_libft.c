/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 10:24:25 by astripeb          #+#    #+#             */
/*   Updated: 2019/03/05 21:34:36 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int			ft_atoi(char *str);

void		ft_putstr(char *str);

void		ft_putnbr(int	nb);

char		*ft_strcpy(char *dest, char *src);

char		*ft_strncpy(char *dest, char *src, unsigned int n);

char		*ft_strstr(char *str, char *to_find);

int			ft_strcmp(char *s1, char *s2);

int			ft_strncmp(char *s1, char *s2, int n);

char		*ft_strupcase(char *str);

char		*ft_strlowcase(char *str);

char		*ft_strcapitalize(char *str);

int			ft_str_is_alpha(char *str);

int			ft_str_is_numeric(char *str);

int			ft_str_is_lowercase(char *str);

int			ft_str_is_uppercase(char *str);

int			ft_str_is_printable(char *str);

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

int			main(void)
{
	//ex00
	char str[] =  "EX00\n";
	ft_putstr(str);

	//ex01
	printf("EX01\n");
	ft_putnbr(2147483647);
	ft_putchar('\n');
	ft_putnbr(-2147483648);
	ft_putchar('\n');

	//ex02
	printf("EX02\n");
	printf("%d = %d\n", atoi("dwf24ss"), ft_atoi("dwf24ss"));
	printf("%d = %d\n", atoi("--324ss"), ft_atoi("--324ss"));
	printf("%d = %d\n", atoi("-324ss"), ft_atoi("-324ss"));
	printf("%d = %d\n", atoi("00024"), ft_atoi("00024"));
	printf("%d = %d\n", atoi("\t\n+213s5"), ft_atoi("\t\n+213s5"));
	printf("%d = %d\n", atoi("\b\t\n-213s5"), ft_atoi("\b\t\n-213s5"));
	printf("%d = %d\n", atoi("    99999"), ft_atoi("    99999"));
	printf("%d = %d\n", atoi("999999999999"), ft_atoi("999999999999"));
	
	//ex03
	printf("EX03\n");
	char str4[] = "alloha";
	char str5[] = "hi";
	char *str6;
	//str6 = ft_strcpy(str5, str4);
	str6 = ft_strcpy(str5, str4);
	printf("%s == %s == %s\n", str4, str5, str6);

	//ex04
	int n;
	n = 10;
	printf("EX04\n");
	char str_ex04_1[] = "Privet, kak dela?";
	char str_ex04_2[15];
	char *str_ex04_3;
	str_ex04_3 = ft_strncpy(str_ex04_2, str_ex04_1, n);
	printf("%s = %s\n", str_ex04_2, str_ex04_3);
	puts(str_ex04_1);

	//ex05
	printf("EX05\n");
	char ex05_1[] = "aaaaManaaaa";
	char ex05_2[] = "aMan";
	char *ex05_3;
	ex05_3 = strstr(ex05_1, ex05_2);
	printf("%s\n%s\n", ex05_1, ex05_3);
	char ex05_4[] = "aaaaManaaaa";
	char ex05_5[] = "aMan";
	ex05_3 = ft_strstr(ex05_4, ex05_5);
	printf("%s\n%s\n", ex05_4, ex05_3);

	//ex06
	printf("EX06\n");
	char ex06_1[] = "Hello";
	char ex06_2[] = "Hello";
	char ex06_3[] = "Hi";
	printf("%d = %d\n", strcmp(ex06_1, ex06_2), ft_strcmp(ex06_1, ex06_2));
	printf("%d = %d\n", strcmp(ex06_3, ex06_2), ft_strcmp(ex06_3, ex06_2));
	printf("%d = %d\n", strcmp(ex06_1, ex06_3), ft_strcmp(ex06_1, ex06_3));
	
	//ex07
	printf("EX07\n");
	char ex07_1[] = "Privet kak dela?";
	char ex07_2[] = "Zdarov kak dela?";
	char ex07_3[] = "Privet kak dela?";
	n = 6;
	printf("%d = %d\n", strncmp(ex07_1, ex07_2, n), ft_strncmp(ex07_1, ex07_2, n));
	printf("%d = %d\n", strncmp(ex07_2, ex07_1, n), ft_strncmp(ex07_2, ex07_1, n));
	printf("%d = %d\n", strncmp(ex07_1, ex07_3, n), ft_strncmp(ex07_1, ex07_3, n));

	//ex08
	printf("EX08\n");
	printf("%s == %s\n", ft_strupcase(ex07_1), ex07_1);
	
	//ex09
	printf("EX09\n");
	printf("%s == %s\n", ft_strlowcase(ex07_1), ex07_1);

	//ex10
	printf("EX10\n");
	char ex10_1[] = "salut, comment tu vas ? 42mots quarante-deux: cinquante+et+un";
	printf("%s\n", ft_strcapitalize(ex10_1));

	//ex11
	printf("EX11\n");
	char ex11_1[] = "salutcommenttuvas";
	char ex11_2[] = "salut c1omment tu vas ";
	char ex11_3[] = "\0";
	printf("1 = %d\n", ft_str_is_alpha(ex11_1));
	printf("0 = %d\n", ft_str_is_alpha(ex11_2));
	printf("1 = %d\n", ft_str_is_alpha(ex11_3));

	//ex12
	printf("EX12\n");
	char ex12_1[] = "1111357809867";
	char ex12_2[] = "salut c1omment tu vas ";
	char ex12_3[] = "\0";
	printf("1 = %d\n", ft_str_is_numeric(ex12_1));
	printf("0 = %d\n", ft_str_is_numeric(ex12_2));
	printf("1 = %d\n", ft_str_is_numeric(ex12_3));
	
	//ex13
	printf("EX13\n");
	char ex13_1[] = "aghihjbijriwohbdfiohvdsfoie";
	char ex13_2[] = "salusadr40fjcdDSALDJs;dJ:A";
	char ex13_3[] = "\0";
	printf("1 = %d\n", ft_str_is_lowercase(ex13_1));
	printf("0 = %d\n", ft_str_is_lowercase(ex13_2));
	printf("1 = %d\n", ft_str_is_lowercase(ex13_3));
	
	//ex14
	printf("EX14\n");
	char ex14_1[] = "LDSLDSADSADAS";
	char ex14_2[] = "salusadr40fjcs;dJ:A";
	char ex14_3[] = "\0";
	printf("1 = %d\n", ft_str_is_uppercase(ex14_1));
	printf("0 = %d\n", ft_str_is_uppercase(ex14_2));
	printf("1 = %d\n", ft_str_is_uppercase(ex14_3));
	
	//ex15
	printf("EX15\n");
	char ex15_1[] = " LDSLDSAsdasdDSADAS";
	char ex15_2[] = "salusadr4\t0fjc\n;dJ:A";
	char ex15_3[] = "\0";
	printf("1 = %d\n", ft_str_is_printable(ex15_1));
	printf("0 = %d\n", ft_str_is_printable(ex15_2));
	printf("1 = %d\n", ft_str_is_printable(ex15_3));
	return (0);
}
