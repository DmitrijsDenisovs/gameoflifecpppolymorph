#pragma once
#ifndef IOUTPUTCONTROLLER_H
#define IOUTPUTCONTROLLER_H

#include <memory>

namespace Interfaces {
	//represents interfaces of classes controlling TState game state display
	template<typename TState>
	class IOutputController {
	public:
		virtual ~IOutputController() = default;

		virtual void displayOutput(const std::shared_ptr<TState> state) = 0;
	};
}

#endif