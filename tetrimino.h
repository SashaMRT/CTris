#include <stdbool.h>

// Definition de la structure pour la position
typedef struct s_point {
    int y;
    int x;
} t_point;

// Definition de la structure tetrimino
typedef struct s_tetrimino {
    int shape;
    t_point location;
    int orientation;
} t_tetrimino;

// On défini ici les formes des tetriminos sous forme de chiffres
#define TETRIMINO_I 0
#define TETRIMINO_J 1
#define TETRIMINO_L 2
#define TETRIMINO_O 3
#define TETRIMINO_S 4
#define TETRIMINO_Z 5
#define TETRIMINO_T 6

// Necessaire pour les tableaux
#define TETRIS_TETRIMINO_NB 7
#define TETRIS_TETRIMINO_ORIENTATIONS 4
#define TETRIS_TETRIMINO_CELL_NB 4

// On reprend la structure de main.h
extern const t_point TETRIMINO_SHAPES[TETRIS_TETRIMINO_NB][TETRIS_TETRIMINO_ORIENTATIONS][TETRIS_TETRIMINO_CELL_NB];

// Déclarations des fonctions
void init_tetrimino(t_tetrimino *tetrimino, int shape);
bool move_tetrimino(t_tetrimino *tetrimino, int dy, int dx);
void rotate_tetrimino(t_tetrimino *tetrimino);