#include<ncurses.h>
#include<string.h>

void wrap_move(int row_move,int col_move,typeof(stdscr) scr) {
    int prev_row,prev_col;
    int row,col;

    getyx(scr,prev_row,prev_col);
    wmove(scr,prev_row+row_move,prev_col+col_move);
    getyx(scr,row,col);

    if(row_move != 0 && prev_row == row)
        row = 0;
    if(col_move != 0 && prev_col == col)
        col = 0;

    if(!(col && row))
        wmove(scr,row,col);
}

int main ()
{
    int ch;
    int row,col;
    int prev;

    char str[] = "Pressed key is ";

    initscr();
    raw();
    noecho();
    keypad(stdscr, TRUE);

    getmaxyx(stdscr,row,col);
    row = row/4;
    col = (col-strlen(str))/4;

    move(row,col);

    do {
        ch = getch();
        printw(str);
        addch(ch | A_BOLD);
        wrap_move(1,0,stdscr);

        refresh();
    } while(ch != KEY_F(1));

    printw("Alright!");
    refresh();

    getch();
    endwin();
    return 0;
}
