#include "headerfile.h"

void	free_node(Contact *ptr)
{
	Contact	*current;
	
	current = head;
	while (current)
	{
		if (current == ptr)
		{
			printf("Contact %s removed", current->name);
			reset_pointers_before_removal(ptr);
			free(ptr);
		}
		current = current->next;
	}
}

void	free_list(void)
{
	Contact *current;
	Contact	*temp;
	current = head;

	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	head = NULL;
}