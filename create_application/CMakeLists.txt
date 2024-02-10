cmake_minimum_required(VERSION 3.14)

project(base_qt LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(dialog)
add_subdirectory(drag_and_drop)
add_subdirectory(save_settings)
add_subdirectory(screen_short)
add_subdirectory(simple_notepad)
add_subdirectory(splash_screen)
add_subdirectory(status_bar)
add_subdirectory(system_tray)