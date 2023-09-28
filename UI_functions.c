// #include "headerfile.h"

// //static void	add_contact();

// void	swap_contacts()
// {
// 	char	name[21];
// 	Contact	*node;

// 	printf("Name: ");
// 	scanf("%20s", name);
// 	node = get_node(name);
// 	swap_nodes(node, node->next);
// }

// void	enter_toggle_mode(void)
// {
// 	traverse_list(head);
// 	prompt_command();

// }

// void	sort_list_ui()
// {
// 	char	command;

// 	printf("\nn - sort by name / e - sort by email / p - sort by phone number \n>>> ");
// 	scanf(" %c", &command);
// 	if (command == 'n')
// 		sort_list(sort_by_name);
// 	else if (command == 'e')
// 		sort_list(sort_by_email);
// 	else if (command == 'p')
// 		sort_list(sort_by_phone);
// 	else if(command)
// 	{
// 		printf("\n\n********** INVALID COMMAND **********\n\n");
// 		prompt_command();
// 	}
// 	prompt_command();
// }

// void	prompt_command(void)
// {
// 	char	command;
// 	Contact	*node;

// 	node = NULL;
// 	printf("\na - Add contact / d -display contacts / s - Search contact / r -remove contact / w - sort list / t - go through the list / q - quit >>> ");
// 	scanf(" %c", &command);

// 	// // if (command == 'a')
// 	// 	//add_contact();
// 	// else if (command == 'd')
// 	// 	display_contact();
// 	// else if (command == 's')
// 	// 	search_contact();
// 	// else if (command == 'r')
// 	// 	remove_contact(node);
// 	// else if (command == 'w')
// 	// 	sort_list_ui();
// 	// else if (command == 't')
// 	// 	enter_toggle_mode();
// 	// else if (command == 'q')
// 	// {
// 	// 	free_list();
// 	// 	exit(1);
// 	// }
// 	// else if(command)
// 	// {
// 	// 	printf("\n\n********** INVALID COMMAND **********\n\n");
// 	// 	prompt_command();
// 	// }

// }

// void	remove_contact(Contact *node)
// {
// 	char	name[21];

// 	printf("Name: ");
// 	scanf("%20s", name);
// 	if (!node)
// 		node = get_node(name);
// 	if (node)
// 		free_node(node);
// 	prompt_command();
// }

// Contact	*search_contact()
// {
// 	Contact	*node;

// 	node = NULL;
// 	char	name[21];

// 	printf("Name: ");
// 	scanf("%20s", name);
// 	node = get_node(name);
// 	if (node)
// 		printf("%-20s%-20s%-30s\n", node->name, node->phone_number, node->email);
// 	prompt_command();
// }

// void	display_contact()
// {
// 	Contact	*current;
// 	current = head;
// 	while (current)
// 	{
// 		printf("%-20s%-20s%-30s%-20s%-20s%-20s\n", current->name, current->phone_number, current->email, current->previous->name, current->next->name, tail->name);
// 		current = current->next;	
// 	}

// 	prompt_command();
// }

// // static void	add_contact()
// // {
// // 	char	name[21];
// // 	char	phone_number[21];
// // 	char	email[31];

// // 	printf("Name: ");
// // 	scanf("%20s", name);
// // 	printf("Phone number: ");
// // 	scanf("%20s", phone_number);
// // 	printf("E-mail address: ");
// // 	scanf("%30s", email);

// // 	create_contact_node(name, phone_number, email);

// // 	prompt_command();
// // }