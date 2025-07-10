add_library(InterfacesLib INTERFACE "ICommand.h" "CommandType.h" "IGameController.h" "IGameState.h" "IInputController.h" "IOutputController.h")

target_include_directories(InterfacesLib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
