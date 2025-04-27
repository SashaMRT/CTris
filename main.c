/**
 * @file main.c
 * @brief Main file for Tetris game
 * @details This file contains the main function for the Tetris game.
 * It initializes the game, handles user input, and manages the game loop.
 * It includes the necessary libraries and headers, and defines the main function.
 * @date 2025-27-04
 * @version 1.0
 * @author Sasha Marie te Rehorst / Gael Guinaliu
 * 
 * Copyright (c) 2025 Sasha Marie te Rehorst / Gael Guinaliu
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3 of the License.
 */
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#include "define.h"
#include "src/tetrimino.h"
#include "src/ctris.h"

// Function to print a colored segment
void print_colored_segment(int y, int x, int width, int color_pair) {
    attron(COLOR_PAIR(color_pair));
    mvprintw(y, x, "%*c", width, ' ');
    attroff(COLOR_PAIR(color_pair));
    refresh();
}

int main() {
    // Initialize ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    timeout(700); // Set timeout for non-blocking getch

    // Start colors
    start_color();

    // Define color pairs for Tetriminos
    init_pair(SHAPE_I, COLOR_CYAN, COLOR_BLACK);
    init_pair(SHAPE_J, COLOR_BLUE, COLOR_BLACK);
    init_pair(SHAPE_L, COLOR_WHITE, COLOR_BLACK);
    init_pair(SHAPE_O, COLOR_YELLOW, COLOR_BLACK);
    init_pair(SHAPE_S, COLOR_GREEN, COLOR_BLACK);
    init_pair(SHAPE_T, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(SHAPE_Z, COLOR_RED, COLOR_BLACK);

    // Main game loop
    while (true) {
        // Initialize game
        init_game();

        // Game loop
        while (!game_state.game_over) {
            clear();
            display_board();
            handle_input();
            update_game_state();
            refresh(); // Ensure the screen is updated
        }

        // Game over sequence
        game_over();

        // Ask the user if they want to play again
        int ch;
        while (true) {
            mvprintw(TETRIS_BOARD_HEIGHT + 3, 0, "Play again? (y/n): ");
            refresh();
            ch = getch();
            if (ch == 'y' || ch == 'Y') {
                // Restart the game
                break;
            } else if (ch == 'n' || ch == 'N') {
                // Exit the game
                goto exit_game;
            }
        }
    }

exit_game:
    // Clean up and exit ncurses
    endwin();
    return 0;
}