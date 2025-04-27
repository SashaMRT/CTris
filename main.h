#include <ncurses.h>

// Definition de la structure pour la position
typedef struct s_point {
    int y;
    int x;
} t_point;

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
