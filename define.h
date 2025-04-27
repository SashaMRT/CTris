/**
 * @file define.h
 * @brief Header file for Tetris game
 * @details This file contains the definitions and declarations for the Tetris game.
 * It includes the necessary libraries, defines the structures for points and tetriminos,
 * and declares the functions for initializing, moving, and rotating tetriminos.
 * It also includes the function for checking collisions and displaying the tetrimino on the screen.
 * @date 2025-27-04
 * @version 1.0
 * @author Sasha Marie te Rehorst / Gael Guinaliu
 * 
 * Copyright (c) 2025 Sasha Marie te Rehorst / Gael Guinaliu
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3 of the License.
 * 
 */
#ifndef DEFINE_H
#define DEFINE_H

// Définir les constantes pour les Tetriminos
#define TETRIS_TETRIMINO_NB 7
#define TETRIS_TETRIMINO_ORIENTATIONS 4
#define TETRIS_TETRIMINO_CELL_NB 4
#define TETRIS_TETRIMINO_SCALE_X 2

// Définir les dimensions et positions de la zone de jeu
#define TETRIS_BOARD_Y 1
#define TETRIS_BOARD_X 1
#define TETRIS_BOARD_HEIGHT 22
#define TETRIS_BOARD_WIDTH 12

// Définir les dimensions et positions de la piece suivante
#define TETRIS_NEXT_Y (TETRIS_BOARD_Y)
#define TETRIS_NEXT_X (TETRIS_BOARD_X + TETRIS_BOARD_WIDTH + 1)
#define TETRIS_NEXT_HEIGHT 8
#define TETRIS_NEXT_WIDTH 8

// Définir les dimensions et positions de la piece en attente
#define TETRIS_HOLD_Y (TETRIS_NEXT_Y + TETRIS_NEXT_HEIGHT + 1)
#define TETRIS_HOLD_X (TETRIS_NEXT_X)
#define TETRIS_HOLD_HEIGHT TETRIS_NEXT_HEIGHT
#define TETRIS_HOLD_WIDTH TETRIS_NEXT_WIDTH

// Définir les dimensions et positions de l'affichage
#define TETRIS_DISPLAY_Y (TETRIS_HOLD_Y + TETRIS_HOLD_HEIGHT + 1)
#define TETRIS_DISPLAY_X (TETRIS_NEXT_X)
#define TETRIS_DISPLAY_HEIGHT 8
#define TETRIS_DISPLAY_WIDTH 10

// Définir les constantes pour les segments colorés
#define SEGMENT_WIDTH 10
#define SEGMENT_SPACING 2

#endif // DEFINE_H
// End of define.h