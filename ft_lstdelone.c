
#include "libft.h"

void        ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
    t_list *dell;

    if (alst != NULL)
    {
        dell = *alst;
        if (dell != NULL)
        {
            del(dell->content, dell->content_size);
            dell->next = NULL;
            free(*alst);
            *alst = NULL;
        }
        alst = NULL;
    }
}