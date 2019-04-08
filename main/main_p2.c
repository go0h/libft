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
	printf("\n");

	//MEMDEL
	printf("\n30_MEMDEL\n");
	i = 5;
	len = 10;
	j = 0;
	char **memdel = (char**)malloc(sizeof(char*) * i);
	while (j < i)
	{
		memdel[j] = strdup("Privet");
		printf("%s\n", memdel[j]);
		++j;
	}
	ft_memdel((void**)memdel);
	if (memdel != NULL)
		printf("MEMDEL : OK\n");
	else
		printf("MEMDEL : FAIL\n");


     return (0);
}