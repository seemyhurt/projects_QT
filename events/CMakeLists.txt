cmake_minimum_required(VERSION 3.14)

project(base_qt LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(change_a_to_z)
add_subdirectory(event_filter)
add_subdirectory(mouse_observer)
add_subdirectory(resize_event)
add_subdirectory(simul_press_key)
