#include <stdlib.h>
//La structure est donnee dans le subject.txt
//Il faut mettre sa dans ft_list.h
//#include "ft_list.h"
typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

//Applique la fonction (*f) a chaque element 'data' de la liste t_list.
void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list *list_ptr = begin_list;

	while (list_ptr)
	{
		(*f)(list_ptr->data);
		list_ptr = list_ptr -> next;
	}
}