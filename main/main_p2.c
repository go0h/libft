#include "my_header.h"

void	f_iter(char *s)
{
	//printf("%s\n", s);
	*s = 'a';
}

void	f_iteri(unsigned int i, char *s)
{
	s[i] = 'a';
}

char	f_map(char c)
{
	c = '0';
	return (c);
}

char	f_mapi(unsigned int i, char c)
{
	i = 0;
	c = 'a';
	return (c + i);
}

void	ft_printarr(char **s)
{
	size_t i;

	i = 0;
	while (s[i])
	{
		printf("|%s|", s[i]);
		++i;
	}
}

int			main(void)
{
	//int n;
	size_t i;
	size_t len;

	//MEMALLOC
	printf("\n29_MEMALLOC\n");
	len = 15;
	i = 0;
	char *memes = (char*)ft_memalloc(len);
	printf("0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n");
	while (i < len)
	{
		printf("%d ", memes[i]);
		++i;
	}
	free(memes);
	printf("\n");

	//MEMDEL
	printf("\n30_MEMDEL\n");
	i = 5;
	len = 3;
	//size_t j = 0;
	char *memdel = (char*)ft_memalloc(sizeof(char) * len);
	printf("MEMORY   ALLOCATED\n");
	ft_memdel((void**)&memdel);
	if (memdel == NULL)
		printf("MEMDEL : OK\n");
	else
		printf("MEMDEL : FAIL\n");

	//STRNEW
	printf("\n30_STRNEW\n");
	len = 15;
	i = 0;
	char *str_new = ft_strnew(len);
	printf("0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n");
	while (i < len)
	{
		printf("%d ", str_new[i]);
		++i;
	}
	free(str_new);
	printf("\n");

	//STRDEL
	printf("\n31_STRDEL\n");
	char *str_del = (char*)malloc(sizeof(char) * len);
	printf("MEMORY   ALLOCATED\n");
	ft_strdel(&str_del);
	if (memdel == NULL)
		printf("STRDEL : OK\n");
	else
		printf("STRDEL : FAIL\n");

	//STRCLR
	printf("\n32_STRCLR\n");
	i = 0;
	char *str_clr = ft_strdup("Privet kak dela?");
	printf("input:  %s\n", str_clr);
	len = ft_strlen(str_clr);
	ft_strclr(str_clr);
	printf("output: ");
	while (i < len)
	{
		printf("%d", str_clr[i]);
		++i;
	}
	free(str_clr);
	printf("\n");

	//STRITER
	printf("\n33_STRITER\n");
	i = 0;
	char *str_iter = strdup("Privet kak dela?");
	printf("input:  %s\n", str_iter);
	ft_striter(str_iter, &f_iter);
	printf("output: %s\n", str_iter);
	free(str_iter);

	//STRITERI
	printf("\n34_STRITERI\n");
	i = 0;
	char *str_iteri = strdup("Privet kak dela?");
	printf("input:  %s\n", str_iteri);
	ft_striteri(str_iteri, &f_iteri);
	printf("output: %s\n", str_iteri);
	//free(str_iteri);

	//STRMAP
	printf("\n35_STRMAP\n");
	i = 0;
	char *str_map;
	printf("input:  %s\n", "Privet, kak dela?");
	str_map = ft_strmap("Privet, kak dela?", &f_map);
	printf("output: %s\n", str_map);

	//STRMAPI
	printf("\n36_STRMAPI\n");
	i = 0;
	char *str_mapi;
	printf("input:  %s\n", "Privet, kak dela?");
	str_mapi = ft_strmapi("Privet, kak dela?", &f_mapi);
	printf("output: %s\n", str_mapi);
	//free(str_mapi);

	//STREQU
	printf("\n37_STREQU\n");
	char *str_equ1;
	char *str_equ2;
	char *str_equ3;
	str_equ1 = ft_strdup("Privet, kak dela?");
	str_equ2 = ft_strdup("Privet, kak dela?");
	str_equ3 = ft_strdup("Privet, tak dela!");
	printf("1 = %d\n", ft_strequ(str_equ1, str_equ2));
	printf("0 = %d\n", ft_strequ(str_equ1, str_equ3));
	printf("0 = %d\n", ft_strequ(str_equ1, NULL));
	printf("0 = %d\n", ft_strequ(NULL, NULL));

	//STRNEQU
	printf("\n38_STRNEQU\n");
	len = 15;
	char *strnequ = ft_strdup("Privet");
	printf("1 = %d\n", ft_strnequ(str_equ1, str_equ2, len));
	printf("0 = %d\n", ft_strnequ(str_equ1, str_equ3, len));
	printf("0 = %d\n", ft_strnequ(str_equ1, NULL, len));
	printf("0 = %d\n", ft_strnequ(NULL, NULL, len));
	printf("0 = %d\n", ft_strnequ(str_equ1, str_equ3, 100));
	printf("1 = %d\n", ft_strnequ(str_equ1, str_equ2, len));
	printf("0 = %d\n", ft_strnequ(strnequ, str_equ1, 100));

	//STRSUB
	printf("\n39_STRSUB\n");
	len = 15;
	char *str_sub = ft_strdup("Privet, kak dela?");
	printf("input:	  %s\n", str_sub);
	printf("output1:  %s\n", ft_strsub(str_sub, 0, 7));
	printf("output2:  %s\n", ft_strsub(str_sub, 8, 3));
	printf("output3:  %s\n", ft_strsub(str_sub, 12, 5));

	//STRJOIN
	printf("\n40_STRJOIN\n");
	printf("%s\n", ft_strjoin("Privet, ", "kak dela?"));
	printf("kak dela? == %s\n", ft_strjoin("", "kak dela?"));
	printf("Privet, == %s\n", ft_strjoin("Privet, ", ""));
	printf("0%s\n", ft_strjoin("",  ""));

	//STRTRIM
	printf("\n41_STRTRIM\n");
	printf("|%s|\n", ft_strtrim("\t\n Privet, kak dela?\t\n   "));
	printf("|%s|\n", ft_strtrim("Privet, kak dela?"));
	printf("|%s|\n", ft_strtrim("     "));
	printf("|%s|\n", ft_strtrim(""));

	//STRSPLIT
	printf("\n42_STRSPLIT\n");
	char **split1 = ft_strsplit("*****Privet,***kak**dela?***", '*');
	ft_printarr(split1);
	printf("\n");
	char **split2 = ft_strsplit("*****Privet,***kak**dela?***", '-');
	ft_printarr(split2);
	printf("\n");
	char **split3 = ft_strsplit("******", '*');
	printf("0 = ");
	ft_printarr(split3);
	printf("\n");

	//ITOA
	printf("\n43_ITOA\n");
	printf("1 = %s\n", ft_itoa(1));
	printf("-1 = %s\n", ft_itoa(-1));
	printf("0 = %s\n", ft_itoa(0));
	printf("-100 = %s\n", ft_itoa(-100));
	printf("100 = %s\n", ft_itoa(100));
	printf("1234567890 = %s\n", ft_itoa(1234567890));
	printf("-1234567890 = %s\n", ft_itoa(-1234567890));
	printf("2147483647 = %s\n", ft_itoa(2147483647));
	printf("-2147483648 = %s\n", ft_itoa(-2147483648));

	//PUTCHAR
	printf("\n44_PUTCHAR\n");
	ft_putchar('c');
	ft_putchar('\n');

	ft_putchar('\200');
	ft_putchar('\n');

	ft_putchar('\0');
	ft_putchar('\n');

	//PUTSTR
	printf("\n45_PUTSTR\n");
	ft_putstr("Privet, kak dela?\n");

	//PUTENDL
	printf("\n46_PUTENDL\n");
	ft_putendl("Privet, kak dela?");
	ft_putendl("");

	//PUTNBR
	printf("\n47_PUTNBR\n");
	ft_putstr(" 1 = ");
	ft_putnbr(1);
	ft_putchar('\n');

	ft_putstr("-1 = ");
	ft_putnbr(-1);
	ft_putchar('\n');

	ft_putstr(" 0 = ");
	ft_putnbr(0);
	ft_putchar('\n');

	ft_putstr(" 1234567890 = ");
	ft_putnbr(1234567890);
	ft_putchar('\n');

	ft_putstr("-1234567890 = ");
	ft_putnbr(-1234567890);
	ft_putchar('\n');

	ft_putstr(" 2147483647 = ");
	ft_putnbr(2147483647);
	ft_putchar('\n');

	ft_putstr("-2147483648 = ");
	ft_putnbr(-2147483648LL);
	ft_putchar('\n');

	//PUTCHAR_FD
	printf("\n48_PUTCHAR_FD\n");
	ft_putchar_fd('c', 1);
	ft_putchar_fd('\n', 1);

	ft_putchar_fd('\200', 1);
	ft_putchar_fd('\n', 1);

	ft_putchar_fd('\0', 1);
	ft_putchar_fd('\n', 1);

	//PUTSTR_FD
	printf("\n49_PUTSTR_FD\n");
	ft_putstr_fd("Privet, kak dela?\n", 1);

	//PUTENDL_FD
	printf("\n50_PUTENDL_FD\n");
	ft_putendl_fd("Privet, kak dela?", 1);
	ft_putendl_fd("", 1);

	//PUTNBR_FD
	printf("\n51_PUTNBR_FD\n");
	ft_putstr_fd(" 1 = ", 1);
	ft_putnbr_fd(1, 1);
	ft_putchar_fd('\n', 1);

	ft_putstr_fd("-1 = ", 1);
	ft_putnbr_fd(-1, 1);
	ft_putchar_fd('\n', 1);

	ft_putstr_fd(" 0 = ", 1);
	ft_putnbr_fd(0, 1);
	ft_putchar_fd('\n', 1);

	ft_putstr_fd(" 1234567890 = ", 1);
	ft_putnbr_fd(1234567890, 1);
	ft_putchar_fd('\n', 1);

	ft_putstr_fd("-1234567890 = ", 1);
	ft_putnbr_fd(-1234567890, 1);
	ft_putchar_fd('\n', 1);

	ft_putstr_fd(" 2147483647 = ", 1);
	ft_putnbr_fd(2147483647, 1);
	ft_putchar_fd('\n', 1);

	ft_putstr_fd("-2147483648 = ", 1);
	ft_putnbr_fd(-2147483648, 1);
	ft_putchar_fd('\n', 1);
	
	//STRSPLIT_SPACE
	printf("\nEXTRA_STRSPLIT_SPACE\n");
	char **split4 = ft_strsplit_sp("\n\tPrivet,        \n\v   kak dela? ");
	ft_printarr(split4);
	printf("\n");
	char **split5 = ft_strsplit_sp("    \fPrivet,\t\t\fkak\n\\\ndela?\r\r\r??\n");
	ft_printarr(split5);
	printf("\n");
	char **split6 = ft_strsplit_sp("\t\n\va\f\raaaaaaa");
	printf("0 = ");
	ft_printarr(split6);
	printf("\n");
	return (0);
}
