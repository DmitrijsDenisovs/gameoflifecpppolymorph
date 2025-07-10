gameoflifecpppolymorph
Implementation of Conway's game of life with Cpp in OOP paradigm.

Main logic is handled by GameOfLifeController class which uses IInputController and IOutputController classes to handle IO appropriately.

Keyboard input and CLI output is OS dependent, built for Windows.

Commands (executed as soon as command string is similar):

pause - pause/unpause
quit - stop execution
switch x y - switch state of cell at x y
