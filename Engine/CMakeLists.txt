cmake_minimum_required(VERSION 4.4)

project(Engine C CXX)

set(SOURCE_FILES
    src/app/app_builder.hpp
    src/app/application.cpp
    src/app/application.hpp
    src/app/keys.hpp
    src/app/keys.cpp
    src/app/timer.cpp
    src/app/timer.hpp
    src/app/window_events.cpp
    src/app/window_events.hpp
    src/app/window.cpp
    src/app/window.hpp
    
    src/core/defines.hpp
    

    src/ecs/plugin.hpp
    src/ecs/schedules.hpp
    src/ecs/system_scheduler.hpp
    src/ecs/system_scheduler.cpp
    src/ecs/world.cpp
    src/ecs/world.hpp


    src/ecs/components/physics.hpp
    src/ecs/components/player.hpp
    src/ecs/components/transform.hpp
    src/ecs/components/renderable.hpp
    src/ecs/components/sprite.hpp
    src/ecs/components/sprite.cpp
    
    src/ecs/events/base_event.hpp
    src/ecs/events/key_events.hpp
    
    src/ecs/scheduling/callable_traits.hpp
    
    src/ecs/systems/physics_plugin.hpp
    src/ecs/systems/physics_plugin.cpp
    src/ecs/systems/render_plugin.hpp
    src/ecs/systems/render_plugin.cpp
    

    src/error/assertions.hpp
    
    src/math/color.hpp
    src/math/color.cpp
    src/math/conversions.hpp
    src/math/conversions.cpp
    src/math/math_defs.hpp
    src/math/math.hpp
    src/math/math.cpp
    src/math/rect2.hpp
    src/math/rect2.cpp
    src/math/vector2.hpp
    src/math/vector2.cpp
    
    src/scenes/scene_stager.hpp
    src/scenes/scene_stager.cpp
    src/scenes/scene.hpp
    src/scenes/scene.cpp

    src/Log.hpp
    src/Log.cpp
)

message(CHECK_START "Operating System Check")
if (WIN32)
    message(CHECK_PASS "Compiling for Windows!!")
    set(OS_LIBDIR "windows")
elseif(APPLE)
    message(CHECK_FAIL "MacOS not supported!!!")
elseif(UNIX)
    message(CHECK_PASS "Compiling for Linux!!")
    set(OS_LIBDIR "linux")
else()
    message(CHECK_FAIL "Unknown OS!!!")
endif()

add_library(Engine STATIC
    ${SOURCE_FILES}
)

target_include_directories(Engine PUBLIC vendor/include src)

target_link_directories(Engine PUBLIC "vendor/lib/${OS_LIBDIR}/x64/")
target_link_libraries(Engine PUBLIC spdlog SDL3)

