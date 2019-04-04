/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 10:24:25 by astripeb          #+#    #+#             */
/*   Updated: 2019/04/04 20:27:24 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

int			main(void)
{
	int n;
	
	//ATOI
	printf("ATOI\n");
	printf("%d = %d\n", atoi("dwf24ss"), ft_atoi("dwf24ss"));
	printf("%d = %d\n", atoi("--324ss"), ft_atoi("--324ss"));
	printf("%d = %d\n", atoi("-324ss"), ft_atoi("-324ss"));
	printf("%d = %d\n", atoi("00024"), ft_atoi("00024"));
	printf("%d = %d\n", atoi("\t\n+213s5"), ft_atoi("\t\n+213s5"));
	printf("%d = %d\n", atoi("\b\t\n-213s5"), ft_atoi("\b\t\n-213s5"));
	printf("%d = %d\n", atoi("    99999"), ft_atoi("    99999"));
	printf("%d = %d\n", atoi("999999999999"), ft_atoi("999999999999"));
	
	/*//STRCPY
	printf("STRCPY\n");
	char str4[] = "alloha";
	char str5[] = "hi";
	char *str6;
	//str6 = ft_strcpy(str5, str4);
	str6 = ft_strcpy(str5, str4);
	printf("%s == %s == %s\n", str4, str5, str6);

	//STRNCPY
	int n;
	n = 10;
	printf("STRNCPY\n");
	char str_ex04_1[] = "Privet, kak dela?";
	char str_ex04_2[15];
	char *str_ex04_3;
	str_ex04_3 = ft_strncpy(str_ex04_2, str_ex04_1, n);
	printf("%s = %s\n", str_ex04_2, str_ex04_3);
	puts(str_ex04_1);

	//STRSTR
	printf("STRSTR\n");
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
	printf("STRCMP\n");
	char ex06_1[] = "Hello";
	char ex06_2[] = "Hello";
	char ex06_3[] = "Hi";
	printf("%d = %d\n", strcmp(ex06_1, ex06_2), ft_strcmp(ex06_1, ex06_2));
	printf("%d = %d\n", strcmp(ex06_3, ex06_2), ft_strcmp(ex06_3, ex06_2));
	printf("%d = %d\n", strcmp(ex06_1, ex06_3), ft_strcmp(ex06_1, ex06_3));
	
	//STRNCMP
	printf("STRNCMP\n");
	char ex07_1[] = "Privet kak dela?";
	char ex07_2[] = "Zdarov kak dela?";
	char ex07_3[] = "Privet kak dela?";
	n = 6;
	printf("%d = %d\n", strncmp(ex07_1, ex07_2, n), ft_strncmp(ex07_1, ex07_2, n));
	printf("%d = %d\n", strncmp(ex07_2, ex07_1, n), ft_strncmp(ex07_2, ex07_1, n));
	printf("%d = %d\n", strncmp(ex07_1, ex07_3, n), ft_strncmp(ex07_1, ex07_3, n));

	//TOUPPER
	printf("TOUPPER\n");
	printf("%s == %d\n", ex07_1, ft_toupper(ex07_1));
	
	//TOLOWER
	printf("TOLOWER\n");
	printf("%s == %d\n", ex07_1, ft_tolower(ex07_1));

	//ISALPHA
	printf("ISALPHA\n");
	char ex11_1[] = "salutcommenttuvas";
	char ex11_2[] = "salut c1omment tu vas ";
	char ex11_3[] = "\0";
	printf("%d = %d\n", isalpha(ex11_1), ft_isalpha(ex11_1));
	printf("%d = %d\n", isalpha(ex11_1), ft_isalpha(ex11_2));
	printf("%d = %d\n", isalpha(ex11_1), ft_isalpha(ex11_3));

	//ISDIGIT
	printf("ISDIGIT\n");
	char ex12_1[] = "1111357809867";
	char ex12_2[] = "salut c1omment tu vas ";
	char ex12_3[] = "\0";
	printf("%d = %d\n", isdigit(ex12_1), ft_isdigit(ex12_1));
	printf("%d = %d\n", isdigit(ex12_1), ft_isdigit(ex12_2));
	printf("%d = %d\n", isdigit(ex12_1), ft_isdigit(ex12_3));
	
	//ISPRINT
	printf("ISPRINT\n");
	char ex15_1[] = " LDSLDSAsdasdDSADAS";
	char ex15_2[] = "salusadr4\t0fjc\n;dJ:A";
	char ex15_3[] = "\0";
	printf("%d = %d\n", isprint(ex15_1), ft_isprint(ex15_1));
	printf("%d = %d\n", isprint(ex15_1), ft_isprint(ex15_2));
	printf("%d = %d\n", isprint(ex15_1), ft_isprint(ex15_3));
	return (0);
}
