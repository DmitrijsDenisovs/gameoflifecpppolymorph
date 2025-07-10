#include "GameController.h"
#include "IOutputController.h"
#include "IInputController.h"
#include "ICommand.h"
#include "CommandType.h"
//
//using Interfaces::ICommand;
//using Game::GameController;
//using Interfaces::IInputController;
//using Interfaces::IOutputController;
//using Interfaces::CommandType;
//
//template<typename TCommand, typename TState>
//void GameController<TCommand, TState>::run() {
//	this->running = true;
//
//	while (!this->finished())
//	{
//		TCommand command = this->inputController->getCommand();
//
//		if (command.getCommandType() != CommandType::EMPTY) {
//
//			if (command.getCommandType() == CommandType::QUIT)
//			{
//				this->running = false;
//				return;
//			}
//
//			this->state = this->update(command);
//
//			this->outputController->displayOutput(this->state);
//		}
//
//		this->handleIterationEnding();
//	}
//};
//
//template<typename TCommand, typename TState>
//static std::shared_ptr<const GameController<TCommand, TState>>
//	GameController<TCommand, TState>::build
//		(std::shared_ptr<IInputController<TCommand>> in, std::shared_ptr<IOutputController<TState>> out, TState startState) {
//	return std::make_shared<GameController<TCommand, TState>>(in, out, startState);
//}


