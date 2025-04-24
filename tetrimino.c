#include <stdlib.h>
#include "tetrimino.h"

// On définit les tetriminos
const t_point TETRIMINO_SHAPES[TETRIS_TETRIMINO_NB][TETRIS_TETRIMINO_ORIENTATIONS][TETRIS_TETRIMINO_CELL_NB] = {
    { // I
        {{1, 0}, {1, 1}, {1, 2}, {1, 3}},
        {{0, 2}, {1, 2}, {2, 2}, {3, 2}},
        {{3, 0}, {3, 1}, {3, 2}, {3, 3}},
        {{0, 1}, {1, 1}, {2, 1}, {3, 1}}
    },
    { // J
        {{0, 0}, {1, 0}, {1, 1}, {1, 2}},
        {{0, 1}, {0, 2}, {1, 1}, {2, 1}},
        {{1, 0}, {1, 1}, {1, 2}, {2, 2}},
        {{0, 1}, {1, 1}, {2, 0}, {2, 1}}
    },
    { // L
        {{0, 2}, {1, 0}, {1, 1}, {1, 2}},
        {{0, 1}, {1, 1}, {2, 1}, {2, 0}},
        {{1, 0}, {1, 1}, {1, 2}, {0, 0}},
        {{0, 0}, {0, 1}, {1, 1}, {2, 1}}
    },
    { // O
        {{0, 1}, {0, 2}, {1, 1}, {1, 2}},
        {{0, 1}, {0, 2}, {1, 1}, {1, 2}},
        {{0, 1}, {0, 2}, {1, 1}, {1, 2}},
        {{0, 1}, {0, 2}, {1, 1}, {1, 2}}
    },
    { // S
        {{0, 1}, {0, 2}, {1, 0}, {1, 1}},
        {{0, 1}, {1, 1}, {1, 2}, {2, 1}},
        {{1, 0}, {1, 1}, {2, 1}, {2, 2}},
        {{0, 1}, {1, 0}, {1, 1}, {2, 0}}
    },
    { // Z
        {{0, 0}, {0, 1}, {1, 1}, {1, 2}},
        {{0, 2}, {1, 1}, {1, 2}, {2, 1}},
        {{1, 0}, {1, 1}, {2, 1}, {2, 2}},
        {{0, 1}, {1, 0}, {1, 1}, {2, 1}}
    },
    { // T
        {{0, 1}, {1, 0}, {1, 1}, {1, 2}},
        {{0, 1}, {1, 1}, {1, 2}, {2, 1}},
        {{1, 0}, {1, 1}, {1, 2}, {2, 1}},
        {{0, 1}, {1, 0}, {1, 1}, {2, 1}}
    }
};

// Initialisation
void init_tetrimino(t_tetrimino *tetrimino, int shape) {
    tetrimino->shape = shape;
    tetrimino->location.y = 0;
    tetrimino->location.x = 3;
    tetrimino->orientation = 0;
}

// Déplacement
bool move_tetrimino(t_tetrimino *tetrimino, int dy, int dx) {
    tetrimino->location.y += dy;
    tetrimino->location.x += dx;
    // A finir
    return true; // Retourne false si une collision
}

// Rotation
void rotate_tetrimino(t_tetrimino *tetrimino) {
    tetrimino->orientation = (tetrimino->orientation + 1) % 4;
    // A finir
}
