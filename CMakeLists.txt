cmake_minimum_required(VERSION 3.10)

project(D-SH VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(GNUInstallDirs)

find_package(ftxui REQUIRED)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(d-sh ${SOURCES})

target_link_libraries(d-sh PRIVATE ftxui::screen ftxui::dom ftxui::component)

install(TARGETS d-sh
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# install(DIRECTORY assets DESTINATION ${CMAKE_INSTALL_DATADIR}/dsh)
