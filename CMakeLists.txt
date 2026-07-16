cmake_minimum_required(VERSION 3.10)

project(DashboardTUI VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(ftxui REQUIRED)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(dashboard ${SOURCES})

target_link_libraries(dashboard PRIVATE ftxui::screen ftxui::dom ftxui::component)
