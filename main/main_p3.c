#include "my_header.h"

void    ft_del_mem(void *data, size_t size)
{
    size *= 0;
    free(data);
    data = NULL;
}

int			main(void)
{
	//size_t i;
	size_t len;

    //LSTNEW
	printf("\n52_LSTNEW\n");
	char *s1 = ft_strdup("Privet, kak dela?");
	len = ft_strlen(s1);
	t_list *list = ft_lstnew((void*)s1, len);
	t_list *list1 = ft_lstnew(NULL, len);
	printf("%s\nlen = %zu\n", (char*)list->content, list->content_size);
	printf("%s\nlen = %zu\n", (char*)list1->content, list1->content_size);

    //LSTDELONE
	printf("\n53_LSTDELONE\n");
	ft_lstdelone(&list, &ft_del_mem);
	ft_lstdelone(&list1, &ft_del_mem);
	if (list == NULL)
	    printf("LIST ONE FREEED!\n");
	else
	{
	    printf("LIST ONE IS NOT FREEED!\n");
        printf("%s\nlen = %zu\n", (char*)list->content, list->content_size);
	}
	if (list1 == NULL)
	    printf("LIST TWO FREEED!\n");
	else
	{
	    printf("LIST TWO IS NOT FREEED!\n");
	     printf("%s\nlen = %zu\n", (char*)list1->content, list1->content_size);
	}
    return (0);
}
