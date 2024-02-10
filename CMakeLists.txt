cmake_minimum_required(VERSION 3.14)

project(qt_book_examples LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(base_qt)
add_subdirectory(create_application)
add_subdirectory(events)
add_subdirectory(graph)
add_subdirectory(managment_elements)
add_subdirectory(sound_generator)
add_subdirectory(threads)
add_subdirectory(special_features)
