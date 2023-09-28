#include "headerfile.h"

int	sort_by_name(Contact *current)
{
	return (strcmp(current->name, current->next->name) > 0);
}

int	sort_by_email(Contact *current)
{
	return (strcmp(current->email, current->next->email) > 0);
}
