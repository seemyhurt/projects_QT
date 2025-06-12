cmake_minimum_required(VERSION 3.16)

project(affine-transform VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets)

set(PROJECT_HEADERS
    mainwidget.h
    pentagonwidget.h
)

set(PROJECT_SOURCES
    main.cpp
    mainwidget.cpp
    pentagonwidget.cpp
)

add_executable(${PROJECT_NAME}
    ${PROJECT_HEADERS}
    ${PROJECT_SOURCES}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt5::Widgets
)

target_compile_definitions(${PROJECT_NAME} PRIVATE
    _USE_MATH_DEFINES
)
