#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>

#define HAUTEUR 10
#define LARGEUR 30

// Création des deux fenétres a cote a cote
WINDOW *fenetre1 = newwin(HAUTEUR, LARGEUR, 2, 2);
WINDOW *fenetre2 = newwin(HAUTEUR, LARGEUR, 2, 35);

// Style pour la premiere fenetre
wbkgd(fenetre1, COLOR_PAIR(SHAPE_I));
box(fenetre1, 0 , 0);
mvwprintfw(fenetre1, 1, 2, "Fenetre 1");
mvwprintfw(fenetre1, 3, 2, "Contenue : stats");

// Style pour la premiere fenetre
wbkgd(fenetre2, COLOR_PAIR(SHAPE_J));
box(fenetre2, 0 , 0);
mvwprintfw(fenetre1, 1, 2, "Fenetre 2");
mvwprintfw(fenetre1, 3, 2, "Contenue : log");
