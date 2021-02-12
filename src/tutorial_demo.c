/**
 *
 * Senha
 * Autores: github.com/Albuquerque-David, github.com/Cardosaum, github.com/sunnyseth
 * Under Apache License Version 2.0, January 2004
 *
 */

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct _win_border_struct {
    chtype ls, rs, ts, bs,
           tl, tr, bl, br;
} WIN_BORDER;

typedef struct _WIN_struct {
    int startx, starty;
    int height, width;
    WIN_BORDER border;
}WIN;

void
draw_table(WIN *win, bool draw);

void
set_default_table(WIN *win);

int main()
{
    WIN win;
    int ch;

    initscr();             /* Start curses mode */
    raw();                 /* Line buffering disabled*/
    keypad(stdscr, TRUE);  /* We get F1, F2 etc..*/
    noecho();              /* Don't echo() while we do getch */
    cbreak();


    set_default_table(&win);
    draw_table(&win, TRUE);
    // printw("Type any character to see it in bold\n");
    /* printw("l: %i, c: %i\n", LINES, COLS); */
    ch = getch();               /* If raw() hadn't been called
                                 * we have to press enter before it
                                 * gets to the program */
    if(ch == KEY_F(1))          /* Without keypad enabled this will */
    printw("F1 Key pressed");   /*  not get to us either*/
                                /* Without noecho() some ugly escape
                                 * charachters might have been printed
                                 * on screen*/
    else
    {
        printw("The pressed key is ");
        attron(A_BOLD);
        printw("%c", ch);
        attroff(A_BOLD);
    }
    refresh(); /* Print it on to the real screen */
    getch();   /* Wait for user input */
    endwin();  /* End curses mode  */

return 0;
}


void
set_default_table(WIN *win)
{
    win->height = 3;
    win->width = 10;
    win->starty = 0;
    win->startx = 0;
    /* win->starty = (LINES - win->height)/2; */
    /* win->startx = (COLS - win->width)/2; */

    win->border.ls = '|';
    win->border.rs = '|';
    win->border.ts = '-';
    win->border.bs = '-';
    win->border.tl = '+';
    win->border.tr = '+';
    win->border.bl = '+';
    win->border.br = '+';

}

void
draw_table(WIN *win, bool draw)
{
    int i, j;
    int x, y, w, h;

    x = win->startx;
    y = win->starty;
    w = win->width;
    h = win->height;

    if(draw == TRUE)
    {
        mvaddch(y, x, win->border.tl);
        mvaddch(y, x + w, win->border.tr);
        mvaddch(y + h, x, win->border.bl);
        mvaddch(y + h, x + w, win->border.br);
        mvhline(y, x + 1, win->border.ts, w - 1);
        mvhline(y + h, x + 1, win->border.bs, w - 1);
        mvvline(y + 1, x, win->border.ls, h - 1);
        mvvline(y + 1, x + w, win->border.rs, h - 1);

    }
    else
        for(j = y; j <= y + h; ++j)
            for(i = x; i <= x + w; ++i)
                mvaddch(j, i, ' ');

    refresh();

}
