#include <ncurses.h>

#define TETRIS_TETRIMINO_NB 7
#define TETRIS_TETRIMINO_ORIENTATIONS 4
#define TETRIS_TETRIMINO_CELL_NB 4

#define TETRIS_BOARD_Y 1
#define TETRIS_BOARD_X 1
#define TETRIS_BOARD_HEIGHT 22
#define TETRIS_BOARD_WIDTH 12

#define TETRIS_NEXT_Y   (TETRIS_BOARD_Y)
#define TETRIS_NEXT_X   (TETRIS_BOARD_X + TETRIS_BOARD_HEIGHT + 1)
#define TETRIS_NEXT_HEIGHT 8
#define TETRIS_NEXT_WIDTH 8

#define TETRIS_HOLD_Y   (TETRIS_NEXT_Y + TETRIS_NEXT_HEIGHT + 1)
#define TETRIS_HOLD_X   (TETRIS_NEXT_X)
#define TETRIS_HOLD_HEIGHT  (TETRIS_NEXT_HEIGHT)
#define TETRIS_HOLD_WIDTH (TETRIS_NEXT_WIDTH)

#define TETRIS_DISPLAY_Y    (TETRIS_HOLD_Y + TETRIS_HOLD_HEIGHT + 1)
#define TETRIS_DISPLAY_X    (TETRIS_NEXT_X)
#define TETRIS_DISPLAY_HEIGHT 8
#define TETRIS_DISPLAY_WIDTH 10


typedef struct s_point{
    int y;
    int x;
}t_point;

typedef enum e_shape {
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

typedef struct s_tetrimino{
    t_shape shape;
    t_point location;
    int orientation;
}t_tetrimino;

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

    { // Shape Z
        {{0, 0}, {0, 1}, {1, 1}, {1, 2}},
        {{0, 2}, {1, 1}, {1, 2}, {2, 1}},
        {{1, 0}, {1, 1}, {2, 1}, {2, 2}},
        {{0, 1}, {1, 0}, {1, 1}, {2, 1}}
    }
};




start_color();
init_pair(SHAPE_I, COLOR_CYAN, COLOR_BLACK);
init_pair(SHAPE_J, COLOR_BLUE, COLOR_BLACK);
init_pair(SHAPE_L, COLOR_WHITE, COLOR_BLACK);
init_pair(SHAPE_O, COLOR_YELLOW, COLOR_BLACK);
init_pair(SHAPE_S, COLOR_GREEN, COLOR_BLACK);
init_pair(SHAPE_T, COLOR_MAGENTA, COLOR_BLACK);
init_pair(SHAPE_Z, COLOR_RED, COLOR_BLACK);
