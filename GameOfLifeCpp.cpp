// entry point

#include <iostream>
#include <memory>

#include "Config.h"

#include "GameOfLifeState.h"
#include "CellState.h"
#include "KeyboardInputController.h"
#include "CliOutputController.h"
#include "GameOfLifeController.h"

int main()
{
	constexpr int i = 16;
	Game::GameOfLifeState<i, i> state;
	state.board(2, 0) = Game::CellState::POPULATED;
	state.board(0, 1) = Game::CellState::POPULATED;
	state.board(2, 1) = Game::CellState::POPULATED;
	state.board(1, 2) = Game::CellState::POPULATED;
	state.board(2, 2) = Game::CellState::POPULATED;

	auto state_ptr = std::make_shared<Game::GameOfLifeState<i, i>>(state);


	auto input_ptr = std::make_shared<Game::KeyboardInputController>();
	auto output_ptr = std::make_shared<Game::CliOutputController<i, i>>(Config::POPULATED_SYMBOL, Config::UNPOPULATED_SYMBOL);

	Game::GameOfLifeController<i, i> controller{ input_ptr, output_ptr, state_ptr };
	input_ptr.reset();
	output_ptr.reset();
	controller.run();

	return 0;
}
