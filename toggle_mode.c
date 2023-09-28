#include "headerfile.h"


void	traverse_list(Contact *node)
{
	char	command;
	Contact *current;

	current = node;
	
	printf("\r>>> %-23s", current->name);
	printf("   a - previous / z - next / q - quit >>> ");
	scanf(" %c", &command);
	if (command == 'a')
	{
		if (current != head)
			current = current->previous;
		traverse_list(current);
	}
	else if (command == 'z')
	{
		if (current != tail)
			current = current->next;
		traverse_list(current);
	}
	else if (command == 'q')
		printf("quit!");
	else if (command)
		printf("fuck you!");

}