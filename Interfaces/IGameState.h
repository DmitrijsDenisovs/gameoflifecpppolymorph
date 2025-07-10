#pragma once
#ifndef IGAMESTATE_H
#define IGAMESTATE_H

namespace Interfaces {
	//represents the game state (entity that changes after interactions and is displayed)
	template <typename TState>
	class IGameState {
	public:
		virtual const TState update() = 0;
		virtual const TState getState() = 0;
	};
}
#endif