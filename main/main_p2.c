#include "my_header.h"

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
	char *str_del = (char*)ft_memalloc(sizeof(char) * len);
	printf("MEMORY   ALLOCATED\n");
	ft_strdel(&str_del);
	if (memdel == NULL)
		printf("STRDEL : OK\n");
	else
		printf("STRDEL : FAIL\n");
     return (0);
}
