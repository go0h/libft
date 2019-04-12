#include "my_header.h"

void    ft_del_mem(void *data, size_t size)
{
    size *= 0;
    free(data);
    data = NULL;
}

void	ft_iter_list(t_list *elem)
{
	char *s;

	s = (char*)elem->content;
	while (*s)
	{
		*s = ft_toupper((int)*s);
		++s;
	}
}

t_list	*ft_map_list(t_list *elem)
{
	t_list *new;
	size_t i = 0;

	char *s = (char*)malloc(sizeof(char*) * elem->content_size);
	char *s1 = (char*)elem->content;
	while (s1[i])
	{
		s[i] = (char)ft_tolower((int)s1[i]);
		++i;
	}
	new = ft_lstnew((void*)s, elem->content_size);
	if (new == NULL)
		return (NULL);
	return (new);
}

int			main(void)
{
	size_t i;
	size_t len;

    //LSTNEW
	printf("\n52_LSTNEW\n");
	char *s1 = ft_strdup("Privet, kak dela?");
	len = ft_strlen(s1);
	t_list *list = ft_lstnew(s1, len);
	t_list *list1 = ft_lstnew(NULL, len);
	printf("SIZEOF T_LIST = %zu\n", sizeof(t_list));
	printf("SIZEOF VOID* = %zu\n", sizeof(void*));
	printf("SIZEOF SIZE_T = %zu\n", sizeof(size_t));
	printf("SIZEOF T_LIST* = %zu\n", sizeof(t_list*));
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

    //LSTDEL
	printf("\n54_LSTDEL\n");
	s1 = ft_strdup("Privet, kak dela?");
	i = 0;
	len = 5;
	t_list *begin = ft_lstnew(s1, ft_strlen(s1));
	t_list *end = ft_lstnew(s1, ft_strlen(s1));
	begin->next = end;
	while (i < len)
	{		
		end->next = ft_lstnew(s1, ft_strlen(s1));
		end = end->next;
		i++;
	}
	end = begin;
	while (end != NULL)
	{		
		printf("%s\n", (char*)end->content);
		end = end->next;
	}
	end = begin;
	ft_lstdel(&begin, &ft_del_mem);
	if (begin == NULL)
	    printf("CHAINED LIST IS FREEED!\n");
	else
	{
	    printf("CHAINED LIST IS NOT FREEED!\n");
        printf("%s\nlen = %zu\n", (char*)begin->content, begin->content_size);
	}
    
	//LSTADD
	printf("\n55_LSTADD\n");
	i = 0;
	len = 5;
	begin = ft_lstnew(s1, ft_strlen(s1));
	end = ft_lstnew(s1, ft_strlen(s1));
	begin->next = end;
	while (i < len)
	{		
		end->next = ft_lstnew(s1, ft_strlen(s1));
		end = end->next;
		i++;
	}
	end = begin;
	while (end != NULL)
	{		
		printf("%s\n", (char*)end->content);
		end = end->next;
	}
	t_list *added = ft_lstnew("ADDED LIST!", ft_strlen(s1));
	ft_lstadd(&begin, added);
	end = begin;
	while (end != NULL)
	{		
		printf("%s\n", (char*)end->content);
		end = end->next;
	}
	
	//LSTUTER
	printf("\n56_LSTITER\n");
	end = begin;
	ft_lstiter(end, &ft_iter_list);
	end = begin;
	while (end != NULL)
	{		
		printf("%s\n", (char*)end->content);
		end = end->next;
	}
	
	//LSTMAP
	printf("\n56_LSTMAP\n");
	end = begin;
	t_list *map_ls = ft_lstmap(end, &ft_map_list);
	end = map_ls;
	while (end != NULL)
	{		
		printf("%s\n", (char*)end->content);
		end = end->next;
	}
	end = begin;
	while (end != NULL)
	{		
		printf("%s\n", (char*)end->content);
		end = end->next;
	}
    return (0);
}
