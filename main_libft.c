/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 10:24:25 by astripeb          #+#    #+#             */
/*   Updated: 2019/04/06 11:30:46 by astripeb         ###   ########.fr       */
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
	printf("%d = %d\n", atoi("2147483647"), ft_atoi("2147483647"));
	printf("%d = %d\n", atoi("-2147483648"), ft_atoi("-2147483648"));
	printf("%d = %d\n", atoi("-21474836489"), ft_atoi("-21474836489"));

	//STRCPY
	printf("\nSTRCPY\n");
	char str4[] = "alloha";
	char str5[] = "hi";
	char str6[] = "alloha";
	char str7[] = "hi";
	char *str8;
	str8 = strcpy(str4, str5);
	printf("standart: %s == %s == %s\n", str4, str5, str8);
	str8 = ft_strcpy(str6, str7);
	printf("testing:  %s == %s == %s\n", str6, str7, str8);

	//STRNCPY
	size_t l = 10;
	printf("\nSTRNCPY\n");
	char str9[] = "Privet, kak dela?";
	char str10[15];
	char str11[15];
	char *str12;
	str12 = strncpy(str10, str9, l);
	printf("standart: %s\t%s = %s\n", str9, str10, str12);
	str12 = ft_strncpy(str11, str9, l);
	printf("testing:  %s\t%s = %s\n", str9, str11, str12);

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

	//STRDUP
	printf("\nSTRDUP\n");
	char s4[] = "Privet, kak dela?";
	char *s5;
	char *s6;
	s5 = strdup(s4);
	s5[0] = 'Z';
	s6 = strdup(s4);
	s6[0] = 'Z';
	printf("sys  = %s == %s\n", s4, s5);
	printf("work = %s == %s\n", s4, s6);


	//STRSTR
	printf("\nSTRSTR\n");
	char ex05_1[] = "12345123456";
	char ex05_2[] = "456";
	char *ex05_3;
	ex05_3 = strstr(ex05_1, ex05_2);
	printf("standart: %s\t%s\n", ex05_1, ex05_3);
	char ex05_4[] = "12345123456";
	char ex05_5[] = "456";
	ex05_3 = ft_strstr(ex05_4, ex05_5);
	printf("testing:  %s\t%s\n", ex05_4, ex05_3);


	//STRNSTR
	printf("\nSTRNSTR\n");
	size_t k = 100;
	char strnstr1[] = "12345123456";
	char strnstr2[] = "456";
	char *strnstr3;
	strnstr3 = strnstr(strnstr1, strnstr2, k);
	printf("standart: %s\t%s\n", strnstr1, strnstr3);
	char strnstr4[] = "12345123456";
	char strnstr5[] = "456";
	strnstr3 = ft_strnstr(strnstr4, strnstr5, k);
	printf("testing:  %s\t%s\n", strnstr4, strnstr3);
	
	
	//STRCAT
	printf("\nSTRCAT\n");
	char *strcat1 = (char*)malloc(sizeof(char) * 100);
	char *strcat2 = (char*)malloc(sizeof(char) * 100);
	const char strcat3[] = "Privet,";
	const char strcat4[] = " kak";
	const char strcat5[] = " dela?";
	strcat1 = strcat(strcat1, strcat3);
	strcat1 = strcat(strcat1, strcat4);
	strcat1 = strcat(strcat1, strcat5);
	strcat2 = ft_strcat(strcat2, strcat3);
	strcat2 = ft_strcat(strcat2, strcat4);
	strcat2 = ft_strcat(strcat2, strcat5);
	printf("standart: %s\n", strcat1);
	printf("testing:  %s\n", strcat2);
	free(strcat1);
	free(strcat2);
	
	
	//STRNCAT
	printf("\nSTRNCAT\n");
	l = 3;
	const char strncat00[] = "STRNCAT";
	const char strncat3[] = "Privet,";
	const char strncat4[] = " kak ";
	const char strncat5[] = "dela?";
	char *strncat1 = (char*)malloc(sizeof(char) * 100);
	char *strncat2 = (char*)malloc(sizeof(char) * 100);
	strncat1 = strncat(strncat1, strncat3, l);
	strncat1 = strncat(strncat1, strncat4, l);
	strncat1 = strncat(strncat1, strncat5, l);
	strncat2 = strncat(strncat2, strncat3, l);
	strncat2 = strncat(strncat2, strncat4, l);
	strncat2 = strncat(strncat2, strncat5, l);
	printf("standart: %s\n", strncat1);
	printf("testing:  %s\n", strncat2);
	free(strncat1);
	free(strncat2);


	//STRLCAT
	printf("\nSTRLCAT\n");
	l = 100;
	const char strLcat00[] = "STRLCAT";
	char *strlcat1 = (char*)malloc(l);
	char *strlcat2 = (char*)malloc(l);
	const char strlcat3[] = "Privet,";
	const char strlcat4[] = " kak ";
	const char strlcat5[] = "dela?";
	printf("standard: 1 = %zu, 2 = %zu, 3 = %zu: %s\n", strlcat(strlcat1, strlcat3, l),\
			strlcat(strlcat1, strlcat4, l), strlcat(strlcat1, strlcat5, l), strlcat1);
	printf("testing:  1 = %zu, 2 = %zu, 3 = %zu: %s\n", ft_strlcat(strlcat2, strlcat3, l),\
			ft_strlcat(strlcat2, strlcat4, l), ft_strlcat(strlcat2, strlcat5, l), strlcat2);
	
	return (0);
}
