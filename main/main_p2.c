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

int			main(void)
{
	//int n;
	size_t i;
	size_t j;
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
	j = 0;
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
	free(str_iteri);
	
	//STRMAP
	printf("\n35_STRMAP\n");
	i = 0;
	char *str_map;
	printf("input:  %s\n", "Privet, kak dela?");
	str_map = ft_strmap("Privet, kak dela?", &f_map);	
	printf("output: %s\n", str_map);
	return (0);
}
