#pragma once

#ifndef GAMEOFLIFECONTROLLER_H
#define GAMEOFLIFECONTROLLER_H

#include <memory>
#include "GameOfLifeState.h"
#include "GameOfLifeManager.h"
#include "GameController.h"
#include "Command.h"
#include "Config.h"
#include <chrono>
#include <thread>
#include <regex>

namespace Game {
	//concrete class to controll Game of Life logic
	template<std::size_t THeight, std::size_t TWidth>
	class GameOfLifeController : public GameController<Command, GameOfLifeState<THeight, TWidth>> {

	public:
		void handleIterationEnding() override;
		std::shared_ptr<GameOfLifeState<THeight, TWidth>> update(const Command& command) override;

		GameOfLifeController() = default;

		GameOfLifeController(
			std::shared_ptr<IInputController<Command>> input,
			std::shared_ptr<IOutputController<GameOfLifeState<THeight, TWidth>>> output,
			std::shared_ptr<GameOfLifeState<THeight, TWidth>> initialState) : GameController<Command, GameOfLifeState<THeight, TWidth>>(input, output, initialState) {}

		GameOfLifeController(GameOfLifeController&& other) noexcept = default;

		GameOfLifeController(const GameOfLifeController& other) = default;

		GameOfLifeController& operator=(const GameOfLifeController& other) = default;
		GameOfLifeController& operator=(GameOfLifeController&& other) noexcept = default;


		~GameOfLifeController() override = default;
	};
}

template<std::size_t THeight, std::size_t TWidth>
void Game::GameOfLifeController<THeight, TWidth>::handleIterationEnding() {

	if (this->running)
	{
		this->state = Game::GameOfLifeManager<THeight, TWidth, Config::NEIGHBORHOOD_RANGE, Config::UNDERPOPULATION_THRESHOLD, Config::OVERPOPULATION_THRESHOLD, Config::REPRPODUCTION_THRESHOLD>::update(this->state);
		this->state->iteration++;
	}

	std::this_thread::sleep_for(std::chrono::milliseconds(Config::FRAME_UPDATE_MS));
}

template<std::size_t THeight, std::size_t TWidth>
std::shared_ptr<GameOfLifeState<THeight, TWidth>> Game::GameOfLifeController<THeight, TWidth>::update(const Game::Command& command) {
	//parse command properly
	std::regex switchRegex(R"(^(switch)\s+(\d+)\s+(\d+)$)");
	std::smatch match;
	std::string commandString = command.getCommandString();
	if (std::regex_match(commandString, match, switchRegex))
	{
		int x = std::stoi(match[2]);
		int y = std::stoi(match[3]);

		if (this->state->board(x, y) == Game::CellState::POPULATED)
		{
			this->state->board(x, y) = Game::CellState::UNPOPULATED;
		} else if (this->state->board(x, y) == Game::CellState::UNPOPULATED)
		{
			this->state->board(x, y) = Game::CellState::POPULATED;
		}
	}

	this->state->currentInput = commandString;

	return this->state;
}

#endif