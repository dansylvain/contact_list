#include "headerfile.h"

void	swap_nodes(Contact *node1, Contact *node2)
{
	Contact	*current;
	Contact	*previous;

	if (node1 == NULL || node1->next == NULL)
		return;

	previous = head;
	node2 = node1->next;
	while (previous && previous->next != node1)
	{
		previous = previous->next;
	}
	if (node1 != head)
		previous->next = node2;
	else
		head = node2;

	node1->next = node2->next;
	node2->next = node1;
}

void	sort_list(int	(sort_func)(Contact *current))
{
	Contact *current;
	int	list_is_sorted;
	
	list_is_sorted = 0;
	while (!list_is_sorted)
	{
		list_is_sorted = 1;
		current = head;
		while (current && current->next)
		{
			if (sort_func(current))
			{
				reset_pointers_for_swapping(current, current->next);
				list_is_sorted = 0;
			}
			current= current->next;
		}
	}
	printf("List sorted\n");
}