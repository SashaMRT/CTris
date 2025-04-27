/**
 * @file ctris.h
 * @brief Header file for CTris game
 * @details This file contains the declarations and definitions for the CTris game.
 * It includes the necessary libraries, defines the structures for game state,
 * and declares the functions for initializing, updating, and displaying the game.
 * It also includes the function for handling user input and checking for game over conditions.
 * @date 2025-27-04
 * @version 1.0
 * @author Sasha Marie te Rehorst / Gael Guinaliu
 * 
 * Copyright (c) 2025 Sasha Marie te Rehorst / Gael Guinaliu
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3 of the License.
 */
#ifndef CTRIS_H
#define CTRIS_H

#include "../define.h"
#include "tetrimino.h"

// Structure pour représenter l'état du jeu
typedef struct {
    int board[TETRIS_BOARD_HEIGHT][TETRIS_BOARD_WIDTH];
    t_tetrimino current_tetrimino;
    int score;
    int level;
    bool game_over;
} t_game_state;

// Déclaration externe pour game_state
extern t_game_state game_state;

// Déclarations des fonctions pour le jeu CTris
void init_game();
void display_board();
void handle_input();
void update_game_state();
void check_lines();
void game_over();

#endif // CTRIS_H
// End of ctris.h