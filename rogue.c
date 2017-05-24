#include<ncurses.h>
#include<string.h>

extern inline void cwmove(typeof(stdscr) scr, int row, int col, int max_row, int max_col) {
    wmove(scr,row % max_row,col % max_col);
}

int main ()
{
    int ch;
    int row,col;
    int max_row,max_col;

    char str[] = "Pressed key is ";

    initscr();
    raw();
    noecho();
    keypad(stdscr, TRUE);

    getmaxyx(stdscr,max_row,max_col);

    row = max_row/4;
    col = (max_col-strlen(str))/4;

    move(row,col);

    do {
        ch = getch();
        printw(str);
        addch(ch | A_BOLD);
        getyx(stdscr,row,col);
        cwmove(stdscr,row+1,col,max_row,max_col);

        refresh();
    } while(ch != KEY_F(1));

    printw("Alright!");
    refresh();

    getch();
    endwin();
    return 0;
}
