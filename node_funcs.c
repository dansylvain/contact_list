#include "headerfile.h"

int	get_contacts_qtty(void)
{
	Contact *current;
	
	current = head;
	int	i;
	i = 0;
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
}

void	create_contact_node(char *name, char *email, char *stone_skipping_record, char *favourite_pokemon)
{
	Contact	*new_contact;

	new_contact = (Contact *)malloc(sizeof(Contact));
	if (!new_contact)
	{
		printf("Could not allocate memory for the new contact\n");
		return;
	}
	strncpy(new_contact->name, name, 20);
	strncpy(new_contact->email, email, 30);
	strncpy(new_contact->stone_skipping_record, stone_skipping_record, 9);
	strncpy(new_contact->favourite_pokemon, favourite_pokemon, 14);
	new_contact->next = NULL;
	new_contact->previous = NULL;
	
	if (!head)
	{
		head = new_contact;
		tail = new_contact;
	}
	else
	{
		Contact	*current;
		Contact *previous;
		previous = NULL;
		current = head;
		while (current->next)
		{
			previous = current;
			current = current->next;
		}
		current->next = new_contact;
		tail = new_contact;
		new_contact->previous = current;
	}
}

Contact	*get_node(char	*name)
{
	Contact	*current;
	int	node_was_found;

	current = head;
	while (current)
	{
		if (!strncmp(current->name, name, 20))
			return (current);
		current = current->next;
	}
	return (NULL);
}

void	reset_pointers_before_removal(Contact *ptr)
{
	if (ptr == head)
	{
		ptr->next->previous = NULL;
		head = ptr->next;
		return;
	}
	if (ptr == tail)
	{
		ptr->previous->next = NULL;
		tail = ptr->previous;
		return;
	}
	ptr->next->previous = ptr->previous;
	ptr->previous->next = ptr->next;
}

void	reset_pointers_for_swapping(Contact *node1, Contact *node2)
{
	if (node1 == head)
	{
		node2->previous = NULL;
		head = node2;
	}
	else
	{
		node1->previous->next = node2;
		node2->previous = node1->previous;
	}
	if (node2 == tail)
	{
		node1->next = NULL;
		tail = node1;
	}
	else	
	{
		node1->next = node2->next;
		node1->next->previous = node1;
	}
	node1->previous = node2;
	node2->next = node1;
	
}