#pragma once
#ifndef ICOMMAND_H
#define ICOMMAND_H

#include "CommandType.h"

namespace Interfaces {
	//interface for Command classes
	class ICommand {
	public:
		virtual const CommandType getCommandType() = 0;
		virtual ~ICommand() = default;
	};
}

#endif
