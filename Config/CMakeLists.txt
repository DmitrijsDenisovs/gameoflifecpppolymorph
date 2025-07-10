add_library(ConfigLib INTERFACE "Config.h")

target_sources(ConfigLib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_include_directories(ConfigLib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
