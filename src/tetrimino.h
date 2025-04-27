#ifndef TETRIMINO_H
#define TETRIMINO_H

#include <stdbool.h>
#include "../define.h"

// Définir une structure pour représenter un point (y, x)
typedef struct {
    int y;
    int x;
} t_point;

// Définir une énumération pour les formes des Tetriminos
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

// Définir une structure pour représenter un Tetrimino
typedef struct {
    t_shape shape;
    t_point location;
    int orientation;
} t_tetrimino;

// Déclaration externe pour TETRIMINO_SHAPES
extern const t_point TETRIMINO_SHAPES[TETRIS_TETRIMINO_NB][TETRIS_TETRIMINO_ORIENTATIONS][TETRIS_TETRIMINO_CELL_NB];

// Déclarations des fonctions
void init_tetrimino(t_tetrimino *tetrimino, t_shape shape);
bool move_tetrimino(t_tetrimino *tetrimino, int dy, int dx);
void rotate_tetrimino(t_tetrimino *tetrimino);
bool is_valid_move(t_tetrimino *tetrimino, int dy, int dx);
void draw_tetrimino(t_tetrimino *tetrimino);

#endif // TETRIMINO_H
// End of tetrimino.h