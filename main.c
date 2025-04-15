#include <ncurses.h>

typedef struct s_point {
    int y;
    int x;
} t_point;

// Fonction Gestion des mouvements
void bouger(t_point *pos, int ch)
{
    switch (ch) {
        case KEY_LEFT:
            pos->x = (pos->x > 0) ? pos->x - 1 : 0;
            break;
        case KEY_RIGHT:
            pos->x = (pos->x < COLS - 1) ? pos->x + 1 : COLS - 1;
            break;
        case KEY_UP:
            pos->y = (pos->y > 0) ? pos->y - 1 : 0;
            break;
        case KEY_DOWN:
            pos->y = (pos->y < LINES - 1) ? pos->y + 1 : LINES - 1;
            break;
    }
}

int main()
{
    int ch;
    t_point pos;
    
    // Initialisation de ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    
    // Position initiale au centre
    pos.y = LINES / 2;
    pos.x = COLS / 2;
    
    while ((ch = getch()) != 'q')
    {
        clear();
        bouger(&pos, ch);
        
        mvprintw(pos.y, pos.x, "G");
        refresh();
    }
    
    endwin();
    return 0;
}
