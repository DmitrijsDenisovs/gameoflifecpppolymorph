#pragma once
#ifndef GAMEOFLIFESTATE_H
#define GAMEOFLIFESTATE_H

#include <concepts>
#include "CellState.h"
#include "Matrix.h"
#include <string>

namespace Game {
	//represents variable entities that represent the game and are displayed
	template<std::size_t THeight, std::size_t TWidth>
	class GameOfLifeState {
	public:
		Utility::Matrix<CellState, THeight, TWidth> board;
		unsigned int iteration = 0;
		std::string currentInput;
	};
}

#endif