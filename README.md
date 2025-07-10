#gameoflifecpppolymorph

Implementation of Conway's game of life with Cpp in OOP paradigm.

Main logic is handled by GameOfLifeController class which uses IInputController and IOutputController classes to handle IO appropriately.

Keyboard input and CLI output is OS dependent, built for Windows.

Commands (executed as soon as command string is similar):

1. pause - pause/unpause
2. quit - stop execution
3. switch x y - switch state of cell at x y

Project built using these commands:

`mkdir build && cd build`

`cmake .. -G "Visual Studio 17 2022"`

`cmake --build . --config Debug`

`.\Debug\GameOfLifeCpp.exe`
