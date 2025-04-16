#include "main.h"

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
    
    // Position initiale au centre
    pos.y = LINES / 2;
    pos.x = COLS / 2;
    
    while ((ch = getch()) != 'q')
    {
        // Effacer l'écran
        clear();
        // Appel de la fonction bouger
        bouger(&pos, ch);
        
        // afficher le caractère "G" à la position voulu
        mvprintw(pos.y, pos.x, "G");
        // mise a jour de la position
        refresh();
    }
    
    // Fin de ncurses (similaire a un free)
    endwin();
    return 0;
}
