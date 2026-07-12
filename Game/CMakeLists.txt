cmake_minimum_required(VERSION 4.4)

project(Game C CXX)

set(SOURCE_FILES
    src/game_settings.hpp
    src/main.cpp
    src/TestScene.hpp
    src/TestScene.cpp

    src/components/parallax.hpp
    src/components/pipe.hpp

    src/events/spawn_pipe_event.hpp

    src/systems/parallax_system.hpp
    src/systems/parallax_system.cpp
    src/systems/pipe_system.hpp
    src/systems/pipe_system.cpp
    src/systems/player_system.hpp
    src/systems/player_system.cpp
)


add_executable(Game ${SOURCE_FILES})

target_include_directories(Game PRIVATE ${PROJECT_SOURCE_DIR}/src)

target_link_libraries(Game Engine)

add_custom_command(
    TARGET Game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different 
        "${PROJECT_SOURCE_DIR}/assets" 
        "$<TARGET_FILE_DIR:Game>/assets"
    COMMENT "Copying assets/ contents to build directory..."
)