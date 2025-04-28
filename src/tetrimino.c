#include "ctris.h"
#include "tetrimino.h"
#include <ncurses.h>
#include <stdlib.h>

// Tableau des formes de Tetriminos (coordonnées relatives)
const t_point TETRIMINO_SHAPES[TETRIS_TETRIMINO_NB][TETRIS_TETRIMINO_ORIENTATIONS][TETRIS_TETRIMINO_CELL_NB] = {
    { // Shape I
        {{1, 0}, {1, 1}, {1, 2}, {1, 3}},
        {{0, 2}, {1, 2}, {2, 2}, {3, 2}},
        {{3, 0}, {3, 1}, {3, 2}, {3, 3}},
        {{0, 1}, {1, 1}, {2, 1}, {3, 1}}
    },
    { // Shape J
        {{0, 0}, {1, 0}, {1, 1}, {1, 2}},
        {{0, 1}, {0, 2}, {1, 1}, {2, 1}},
        {{1, 0}, {1, 1}, {1, 2}, {2, 2}},
        {{0, 1}, {1, 1}, {2, 0}, {2, 1}}
    },
    { // Shape L
        {{0, 2}, {1, 0}, {1, 1}, {1, 2}},
        {{0, 1}, {1, 1}, {2, 1}, {2, 0}},
        {{1, 0}, {1, 1}, {1, 2}, {0, 0}},
        {{0, 0}, {0, 1}, {1, 1}, {2, 1}}
    },
    { // Shape O
        {{0, 1}, {0, 2}, {1, 1}, {1, 2}},
        {{0, 1}, {0, 2}, {1, 1}, {1, 2}},
        {{0, 1}, {0, 2}, {1, 1}, {1, 2}},
        {{0, 1}, {0, 2}, {1, 1}, {1, 2}}
    },
    { // Shape S
        {{0, 1}, {0, 2}, {1, 0}, {1, 1}},
        {{0, 1}, {1, 1}, {1, 2}, {2, 1}},
        {{1, 0}, {1, 1}, {2, 1}, {2, 2}},
        {{0, 1}, {1, 0}, {1, 1}, {2, 0}}
    },
    { // Shape Z
        {{0, 0}, {0, 1}, {1, 1}, {1, 2}},
        {{0, 2}, {1, 1}, {1, 2}, {2, 1}},
        {{1, 0}, {1, 1}, {2, 1}, {2, 2}},
        {{0, 1}, {1, 0}, {1, 1}, {2, 1}}
    },
    { // Shape T
        {{0, 1}, {1, 0}, {1, 1}, {1, 2}},
        {{0, 1}, {1, 1}, {1, 2}, {2, 1}},
        {{1, 0}, {1, 1}, {1, 2}, {2, 1}},
        {{0, 1}, {1, 0}, {1, 1}, {2, 1}}
    }
};

// Initialiser un Tetrimino avec une forme donnée
void init_tetrimino(t_tetrimino *tetrimino, t_shape shape) {
    tetrimino->shape = shape - SHAPE_BEGIN;
    tetrimino->location.y = 0;
    tetrimino->location.x = TETRIS_BOARD_WIDTH / 2; // Centre initialement
    tetrimino->orientation = 0;
}

// Déplacer un Tetrimino
bool move_tetrimino(t_tetrimino *tetrimino, int dy, int dx) {
    if (is_valid_move(tetrimino, dy, dx)) {
        tetrimino->location.y += dy;
        tetrimino->location.x += dx;
        return true;
    }
    return false;
}

// Faire tourner un Tetrimino
void rotate_tetrimino(t_tetrimino *tetrimino) {
    tetrimino->orientation = (tetrimino->orientation + 1) % TETRIS_TETRIMINO_ORIENTATIONS;
    if (!is_valid_move(tetrimino, 0, 0)) {
        tetrimino->orientation = (tetrimino->orientation - 1 + TETRIS_TETRIMINO_ORIENTATIONS) % TETRIS_TETRIMINO_ORIENTATIONS;
    }
}

// Vérifier si un mouvement est valide
bool is_valid_move(t_tetrimino *tetrimino, int dy, int dx) {
    for (int i = 0; i < TETRIS_TETRIMINO_CELL_NB; ++i) {
        int new_y = tetrimino->location.y + dy + TETRIMINO_SHAPES[tetrimino->shape][tetrimino->orientation][i].y;
        int new_x = tetrimino->location.x + dx + TETRIMINO_SHAPES[tetrimino->shape][tetrimino->orientation][i].x;

        if (new_y >= TETRIS_BOARD_HEIGHT || new_x < 0 || new_x >= TETRIS_BOARD_WIDTH || new_y < 0) {
            return false;
        }
        if (new_y >= 0 && game_state.board[new_y][new_x] != 0) {
            return false;
        }
    }
    return true;
}

// Dessiner un Tetrimino
void draw_tetrimino(t_tetrimino *tetrimino) {
    for (int i = 0; i < TETRIS_TETRIMINO_CELL_NB; ++i) {
        int y = tetrimino->location.y + TETRIMINO_SHAPES[tetrimino->shape][tetrimino->orientation][i].y;
        int x = tetrimino->location.x + TETRIMINO_SHAPES[tetrimino->shape][tetrimino->orientation][i].x;
        if (y >= 0 && y < TETRIS_BOARD_HEIGHT && x >= 0 && x < TETRIS_BOARD_WIDTH) {
            attron(COLOR_PAIR(tetrimino->shape + 1));
            mvprintw(y, x * TETRIS_TETRIMINO_SCALE_X, "##");
            attroff(COLOR_PAIR(tetrimino->shape + 1));
        }
    }
    refresh();
}
// End of tetrimino.c