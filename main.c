#include "main.h"

void afficher_fenetre(WINDOW *win, const char *titre)
{
    box(win, 0 ,0);
    mvwprintw(win, 0 ,2 ,"[%s]", titre);
    wrefresh(win);
}

int main()
{
    int ch;
    t_point pos;
    
    // Initialisation de ncurses
    initscr();
    // Enlever les limites des lignes
    cbreak();
    // Remet les lignes en fonction de la resolution de la fenetre
    noecho();
    // Permet d'utiliser les touches de fonction
    keypad(stdscr, TRUE); // stdscr correspond a la limite de taille de la fenêtre
    // Enlever les bordures de la fenetre
    curs_set(0);
    refresh();
    getch();
    WINDOW *win_next = newwin(TETRIS_NEXT_HEIGHT, TETRIS_NEXT_WIDTH, TETRIS_NEXT_Y, TETRIS_NEXT_X);
    WINDOW *win_hold = newwin(TETRIS_HOLD_HEIGHT, TETRIS_HOLD_WIDTH, TETRIS_HOLD_Y, TETRIS_HOLD_X);
    WINDOW *win_display = newwin(TETRIS_DISPLAY_HEIGHT, TETRIS_DISPLAY_WIDTH, TETRIS_DISPLAY_Y, TETRIS_DISPLAY_X);

    afficher_fenetre(win_next, "NEXT");
    afficher_fenetre(win_hold, "HOLD");
    afficher_fenetre(win_display, "SCORE");

    WINDOW *win_board = newwin(TETRIS_BOARD_HEIGHT, TETRIS_BOARD_WIDTH, TETRIS_BOARD_Y, TETRIS_BOARD_X);
    afficher_fenetre(win_board, "BOARD");
        refresh();
        getch();
    // Fin de ncurses (similaire a un free)
    delwin(win_board);
    delwin(win_display);
    delwin(win_hold);
    delwin(win_next);
    endwin();
    return 0;
}
