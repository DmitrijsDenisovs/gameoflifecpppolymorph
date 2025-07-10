#pragma once
#ifndef IINPUTCONTROLLER_H
#define IINPUTCONTROLLER_H

#include "ICommand.h"
#include <type_traits>

namespace Interfaces {
	//represents interface for classes that handle input which is transmitted through ICommand classes
	template <typename TCommand>
	class IInputController {
		static_assert(std::is_base_of<ICommand, TCommand>::value);
	public:
		virtual ~IInputController() = default;
		virtual const TCommand getCommand() = 0;
	};
}

#endif