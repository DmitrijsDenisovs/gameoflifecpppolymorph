#pragma once
#ifndef CELLSTATE_H
#define CELLSTATE_H
namespace Game
{
	//represents possible states of a cell in Conway's game of life, open to extension
	enum class CellState
	{
		POPULATED = 1,
		UNPOPULATED = 0
	};
}
#endif