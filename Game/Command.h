#pragma once
#ifndef COMMAND_H
#define COMMAND_H

#include "ICommand.h"
#include "CommandType.h"
#include <string>

namespace Game
{
	//wraps command string and type together, implements ICommand concept (interface)
	class Command : public Interfaces::ICommand {
	private:
		Interfaces::CommandType type;
		std::string commandString;
	public:
		inline const Interfaces::CommandType getCommandType() override { return this->type; }
		inline const std::string getCommandString() const { return this->commandString; }

        Command() = default;

        Command(Interfaces::CommandType type, std::string str) : type(type), commandString(std::move(str)) {}

        Command(const Command& other) = default;

        Command(Command&& other) noexcept = default;

        Command& operator=(const Command& other) = default;

        ~Command() override = default;
	};

}

#endif