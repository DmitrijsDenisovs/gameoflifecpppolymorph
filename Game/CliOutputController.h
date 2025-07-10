#pragma once
#ifndef CLIOUTPUTCONTROLLER_H
#define CLIOUTPUTCONTROLLER_H

#include "IOutputController.h"
#include "GameOfLifeState.h"
#include <iostream>
#include <windows.h>

namespace Game {
	//handles output of Conway's game of life state output to cli, Windows OS dependent
	template<std::size_t THeight, std::size_t TWidth>
	class CliOutputController : public Interfaces::IOutputController<GameOfLifeState<THeight, TWidth>> {
	private:
        char populatedSymbol;
        char unpopulatedSymbol;

	public:

		void displayOutput(const std::shared_ptr<GameOfLifeState<THeight, TWidth>>  state) override;

        CliOutputController() : populatedSymbol('#'), unpopulatedSymbol('.') {}

        CliOutputController(char populated, char unpopulated) : populatedSymbol(populated), unpopulatedSymbol(unpopulated) {}

        CliOutputController(const CliOutputController& other) = default;

        CliOutputController(CliOutputController&& other) noexcept = default;

        CliOutputController& operator=(const CliOutputController& other) = default;
        CliOutputController& operator=(CliOutputController&& other) noexcept = default;
	};
}

using Game::CliOutputController;
template<std::size_t THeight, std::size_t TWidth>
void CliOutputController<THeight, TWidth>::displayOutput(const std::shared_ptr<GameOfLifeState<THeight, TWidth>> state) {

    //clear terminal, ChatGPT generated
    using namespace std;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE) return;

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) return;

    const DWORD consoleSize = csbi.dwSize.X * csbi.dwSize.Y;
    DWORD charsWritten;

    // Fill screen with spaces
    FillConsoleOutputCharacter(hConsole, ' ', consoleSize, COORD{ 0, 0 }, &charsWritten);
    // Reset attributes
    FillConsoleOutputAttribute(hConsole, csbi.wAttributes, consoleSize, COORD{ 0, 0 }, &charsWritten);
    // Move cursor to top-left
    SetConsoleCursorPosition(hConsole, COORD{ 0, 0 });


    std::cout << "Iteration:  " << state->iteration << std::endl;

    std::cout << "Current input:  " << state->currentInput << std::endl;

    for (int i = 0; i < THeight; ++i) {
        for (int j = 0; j < TWidth; ++j) {
            if (state->board(i, j) == Game::CellState::POPULATED)
            {
                std::cout << this->populatedSymbol;
            }

            if (state->board(i, j) == Game::CellState::UNPOPULATED)
            {
                std::cout << this->unpopulatedSymbol;
            }
        }
        std::cout << std::endl;
    }
}

#endif