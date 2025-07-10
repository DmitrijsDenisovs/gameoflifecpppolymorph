#pragma once
#ifndef IGAMECONTROLLER_H
#define IGAMECONTROLLER_H

#include <memory>
#include <type_traits>
#include "ICommand.h"

namespace Interfaces {
	//represents the interface for main handler of games
	template<typename TCommand, typename TState>
	class IGameController {
		static_assert(std::is_base_of<ICommand, TCommand>::value);
	public:
		virtual void run() = 0;
		virtual ~IGameController() = default;
	};

}

#endif