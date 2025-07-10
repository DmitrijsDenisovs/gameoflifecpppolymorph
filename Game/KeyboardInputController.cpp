#include "KeyboardInputController.h"
#include "Command.h"
#include "CommandType.h"
#include <string>
#include <thread>
#include <conio.h> 
#include <mutex>
#include <cctype>

using Game::KeyboardInputController;
using Game::Command;
using Interfaces::CommandType;

KeyboardInputController::KeyboardInputController()
{
    this->running = true;
    this->listenerThread = std::thread(&KeyboardInputController::listen, this);
}

const Command KeyboardInputController::getCommand()
{
    std::lock_guard<std::mutex> lock(this->commandStringMutex);

    CommandType type = CommandType::ACTION;

    std::string send = this->currentCommandString;

    if (this->currentCommandString == "pause")
    {
        type = CommandType::PAUSE_UNPAUSE;
        this->currentCommandString = "";
    }

    if (this->currentCommandString == "quit")
    {
        type = CommandType::QUIT;
        this->currentCommandString = "";
    }

    Command cmd{ type, send };
    return cmd;
}

void KeyboardInputController::listen()
{
    while (this->running.load()) {
        //check key press
        if (_kbhit()) {
            int ch = _getch();
            // skip special keys
            if (ch == 0 || ch == 224) {
                _getch();
                continue;
            }

            if (ch == 8) {
                std::lock_guard<std::mutex> lock(this->commandStringMutex);
                if (this->currentCommandString.size() > 0)
                {
                    this->currentCommandString.pop_back();
                }
            }

            if (std::isprint(ch)) {
                std::lock_guard<std::mutex> lock(this->commandStringMutex);
                this->currentCommandString += ch;
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(20)); 
    }
}

KeyboardInputController::~KeyboardInputController() {
    this->running = false;
    if (this->listenerThread.joinable()) {
        listenerThread.join();
    }
}
