/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 10:24:25 by astripeb          #+#    #+#             */
/*   Updated: 2019/04/04 21:41:39 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

int			main(void)
{
	int n;
	
	//ATOI
	printf("\nATOI\n");
	printf("%d = %d\n", atoi("dwf24ss"), ft_atoi("dwf24ss"));
	printf("%d = %d\n", atoi("--324ss"), ft_atoi("--324ss"));
	printf("%d = %d\n", atoi("-324ss"), ft_atoi("-324ss"));
	printf("%d = %d\n", atoi("00024"), ft_atoi("00024"));
	printf("%d = %d\n", atoi("\t\n+213s5"), ft_atoi("\t\n+213s5"));
	printf("%d = %d\n", atoi("\b\t\n-213s5"), ft_atoi("\b\t\n-213s5"));
	printf("%d = %d\n", atoi("    99999"), ft_atoi("    99999"));
	printf("%d = %d\n", atoi("999999999999"), ft_atoi("999999999999"));
	
	/*//STRCPY
	printf("\nSTRCPY\n");
	char str4[] = "alloha";
	char str5[] = "hi";
	char *str6;
	//str6 = ft_strcpy(str5, str4);
	str6 = ft_strcpy(str5, str4);
	printf("%s == %s == %s\n", str4, str5, str6);

	//STRNCPY
	int n;
	n = 10;
	printf("\nSTRNCPY\n");
	char str_ex04_1[] = "Privet, kak dela?";
	char str_ex04_2[15];
	char *str_ex04_3;
	str_ex04_3 = ft_strncpy(str_ex04_2, str_ex04_1, n);
	printf("%s = %s\n", str_ex04_2, str_ex04_3);
	puts(str_ex04_1);

	//STRSTR
	printf("\nSTRSTR\n");
	char ex05_1[] = "aaaaManaaaa";
	char ex05_2[] = "aMan";
	char *ex05_3;
	ex05_3 = strstr(ex05_1, ex05_2);
	printf("%s\n%s\n", ex05_1, ex05_3);
	char ex05_4[] = "aaaaManaaaa";
	char ex05_5[] = "aMan";
	ex05_3 = ft_strstr(ex05_4, ex05_5);
	printf("%s\n%s\n", ex05_4, ex05_3);*/

	//STRCMP
	printf("\nSTRCMP\n");
	char ex06_1[] = "Hello";
	char ex06_2[] = "Hello";
	char ex06_3[] = "Hi";
	printf("%d = %d\n", strcmp(ex06_1, ex06_2), ft_strcmp(ex06_1, ex06_2));
	printf("%d = %d\n", strcmp(ex06_3, ex06_2), ft_strcmp(ex06_3, ex06_2));
	printf("%d = %d\n", strcmp(ex06_1, ex06_3), ft_strcmp(ex06_1, ex06_3));
	
	//STRNCMP
	printf("\nSTRNCMP\n");
	char ex07_1[] = "Privet kak dela?";
	char ex07_2[] = "Zdarov kak dela?";
	char ex07_3[] = "Privet kak dela?";
	n = 6;
	printf("%d = %d\n", strncmp(ex07_1, ex07_2, n), ft_strncmp(ex07_1, ex07_2, n));
	printf("%d = %d\n", strncmp(ex07_2, ex07_1, n), ft_strncmp(ex07_2, ex07_1, n));
	printf("%d = %d\n", strncmp(ex07_1, ex07_3, n), ft_strncmp(ex07_1, ex07_3, n));

	//TOUPPER
	printf("\nTOUPPER\n");
	char to_up1[] = "privet_kak_dela?";
	int i = 0;
	while (to_up1[i] != '\0')
	{
		to_up1[i] = toupper(to_up1[i]);
		++i;
	}
	printf("%s\n", to_up1);
	i = 0;
	while (to_up1[i] != '\0')
	{
		to_up1[i] = tolower(to_up1[i]);
		++i;
	}
	i = 0;
	while (to_up1[i] != '\0')
	{
		to_up1[i] = ft_toupper(to_up1[i]);
		++i;
	}
	printf("%s\n", to_up1);
	
	//TOLOWER
	printf("\nTOLOWER\n");
	i = 0;
	while (to_up1[i] != '\0')
	{
		to_up1[i] = tolower(to_up1[i]);
		++i;
	}
	printf("%s\n", to_up1);
	i = 0;
	while (to_up1[i] != '\0')
	{
		to_up1[i] = toupper(to_up1[i]);
		++i;
	}
	i = 0;
	while (to_up1[i] != '\0')
	{
		to_up1[i] = ft_tolower(to_up1[i]);
		++i;
	}
	printf("%s\n", to_up1);

	//ISALPHA
	printf("\nISALPHA\n");
	int a = 65;
	int b = 97;
	int c = 13;
	printf("%d = %d\n", isalpha(a), ft_isalpha(a));
	printf("%d = %d\n", isalpha(b), ft_isalpha(b));
	printf("%d = %d\n", isalpha(c), ft_isalpha(c));

	//ISDIGIT
	printf("\nISDIGIT\n");
	a = 48;
	b = 57;
	c = 30;
	printf("%d = %d\n", isdigit(a), ft_isdigit(a));
	printf("%d = %d\n", isdigit(b), ft_isdigit(b));
	printf("%d = %d\n", isdigit(c), ft_isdigit(c));
	
	//ISPRINT
	printf("\nISPRINT\n");
	a = 32;
	b = 126;
	c = 127;
	int d = 13;
	printf("%d = %d\n", isprint(a), ft_isprint(a));
	printf("%d = %d\n", isprint(b), ft_isprint(b));
	printf("%d = %d\n", isprint(c), ft_isprint(c));
	printf("%d = %d\n", isprint(d), ft_isprint(d));
	
	//STRLEN
	printf("\nSTRLEN\n");
	const char s1[] = "Privet, kak dela?";
	const char s2[] = "\0";
	const char s3[] = "";
	printf("%zu = %zu\n", strlen(s1), ft_strlen(s1));
	printf("%zu = %zu\n", strlen(s2), ft_strlen(s2));
	printf("%zu = %zu\n", strlen(s3), ft_strlen(s3));
	return (0);
}
