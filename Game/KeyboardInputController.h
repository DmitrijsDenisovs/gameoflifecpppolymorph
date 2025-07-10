#pragma once
#ifndef KEYBOARDINPUTCONTROLLER_H
#define KEYBOARDINPUTCONTROLLER_H

#include "IInputController.h"
#include "Command.h"
#include <string>
#include <thread>
#include <atomic>
#include <mutex>

namespace Game {
	//controlls comand input using keyboard, Windows OS dependent, keyboard processing works on its own thread
	class KeyboardInputController : public Interfaces::IInputController<Command> {
	private:
		std::thread listenerThread;
		std::string currentCommandString = "";
		std::mutex commandStringMutex;
		std::atomic<bool> running;

	public:
		KeyboardInputController();
		~KeyboardInputController();
		const Command getCommand() override;

		KeyboardInputController(const KeyboardInputController&) = delete;
		KeyboardInputController& operator=(const KeyboardInputController&) = delete;

		KeyboardInputController(KeyboardInputController&&) noexcept = default;
		KeyboardInputController& operator=(KeyboardInputController&&) noexcept = default;

		void listen();
	};
}

#endif