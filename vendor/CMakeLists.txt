cmake_minimum_required(VERSION 3.16)

macro(AddExternalProject MACRO_PROJECT_NAME VERSION GIT_REPOSITORY GIT_TAG)

    message(STATUS "Trying to configure ${MACRO_PROJECT_NAME} dependency")
    # find_package(${MACRO_PROJECT_NAME} ${VERSION} QUIET)

    if (NOT ${MACRO_PROJECT_NAME}_FOUND)
        message(STATUS "Could not find ${MACRO_PROJECT_NAME}, trying to download...")
        FetchContent_Declare(
                ${MACRO_PROJECT_NAME}
                GIT_REPOSITORY ${GIT_REPOSITORY}
                GIT_TAG        ${GIT_TAG}
        )

        FetchContent_MakeAvailable(${MACRO_PROJECT_NAME})
    else()
        message(STATUS "System provided ${MACRO_PROJECT_NAME} has been found")
    endif()

    message(STATUS "Configured ${MACRO_PROJECT_NAME}")
endmacro()

include(FetchContent)

AddExternalProject(cli11 2.3.2 https://github.com/CLIUtils/CLI11 v2.3.1)
AddExternalProject(tomlplusplus 3.3.0 https://github.com/marzer/tomlplusplus v3.3.0)
AddExternalProject(fmt 10.0.0 https://github.com/fmtlib/fmt 10.0.0)
