cmake_minimum_required(VERSION 3.21)
project(computerAdmin)
set(CMAKE_CXX_STANDARD 14)
file(GLOB SRC_FILES
        "${PROJECT_SOURCE_DIR}/src/*.h"
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
        )
add_executable(${CMAKE_PROJECT_NAME} ${SRC_FILES})
add_custom_command(
        TARGET ${CMAKE_PROJECT_NAME}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${PROJECT_SOURCE_DIR}/resources"
        "$<TARGET_FILE_DIR:${CMAKE_PROJECT_NAME}>"
)

