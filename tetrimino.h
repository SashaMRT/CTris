#include <stdbool.h>

// Definition de la structure pour la position
typedef struct s_point {
    int y;
    int x;
} t_point;

typedef enum {
    SHAPE_NONE = 0,
    SHAPE_BEGIN,
    SHAPE_I = SHAPE_BEGIN,
    SHAPE_J,
    SHAPE_L,
    SHAPE_O,
    SHAPE_S,
    SHAPE_T,
    SHAPE_Z,
    SHAPE_END
} t_shape;

// Definition de la structure tetrimino
typedef struct s_tetrimino {
    t_shape shape;
    t_point location;
    int orientation;
} t_tetrimino;

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