#pragma once

#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <memory>
#include "IInputController.h"
#include "IOutputController.h"
#include "IGameController.h"
#include "ICommand.h"
#include <type_traits>

namespace Game {
	//abstract class with Input and Output controllers, main logic described in run()
	template <typename TCommand, typename TState>
	class GameController : public Interfaces::IGameController<TCommand, TState> {
		static_assert(std::is_base_of<Interfaces::ICommand, TCommand>::value);
	private:
		std::shared_ptr<Interfaces::IInputController<TCommand>> inputController;
		std::shared_ptr<Interfaces::IOutputController<TState>> outputController;

	protected:
		std::shared_ptr<TState> state;

		bool running = false;
		bool finished = false;

		GameController(std::shared_ptr<Interfaces::IInputController<TCommand>> in,
			std::shared_ptr<Interfaces::IOutputController<TState>> out, std::shared_ptr<TState> startState)
			: inputController(std::move(in)), outputController(std::move(out)), state(startState) {
		};

	public:
		void run() override;

		virtual void handleIterationEnding() = 0;
		virtual std::shared_ptr<TState> update(const TCommand& command) = 0;

		virtual ~GameController() = default;
	};
}


using Interfaces::ICommand;
using Game::GameController;
using Interfaces::IInputController;
using Interfaces::IOutputController;
using Interfaces::CommandType;

template<typename TCommand, typename TState>
void GameController<TCommand, TState>::run() {
	this->running = true;
	this->finished = false;

	while (!this->finished)
	{
		TCommand command = this->inputController->getCommand();

		if (command.getCommandType() != CommandType::EMPTY) {

			if (command.getCommandType() == CommandType::QUIT)
			{
				this->finished = true;

				this->inputController.reset();
				this->outputController.reset();

				return;
			}

			if (command.getCommandType() == CommandType::PAUSE_UNPAUSE)
			{
				this->running = !this->running;
			}
			else {
				this->update(command);
			}
		}

		this->outputController->displayOutput(this->state);

		this->handleIterationEnding();
	}

	this->inputController.reset();
	this->outputController.reset();
};
#endif