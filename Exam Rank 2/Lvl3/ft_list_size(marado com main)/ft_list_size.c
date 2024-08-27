#include <stdio.h>
#include <stdlib.h>

typedef struct    s_list
{
	struct s_list *next;
	int          data;
}                 t_list;

int	ft_list_size(t_list *begin_list)
{
	int nodes = 0;

	while(begin_list)
	{
		begin_list = begin_list->next;
		nodes++;
	}
	return(nodes);
}

int main()
{
	t_list *nodo = malloc(sizeof(struct s_list));
	nodo->data = 2;
	nodo->next = malloc(sizeof(struct s_list));
	nodo->next->data = 3;
	nodo->next->next = NULL;
	printf("%d\n", ft_list_size(nodo));
}