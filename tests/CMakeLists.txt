cmake_minimum_required(VERSION 4.4)

project(UnitTests C CXX)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(UnitTests math_tests.cpp vector2_tests.cpp event_tests.cpp)

target_link_libraries(UnitTests PRIVATE Engine GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(UnitTests)
