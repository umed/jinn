cmake_minimum_required(VERSION 3.16)

set(TARGET_NAME jinn)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS *.cpp)

add_executable(${TARGET_NAME} ${SOURCES})

target_include_directories(${TARGET_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(${TARGET_NAME}
    CLI11::CLI11
    tomlplusplus::tomlplusplus
    fmt::fmt
)
