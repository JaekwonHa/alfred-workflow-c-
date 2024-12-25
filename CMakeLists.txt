cmake_minimum_required(VERSION 3.21)
project(alfred-workflow-cpp VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/modules" ${CMAKE_MODULE_PATH})
set(SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/src)

find_package(CompilerFlags REQUIRED MODULE)
find_package(PublishPaths REQUIRED MODULE)

find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})


add_subdirectory(src)

enable_testing()
add_subdirectory(test)
