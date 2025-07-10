#pragma once
#ifndef GAMEOFLIFEMANAGER_H
#define GAMEOFLIFEMANAGER_H

#include "GameOfLifeState.h"
#include "CellState.h"
#include <memory>
#include <unordered_set>
#include <algorithm>

namespace Game {
	//static class to handle board updates
	template<std::size_t THeight, std::size_t TWidth, unsigned int TNeighborhoodRange, unsigned int TUnderpopulationThreshold, unsigned int TOverpopulationThreshold, unsigned int TReproductionThreshold>
	class GameOfLifeManager {
	public:
			static std::shared_ptr<GameOfLifeState<THeight, TWidth>> update(std::shared_ptr<GameOfLifeState<THeight, TWidth>> state);
	};
}

using Game::GameOfLifeState;
using Game::GameOfLifeManager;

template<std::size_t THeight, std::size_t TWidth, unsigned int TNeighborhoodRange, unsigned int TUnderpopulationThreshold, unsigned int TOverpopulationThreshold, unsigned int TReproductionThreshold>
std::shared_ptr<GameOfLifeState<THeight, TWidth>> GameOfLifeManager<THeight, TWidth, TNeighborhoodRange, TUnderpopulationThreshold, TOverpopulationThreshold, TReproductionThreshold>::
	update(std::shared_ptr<GameOfLifeState<THeight, TWidth>> state) {

	std::unordered_set<unsigned int> cellsToPopulate{};
	std::unordered_set<unsigned int> cellsToUnpopulate{};

	//iterating over every cell, might be optimized by iterating over live cells and their neighbors
	for (int i = 0; i < state->board.size(); ++i)
	{
		const auto neighbors = state->board.getNeighbors(i, 1);
		const unsigned int liveCount = std::count_if(neighbors.begin(), neighbors.end(), [state](int i) { return state->board[i] == CellState::POPULATED; });
		const unsigned int deadCount = std::count_if(neighbors.begin(), neighbors.end(), [state](int i) { return state->board[i] == CellState::UNPOPULATED; });

		if (state->board[i] == CellState::POPULATED)
		{
			if (liveCount < TUnderpopulationThreshold || liveCount > TOverpopulationThreshold)
			{
				cellsToUnpopulate.insert(i);
			}
		}

		if (state->board[i] == CellState::UNPOPULATED)
		{
			if (liveCount == TReproductionThreshold)
			{
				cellsToPopulate.insert(i);
			}
		}
	}

	for (const auto& index : cellsToPopulate)
	{
		state->board[index] = CellState::POPULATED;
	}

	for (const auto& index : cellsToUnpopulate)
	{
		state->board[index] = CellState::UNPOPULATED;
	}

	return state;
}

#endif