
#include "libft.h"

t_list  *ft_lstnew(void const *content, size_t content_size)
{
    t_list *newl;

    if ((newl = (t_list*)malloc(sizeof(t_list))) == NULL)
        return (NULL);
    if (content != NULL)
    {
        newl->content = (void*)content;
        newl->content_size = content_size;
    }
    else
    {
        newl->content = NULL;
        newl->content_size = 0;
    }
    return (newl);
}