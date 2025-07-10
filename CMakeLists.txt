cmake_minimum_required(VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project(GameOfLifeCpp)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(Config)
add_subdirectory(Utility)
add_subdirectory(Game)
add_subdirectory(Interfaces)


add_executable(GameOfLifeCpp GameOfLifeCpp.cpp)

target_link_libraries(GameOfLifeCpp PRIVATE ConfigLib)
target_link_libraries(GameOfLifeCpp PRIVATE UtilityLib)
target_link_libraries(GameOfLifeCpp PRIVATE InterfacesLib)
target_link_libraries(GameOfLifeCpp PRIVATE GameLib)

