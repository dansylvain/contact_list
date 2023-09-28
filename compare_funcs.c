#include "headerfile.h"

int	sort_by_name(Contact *current)
{
	return (strcmp(current->name, current->next->name) > 0);
}

int	sort_by_email(Contact *current)
{
	return (strcmp(current->email, current->next->email) > 0);
}

int	sort_by_phone(Contact *current)
{
	if ((current->phone_number[0] - '0') > (current->next->phone_number[0] - '0'))
		return (1);
	else
		return (0);
}
