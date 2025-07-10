#pragma once
#ifndef CELL_H
#define CELL_H

#include <concepts>
#include "CellState.h"

namespace Game {
	//wrapper of Cell data for some data transmission between entities
	template <std::integral T>
	class Cell {
	public:
		T x;
		T y;
		CellState state;
	};
}

#endif