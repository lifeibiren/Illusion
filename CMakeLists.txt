cmake_minimum_required(VERSION 3.0)

project(Illusion)

find_package(Freetype REQUIRED)
include_directories(${FREETYPE_INCLUDE_DIRS})

add_compile_options(-std=c++11)
include_directories(.)
file(GLOB SRC_FILE *.cpp *.cc)
add_executable(${PROJECT_NAME} ${SRC_FILE})
target_link_libraries(${PROJECT_NAME} glut GL GLU )
target_link_libraries(${PROJECT_NAME} ${FREETYPE_LIBRARIES})
