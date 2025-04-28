#include "ctris.h"
#include "tetrimino.h"
#include <ncurses.h>
#include <stdlib.h>
#include <sys/time.h>

// Définition de game_state
t_game_state game_state;

// Initialiser le jeu
void init_game() {
    // Initialiser la grille de jeu
    for (int y = 0; y < TETRIS_BOARD_HEIGHT; ++y) {
        for (int x = 0; x < TETRIS_BOARD_WIDTH; ++x) {
            game_state.board[y][x] = 0;
        }
    }
    // Initialiser le Tetrimino courant
    init_tetrimino(&game_state.current_tetrimino, SHAPE_I);
    game_state.score = 0;
    game_state.level = 1;
    game_state.game_over = false;
}

// Afficher la grille de jeu
void display_board() {
    clear();
    for (int y = 0; y < TETRIS_BOARD_HEIGHT; ++y) {
        for (int x = 0; x < TETRIS_BOARD_WIDTH; ++x) {
            if (game_state.board[y][x] != 0) {
                attron(COLOR_PAIR(game_state.board[y][x]));
                mvprintw(y, x * TETRIS_TETRIMINO_SCALE_X, "##");
                attroff(COLOR_PAIR(game_state.board[y][x]));
            } else {
                mvprintw(y, x * TETRIS_TETRIMINO_SCALE_X, ".");
            }
        }
    }
    draw_tetrimino(&game_state.current_tetrimino);
    mvprintw(TETRIS_BOARD_HEIGHT + 1, 0, "Score: %d Level: %d", game_state.score, game_state.level);
    refresh();
}

// Gérer les entrées utilisateur
void handle_input() {
    int ch = getch();
    switch (ch) {
        case KEY_LEFT:
            move_tetrimino(&game_state.current_tetrimino, 0, -1);
            break;
        case KEY_RIGHT:
            move_tetrimino(&game_state.current_tetrimino, 0, 1);
            break;
        case KEY_DOWN:
            move_tetrimino(&game_state.current_tetrimino, 1, 0);
            break;
        case ' ':
            // Drop Tetrimino instantly
            while (move_tetrimino(&game_state.current_tetrimino, 1, 0));
            break;
        case KEY_UP:
            rotate_tetrimino(&game_state.current_tetrimino);
            break;
        case 'q':
            game_state.game_over = true;
            break;
    }
}

// Mettre à jour l'état du jeu
void update_game_state() {
    // Mettre à jour la position du Tetrimino courant
    if (!move_tetrimino(&game_state.current_tetrimino, 1, 0)) {
        // Tetrimino ne peut plus descendre, le fixer sur le plateau
        for (int i = 0; i < TETRIS_TETRIMINO_CELL_NB; ++i) {
            int y = game_state.current_tetrimino.location.y + TETRIMINO_SHAPES[game_state.current_tetrimino.shape][game_state.current_tetrimino.orientation][i].y;
            int x = game_state.current_tetrimino.location.x + TETRIMINO_SHAPES[game_state.current_tetrimino.shape][game_state.current_tetrimino.orientation][i].x;
            if (y < 0 || y >= TETRIS_BOARD_HEIGHT || x < 0 || x >= TETRIS_BOARD_WIDTH) {
                // Si le Tetrimino dépasse les limites, le jeu est terminé
                game_state.game_over = true;
                return;
            }
            game_state.board[y][x] = game_state.current_tetrimino.shape + 1;
        }
        // Vérifier et supprimer les lignes complètes
        check_lines();
        // Générer un nouveau Tetrimino
        struct timeval ms;
        gettimeofday(&ms, NULL);
        srand(ms.tv_sec * 1000 + ms.tv_usec / 1000);
        init_tetrimino(&game_state.current_tetrimino, rand() % (TETRIS_TETRIMINO_NB - SHAPE_BEGIN + 1) + SHAPE_BEGIN);
        // Vérifier si le nouveau Tetrimino peut être placé
        if (!is_valid_move(&game_state.current_tetrimino, 0, 0)) {
            game_state.game_over = true;
        }
    }
}

// Vérifier et supprimer les lignes complètes
void check_lines() {
    for (int y = TETRIS_BOARD_HEIGHT - 1; y >= 0; --y) {
        bool line_full = true;
        for (int x = 0; x < TETRIS_BOARD_WIDTH; ++x) {
            if (game_state.board[y][x] == 0) {
                line_full = false;
                break;
            }
        }
        if (line_full) {
            // Supprimer la ligne et décaler les lignes supérieures
            for (int yy = y; yy > 0; --yy) {
                for (int x = 0; x < TETRIS_BOARD_WIDTH; ++x) {
                    game_state.board[yy][x] = game_state.board[yy - 1][x];
                }
            }
            // Ajouter une nouvelle ligne vide en haut
            for (int x = 0; x < TETRIS_BOARD_WIDTH; ++x) {
                game_state.board[0][x] = 0;
            }
            // Augmenter le score
            game_state.score += 100;
            // Message de débogage
            mvprintw(TETRIS_BOARD_HEIGHT + 4, 0, "Line %d cleared!", y);
            refresh();
            napms(500); // Pause pour voir le message de débogage
        }
    }
}


// Gérer la fin du jeu
void game_over() {
    mvprintw(TETRIS_BOARD_HEIGHT + 2, 0, "Game Over! Final Score: %d", game_state.score);
    refresh();

    // Demander à l'utilisateur s'il veut rejouer
    int ch;
    while (true) {
        mvprintw(TETRIS_BOARD_HEIGHT + 3, 0, "Play again? (y/n): ");
        refresh();
        ch = getch();
        if (ch == 'y' || ch == 'Y') {
            // Réinitialiser le jeu
            init_game();
            // Message de débogage
            mvprintw(TETRIS_BOARD_HEIGHT + 4, 0, "Game restarted!");
            refresh();
            // Attendre un court moment pour voir le message de débogage
            napms(1000);
            break;
        } else if (ch == 'n' || ch == 'N') {
            // Quitter le jeu
            break;
        }
    }
}
// End of ctris.c