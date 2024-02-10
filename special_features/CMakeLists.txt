cmake_minimum_required(VERSION 3.14)

project(base_qt LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(blink_label)
add_subdirectory(client)
add_subdirectory(downloader)
add_subdirectory(file_finder)
add_subdirectory(read_xml)
add_subdirectory(server)
add_subdirectory(shell)
add_subdirectory(thread_event)
add_subdirectory(viewer)
add_subdirectory(web_browser)
add_subdirectory(write_xml)
