add_library(GameLib "GameController.h" "GameOfLifeManager.h" "Cell.h" "CellState.h" "Command.h" "GameOfLifeController.h" "GameOfLifeState.h" "GameController.cpp" "GameOfLifeManager.cpp" "KeyboardInputController.h" "KeyboardInputController.cpp" "CliOutputController.h")

target_include_directories(GameLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(GameLib PUBLIC ConfigLib)

target_link_libraries(GameLib PUBLIC UtilityLib)

target_link_libraries(GameLib PUBLIC InterfacesLib)

