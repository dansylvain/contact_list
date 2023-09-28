#include <ncurses.h>
#include <stdlib.h>

void display_main_menu_content(WINDOW *menu_win, char **items, int item_count) 
{
    int x = 2;
    int y = 2;

    for(int i = 0; i < item_count; ++i)
	{
		if(i == 2)
		{
			wattron(menu_win, A_REVERSE);
			mvwprintw(menu_win, y + i, x, "%s", items[i]);
			wattroff(menu_win, A_REVERSE);
		}
		else
	    	mvwprintw(menu_win, y + i, x, "%s", items[i]);
    }
    wrefresh(menu_win);
}

int main(void) {
	int	ch;
    char *main_menu_items[] =
	{
        "Item 1",
        "Item 2",
        "Item 3",
        "Item 4"
    };
    int main_menu_items_number = sizeof(main_menu_items) / sizeof(char *);

    initscr();
    cbreak();
    noecho();
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
    refresh();

    WINDOW *main_menu;
    main_menu = newwin(LINES / 2, COLS / 2, LINES / 4, COLS / 4);
	keypad(main_menu, TRUE);
	wattron(main_menu, COLOR_PAIR(1));
    box(main_menu, 0, 0);
    display_main_menu_content(main_menu, main_menu_items, main_menu_items_number);

	while (TRUE)
	{
    	ch = getch();
		if (ch == KEY_LEFT)
			wprintw(main_menu, "Data gueule!");
		wrefresh(main_menu);

	}
    endwin();
    return 0;
}